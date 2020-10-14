// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2020, Intel Corporation */

/* [I want to show how to implement simple.. ]
 * This is the example of using pmemkv-java binding in simlpe, real life application.
 * It loads png files from specified directory, stores it into pmemkv, and display to the screen
 * As persistent pmemkv  engine was used, it's possible to load  pictures ones, and
 * read it from persistent storage  in next runs of application.
 */
import java.awt.*;
import java.awt.image.BufferedImage;
import javax.swing.JFrame;
import java.io.File;
import javax.imageio.ImageIO;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

import io.pmem.pmemkv.Database;
import io.pmem.pmemkv.Converter;

import java.nio.ByteBuffer;
import java.util.concurrent.atomic.AtomicInteger;


class ByteBufferBackedInputStream extends InputStream {

	ByteBuffer buff;

	public ByteBufferBackedInputStream(ByteBuffer buff) {
		this.buff = buff;
		this.buff.rewind();
	}

	public int read() {
		throw new UnsupportedOperationException();
	}

	public int read(byte[] bytes, int off, int len)
			throws IOException {
		if (!buff.hasRemaining()) {
			return -1;
		}
		len = Math.min(len, buff.remaining());
		buff.get(bytes, off, len);
		return len;
	}
}

class StringConverter implements Converter<String> {
	public ByteBuffer toByteBuffer(String entry) {
		return ByteBuffer.wrap(entry.getBytes());
	}

	public String fromByteBuffer(ByteBuffer entry) {
		byte[] bytes;
		bytes = new byte[entry.capacity()];
		entry.get(bytes);
		return new String(bytes);
	}
}

/*
 * As pmemkv-java binding is java wrapper on c++ library, it internally relays on java natinve interface, so it allows to store only ByteBuffer objects.
 *  As it's not very convinient to operate on ByteBuffers inside high level application, additional layer of converters was introduced.
 *  It's posible to store, in the pmemkv, objects of any (even user defined) type, as long as appropriate converter class is delivered.
 *  Such class needs to implement Converter jeneric interface. Such class have to implement just two methods:
 *  # toByteBuffer() - which provides method to convert (serialize) objects to BYteBuffer
 *  # fromByteBuffer() - which provides method to conver objects back.
 *
 */

class ImageConverter implements Converter<BufferedImage> {
	public ByteBuffer toByteBuffer(BufferedImage entry) {
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		try {
			ImageIO.write(entry, "png", out);
		} catch (IOException e) {
			return null;
		}
		return ByteBuffer.wrap(out.toByteArray());
	}

	public BufferedImage fromByteBuffer(ByteBuffer entry) {
		BufferedImage out = null;
		try {
			out = ImageIO.read(new ByteBufferBackedInputStream(entry));
		} catch (IOException e) {
			return null;
		}
		return out;
	}
}

public class PicturesExample extends Canvas {

	private Database<String, BufferedImage> db;
	private String engine = "cmap";

/*
 * Database is generic class, which needs to be "parametrized" by key and value type.
 * Database constructor implements Builder pattern. Parameters, which are needed to be set during Database object creation highly depends on choosen pmemkv  engine. [link to pmemkv readme];
 * however setValueConverter() and setKeyConverter() always needs to be called, and it's types has to corespond with Database key and value types.
 * Choice of engine is probably most important part of designing application, which uses pmemkv.
 */
	public PicturesExample(String Path, int size) {
		System.out.println("Creating new database in path: " + Path + " with size: " + size);
		db = new Database.Builder<String, BufferedImage>(engine)
				.setSize(size)
				.setPath(Path)
				.setKeyConverter(new StringConverter())
				.setValueConverter(new ImageConverter())
				.setForceCreate(true)
				.build();
	}
	public PicturesExample(String Path) {
		System.out.println("Using already existing database: " + Path);
		db = new Database.Builder<String, BufferedImage>(engine)
				.setPath(Path)
				.setKeyConverter(new StringConverter())
				.setValueConverter(new ImageConverter())
				.build();
	}

	public void putAllPicturesFromDirectory(String dir_path) {
		File[] images = new File(dir_path).listFiles((dir, name) -> name.endsWith(".png"));
		for (File image : images) {
			System.out.println(image.getAbsolutePath());

			BufferedImage image_buffer = null;
			try {
				image_buffer = ImageIO.read(image);
			} catch (IOException e) {
				System.exit(1);
			}
/*
 * To store any object in pmemkv database, user should just call put ...
 * */		
			db.put(image.getName(), image_buffer);
		}
	}

	public void paint(Graphics g) {
		System.out.println("Draw images from pmemkv database");
		AtomicInteger yPosition = new AtomicInteger(0);
/* Operating on stored data
 * There is group of get*() methods, which gets lambda expressions, and can operate directly on data stored in
 * persistent memory, without copying. 
 * */
		db.getAll((k, v) -> {
			System.out.println("\tDraw" + k);
			Graphics2D g2 = (Graphics2D) g;
			g.drawImage(v, 0, yPosition.getAndAdd(v.getHeight()), null);
		});
	}

	public static void main(String[] args) {
		String input_dir = System.getenv("InputDir");
		String pmemkvPath = System.getenv("PmemkvPath");
		String pmemkvSize = System.getenv("PmemkvSize");

		System.out.println("Parameters:");
		System.out.println("InputDir" + input_dir);
		System.out.println("Path: " + pmemkvPath);
		System.out.println("Size: " + pmemkvSize);

		PicturesExample m = null;
		if (pmemkvSize != null && pmemkvPath != null) {
			try {
				m = new PicturesExample(pmemkvPath, Integer.parseInt(pmemkvSize));
			} catch (NumberFormatException e) {
				System.out.println("Wrong size: " + e);
				System.exit(1);
			}
		} else if (pmemkvPath != null) {
			m = new PicturesExample(pmemkvPath);
		} else {
			System.out.println("Provide at least PmemkvPath parameter. See examples' README for usage");
			System.exit(0);
		}

		if (input_dir != null) {
			System.out.println("Loading files from " + input_dir + " to pmemkv database");
			m.putAllPicturesFromDirectory(input_dir);
		}
		JFrame f = new JFrame();
		f.add(m);
		f.setSize(512, 512);
		f.setVisible(true);
	}
}

/* What's next?
 * 
 * # As pmemkv-java 1.0 API is compatibile with pmemkv 1.0 API, in upcomming releases
 *  we are going to imlement most important features avialable in next pmemkv releases.
 * # predefined converters for most comon types (patches are welcomed)
 * */

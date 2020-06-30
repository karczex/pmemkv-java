/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class io_pmem_pmemkv_Database */

#ifndef _Included_io_pmem_pmemkv_Database
#define _Included_io_pmem_pmemkv_Database
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_start
 * Signature: (Ljava/lang/String;J)J
 */
JNIEXPORT jlong JNICALL Java_io_pmem_pmemkv_Database_database_1start
  (JNIEnv *, jobject, jstring, jlong);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_stop
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1stop
  (JNIEnv *, jobject, jlong);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_keys_buffer
 * Signature: (JLio/pmem/pmemkv/internal/GetKeysBuffersJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1keys_1buffer
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_keys_above_buffer
 * Signature: (JILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetKeysBuffersJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1keys_1above_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_keys_below_buffer
 * Signature: (JILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetKeysBuffersJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1keys_1below_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_keys_between_buffer
 * Signature: (JILjava/nio/ByteBuffer;ILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetKeysBuffersJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1keys_1between_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_count_all
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_io_pmem_pmemkv_Database_database_1count_1all
  (JNIEnv *, jobject, jlong);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_count_above_buffer
 * Signature: (JILjava/nio/ByteBuffer;)J
 */
JNIEXPORT jlong JNICALL Java_io_pmem_pmemkv_Database_database_1count_1above_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_count_below_buffer
 * Signature: (JILjava/nio/ByteBuffer;)J
 */
JNIEXPORT jlong JNICALL Java_io_pmem_pmemkv_Database_database_1count_1below_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_count_between_buffer
 * Signature: (JILjava/nio/ByteBuffer;ILjava/nio/ByteBuffer;)J
 */
JNIEXPORT jlong JNICALL Java_io_pmem_pmemkv_Database_database_1count_1between_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_all_buffer
 * Signature: (JLio/pmem/pmemkv/internal/GetAllBufferJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1all_1buffer
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_above_buffer
 * Signature: (JILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetAllBufferJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1above_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_below_buffer
 * Signature: (JILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetAllBufferJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1below_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_between_buffer
 * Signature: (JILjava/nio/ByteBuffer;ILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetAllBufferJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1between_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_exists_buffer
 * Signature: (JILjava/nio/ByteBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_pmem_pmemkv_Database_database_1exists_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_buffer_with_callback
 * Signature: (JILjava/nio/ByteBuffer;Lio/pmem/pmemkv/internal/GetKeysBuffersJNICallback;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1get_1buffer_1with_1callback
  (JNIEnv *, jobject, jlong, jint, jobject, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_get_bytes
 * Signature: (JILjava/nio/ByteBuffer;)[B
 */
JNIEXPORT jbyteArray JNICALL Java_io_pmem_pmemkv_Database_database_1get_1bytes
  (JNIEnv *, jobject, jlong, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_put_buffer
 * Signature: (JILjava/nio/ByteBuffer;ILjava/nio/ByteBuffer;)V
 */
JNIEXPORT void JNICALL Java_io_pmem_pmemkv_Database_database_1put_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject, jint, jobject);

/*
 * Class:     io_pmem_pmemkv_Database
 * Method:    database_remove_buffer
 * Signature: (JILjava/nio/ByteBuffer;)Z
 */
JNIEXPORT jboolean JNICALL Java_io_pmem_pmemkv_Database_database_1remove_1buffer
  (JNIEnv *, jobject, jlong, jint, jobject);

#ifdef __cplusplus
}
#endif
#endif
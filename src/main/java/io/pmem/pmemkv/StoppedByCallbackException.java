// SPDX-License-Identifier: BSD-3-Clause
/* Copyright 2020, Intel Corporation */

package io.pmem.pmemkv;

public class StoppedByCallbackException extends DatabaseException {

    public StoppedByCallbackException(String message) {
        super(message);
    }
}

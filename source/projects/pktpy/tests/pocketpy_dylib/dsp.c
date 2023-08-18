#include "pocketpy_c.h"
#include <stdio.h>
#include <stdlib.h>

static int hello(pkpy_vm* vm){
    printf("Hello from dylib!\n");
    return 0;
}

PK_EXPORT
const char* pkpy_module__init__(pkpy_vm* vm, const char* version){
    printf("version: %s\n", version);
    pkpy_push_function(vm, "hello()", hello);
    pkpy_push_module(vm, "dsp");
    pkpy_setattr(vm, pkpy_name("hello"));
    // check if initialization failed
    if(pkpy_clear_error(vm, NULL)) return NULL;
    return "dsp";
}

#ifndef BPF_LIB
#define BPF_LIB

#include "../prototypes/bpf_svc.h"

CLIENT* ebpf_connect(char *host);

ebpf_result_t* ebpf_verify_load_program(ebpf_verify_arg *args, CLIENT* clt);

#endif
#include "../prototypes/bpf_svc.h"
#include "bpf_lib.h"

CLIENT* ebpf_connect(char *host)
{
    CLIENT *clt = clnt_create(host, VERIFY_AND_LOAD, VERIFY_AND_LOAD_V1, "tcp");
    if (clt == NULL) {
        printf("Error connecting to eBPF server.\n");
    }

    return clt;
}

ebpf_result_t* result;
ebpf_result_t* ebpf_verify_load_program(ebpf_verify_arg *args, CLIENT* clt)
{
    if (!args)
    {
        printf("Arguments are NULL, please fill in the verification arguments.\n");
        ebpf_result_t invalid_result = EBPF_INVALID_ARGUMENT;
        result = &invalid_result;
        return result;
    }

    result = ebpf_verify_load_program_1(args, clt);
    if (result == NULL) {
        printf("Call to eBPF server failed.\n");
        return result;
    }

    printf("Received request. Log size: %u\n", *(args->log_size));

    return result;
}
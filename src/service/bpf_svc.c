#include "../prototypes/bpf_svc.h"

ebpf_result_t result;
ebpf_result_t* ebpf_verify_load_program_1_svc(ebpf_verify_arg *args, struct svc_req *req)
{
    if (!args || args->info->instruction_count == 0)
    {
        result = EBPF_INVALID_ARGUMENT;
        return &result;
    }

    printf("Verifying BPF program...");

    return &result;
}
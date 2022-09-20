#include "../lib/bpf_lib.h"

int main (int argc, char **argv)
{
    printf("Starting client...\n");

    CLIENT *clt = ebpf_connect("localhost");
    printf("Opened connection...\n");

    struct ebpf_verify_arg args;
    int size = 10;
    args.log_size = &size;

    ebpf_result_t *result = ebpf_verify_load_program(&args, clt);

    int iresult = (int)*(result);
    if (result != EBPF_SUCCESS)
    {
        printf("ERROR: status code is %i\n", iresult);
    }
    else
    {
        printf("Done sending the request\n");
    }

    return iresult;
}
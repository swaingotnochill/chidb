#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    
    const char *cc = "cc";
    const char *cflags = "-Wall -Wextra -Iinclude";
    const char *output = "build/chidbshell";

    if(!nob_mkdir_if_not_exists("build")) {
        fprintf(stderr, "ERROR: Failed to create build directory.\n");
        return 1;
    }

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, cc, cflags, "-o", output, "src/shell/main.c", "src/shell/shell.c", NULL);
    if(!nob_cmd_run_sync(cmd)) {
        fprintf(stderr, "ERROR: Failed to create build directory.\n");
        return 1;
    }

    printf("Build successfull! Output : %s", output);
    return 0;
}

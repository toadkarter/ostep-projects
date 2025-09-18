#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 512

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];

    for (int i = 2; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (!file) {
            printf("wgrep: cannot open file\n");
            return 1;
        }

        while (fgets(buffer, sizeof(buffer), file)) {
            if (strstr(buffer, argv[1])) {
                printf("%s", buffer);
            }
        }

        fclose(file);
    }
}
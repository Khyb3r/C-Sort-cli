#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sorting_algo(char *, int);
int main(int argc, char *argv[]) {
    // open the file and make sure it is correct (1 file only to be sorted)
    if (argc < 2) {
        fprintf(stderr, "Incorrect file formatting\n");
        exit(1);
    }
    // pick argv[1]
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Incorrect formatting of file");
        exit(1);
    }
    // buffer to read from file
    char entireFile[3000];
    char buffer[1024];
    char *string = NULL;
    while ((string = fgets(buffer, 1024, file)) != NULL) {
        // sort the buffer
        strcat(entireFile, string);
    }
    // sort into array by first spaces
    char newArray[100];
    for (int i = 0; i < sizeof(entireFile); i++) {
        strtok()
    }
    sorting_algo(entireFile, sizeof(entireFile));

}
void sorting_algo(char *p_string, size_t length) {
    qsort
}

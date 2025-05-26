#include <stdio.h>
#include <stdlib.h>

// compare function
int compare(const void *p_one, const void *p_two) {
    unsigned char byte_one = *(unsigned char *)p_one;
    unsigned char byte_two = *(unsigned char *)p_two;
    return (byte_one > byte_two) - (byte_one < byte_two);
}


// sort binary based
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Incorrect input format");
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr,"Couldn't open file");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    // read from the file and convert into binary
    unsigned char *buffer = malloc(fileSize);
    if (buffer == NULL) {
        fprintf(stderr, "Malloc error with buffer\n");
        exit(1);
    }
    size_t bytesRead = fread(buffer, sizeof(unsigned char), fileSize, file);
    if (bytesRead != fileSize) {
        printf("read error\n");
        exit(1);
    }
    qsort(buffer, bytesRead, sizeof(unsigned char), compare);

    for (int i = 0; i < bytesRead; i++) {
        printf("%u", buffer[i]);
    }
    printf("\n");
    free(buffer);
    return 0;
}

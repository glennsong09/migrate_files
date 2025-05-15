#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Please input .so, signature file, and name for .so file including signature file.");
    }

    FILE *fptr1 = fopen(argv[1], "rb");
    FILE *fptr2 = fopen(argv[2], "rb");
    FILE *fptr3 = fopen(argv[3], "wb");

    if (fptr1 == NULL || fptr2 == NULL || fptr3 == NULL) {
        printf("Error opening files!\n");
        return 1;
    }

    // Copy contents of the first file to the third file
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), fptr1)) > 0) {
        fwrite(buffer, 1, n, fptr3);
    }

    //char flag[] = "HDF5signed_plugin_signature_start";
    //fwrite(flag, sizeof(char), strlen(flag), fptr3);

    // Copy contents of the second file to the third file
    while ((n = fread(buffer, 1, sizeof(buffer), fptr2)) > 0) {
        fwrite(buffer, 1, n, fptr3);
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

    printf("Contents merged successfully");
    return 0;
}
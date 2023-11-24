#include <stdio.h>
#include <string.h>

void logo() {
    printf(" __      ___                                       _       _               \n");
    printf(" \\ \\    / (_)                                     (_)     | |              \n");
    printf("  \\ \\  / / _  __ _  ___ _ __   ___ _ __ ___    ___ _ _ __ | |__   ___ _ __ \n");
    printf("   \\ \\/ / | |/ _` |/ _ \\ '_ \\ / _ \\ '__/ _ \\  / __| | '_ \\| '_ \\ / _ \\ '__|\n");
    printf("    \\  /  | | (_| |  __/ | | |  __/ | |  __/ | (__| | |_) | | | |  __/ |   \n");
    printf("     \\/   |_|\\__, |\\___|_| |_|\\___|_|  \\___|  \\___|_| .__/|_| |_|\\___|_|   \n");
    printf("              __/ |                                 | |                    \n");
    printf("             |___/                                  |_|                    \n");
    printf("                                                 Made by Black Ghost");
}

void encrypt(const char* key, const char* inputFileName) {
    FILE* inputFile, *outputFile;
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen("encrypted.txt", "w");

    if (inputFile == NULL) {
        printf("Make input.txt !!!\n");
        return;
    }

    int keyLength = strlen(key);
    int keyIndex = 0;
    char c;

    while ((c = fgetc(inputFile)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' + key[keyIndex] - 'a') % 26;
            keyIndex = (keyIndex + 1) % keyLength;
        }
        else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' + key[keyIndex] - 'a') % 26;
            keyIndex = (keyIndex + 1) % keyLength;
        }

        fputc(c, outputFile);

        printf("%d\n",keyIndex);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decrypt(const char* key, const char* inputFileName) {
    FILE* inputFile, *outputFile;
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen("decrypted.txt", "w");

    if (inputFile == NULL) {
        printf("Make input.txt !!!\n");
        return;
    }

    int keyLength = strlen(key);
    int keyIndex = 0;
    char c;

    while ((c = fgetc(inputFile)) != EOF) {
      if (c >= 'a' && c <= 'z') {
          c = 'a' + (c - 'a' - (key[keyIndex] - 'a') + 26) % 26;
          keyIndex = (keyIndex + 1) % keyLength;
      }
      else if (c >= 'A' && c <= 'Z') {
          c = 'A' + (c - 'A' - (key[keyIndex] - 'a') + 26) % 26;
          keyIndex = (keyIndex + 1) % keyLength;
      }

    fputc(c, outputFile);
}


    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    logo();

    int start = 1;
    int value;
    char key[100];
    char inputFileName[] = "input.txt";

    while (start) {
        printf("\n| MENU |\n");
        printf(" 1 -> Encrypt\n");
        printf(" 2 -> Decrypt\n");
        printf(" 0 -> Exit\n\n");

        printf("Enter value : ");
        scanf("%d", &value);

        switch (value) {
            case 1:
                printf(" Key for encrypt = ");
                scanf("%s", key);
                encrypt(key, inputFileName);
                break;

            case 2:
                printf(" Key for decrypt = ");
                scanf("%s", key);
                decrypt(key, inputFileName);
                break;

            case 0:
                start = 0;
                break;

            default:
                printf("Enter 1, 2, or 0 !!!\n");
                break;
        }
    }

    return 0;
}

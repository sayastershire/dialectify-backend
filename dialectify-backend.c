#include <stdio.h>
#include <assert.h>

// Forward declarations
void parseOptions(int argc, char **argv);
void readAloudArgs(int argc, char **argv);

// --- Variables
// - Boolean
int customOutput = 0, customType = 0;
char *filename, *input;
int main(int argc, char **argv){
    printf("Initialising dialectify-backend.\n");
    readAloudArgs(argc, argv);
    printf("Parsing options.\n");
    parseOptions(argc, argv);
    return 0;
}

void parseOptions(int argc, char **argv){
    // Example: ./dialectify-backend -t csv -o "data.csv" input.txt
    printf("Entering parseOptions.\n");
    for (int i = 1; i < argc; i++) {
        printf("Entering for loop. [i=%d], argv[%d][0(~1)]=%c", i, i, argv[i][0]);
        switch(argv[i][0]){
        case '-':
            printf("%c\n", argv[i][1]);
            switch(argv[i][1]){
            case 't':
                ++customType;
                char *requestedType = argv[++i];
                printf("Requested type: %s", requestedType);
                break;
            case 'o':
                ++customType;
                filename = argv[++i];
                printf("Requested output filename: %s", filename);
                break;
            }
            break;
        default:
            printf("\n");
            if (i >= argc) {
                printf("\nError: input not found.\n");
                assert(0);
            }
            else {
                input = argv[i];
                printf("Input name: %s\n", input);
            }
            break;
        }
    }
}

void readAloudArgs(int argc, char **argv){
    printf("argc = %d\n", argc);
    for (int i = 0; i < (argc); i++){
        printf("argv[%d] = %s\n", i , argv[i]);
    }
}
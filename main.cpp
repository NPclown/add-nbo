#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

uint32_t readFile(char* fileName){
    uint32_t result;
    FILE* f = fopen(fileName, "rb");

    if (f == NULL){
        fprintf(stderr,"\"%s\" Not exisit.\n", fileName);
        exit(-1);
    }
    
    size_t readlen = fread(&result, 1, sizeof(uint32_t), f);
    if (readlen != sizeof(uint32_t)){
        fprintf(stderr,"fread return %lu\n", readlen);
        exit(-1);
    }
    
    fclose(f);
    return htonl(result);
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printf("syntax : add-nbo <file1> <file2>\n");
        return -1;
    }

    uint32_t result_1 = readFile(argv[1]);
    uint32_t result_2 = readFile(argv[2]);
    
    
    uint32_t result_3 = result_1 + result_2;
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", result_1, result_1, result_2, result_2, result_3, result_3);
}
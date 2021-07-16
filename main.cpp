#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t readFile(char* fileName){
    uint32_t result;
    FILE* f = fopen(fileName, "rb");

    if (f == NULL){
        printf("syntax : add-nbo <file1> <file2>\n");
        return -1;
    }
    
    fread(&result, sizeof(uint32_t), 1, f);
    
    fclose(f);
    return htonl(result);
}

int main(int argc, char* argv[]){

    uint32_t result_1 = readFile(argv[1]);
    uint32_t result_2 = readFile(argv[2]);
    
    if (result_1 != -1 && result_2 != -1){
        uint32_t result_3 = result_1 + result_2;
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", result_1, result_1, result_2, result_2, result_3, result_3);
    }
}
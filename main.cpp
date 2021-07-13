#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
    FILE* f1 = fopen(argv[1], "rb");
    FILE* f2 = fopen(argv[2], "rb");

    uint32_t t1, t2;
    uint32_t r1, r2, r3;

    if (f1 == NULL || f2 == NULL){
        printf("syntax : add-nbo <file1> <file2>\n");
    }else{
        fread(&t1, sizeof(uint32_t), 1, f1);
        fread(&t2, sizeof(uint32_t), 1, f2);

        r1 = htonl(t1);
        r2 = htonl(t2);
        r3 = r1 + r2;
        printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", r1, r1, r2, r2, r3, r3);
    }
}
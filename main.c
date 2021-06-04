#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "disassembler.h"

size_t get_file_size(FILE *fd){
    fseek(fd, 0, SEEK_END);
    size_t size = ftell(fd);
    rewind(fd);
    return size;
}

int disassemble_file(char* filename){
    FILE *fd = fopen(filename, "r");
    if (!fd)
    {
        printf("Error opening input file.\n");
        return 1;
    }
    size_t size = get_file_size(fd);
    char* buffer = malloc(size);
    fread(buffer, sizeof(uint8_t), size, fd);
    fclose(fd);

    char dasm_buffer[64];
    uint32_t offset = 0;

    while (offset < size)
    {
        offset += disassemble_6502_to_string(buffer, dasm_buffer, offset);
        printf("%s\n",dasm_buffer);
    }   
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Usage: 6502dasm [FILENAME]\n");
        return 0;
    }
    else
    {
        return disassemble_file(argv[1]);
    }
}

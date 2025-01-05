#include <stdio.h>

#include "bitstring.h"

void bitstring_basic(int64_t number, int bits, bitstr_t bitstring, size_t size) {
    if (size < bits + 1) {  // bits + null terminator
        snprintf(bitstring, size, "[Error: Buffer too small]");
        return;
    }

    for (int i = bits - 1; i >= 0; --i) {
        bitstring[bits - 1 - i] = (number & (1ULL << i)) ? '1' : '0';
    }

    bitstring[bits] = '\0';  // Null-terminate the string
}

void bitstring_u_basic(uint64_t number, int bits, bitstr_t bitstring, size_t size) {
    if (size < bits + 1) {  // bits + null terminator
        snprintf(bitstring, size, "[Error: Buffer too small]");
        return;
    }

    for (int i = bits - 1; i >= 0; --i) {
        bitstring[bits - 1 - i] = (number & (1ULL << i)) ? '1' : '0';
    }

    bitstring[bits] = '\0';  // Null-terminate the string
}

void bitstring8(int8_t number, bitstr_t bitstring, size_t size) {
    bitstring_basic((uint64_t)number, 8, bitstring, size);
}

void bitstring16(int16_t number, bitstr_t bitstring, size_t size) {
    bitstring_basic((uint64_t)number, 16, bitstring, size);
}

void bitstring32(int32_t number, bitstr_t bitstring, size_t size) {
    bitstring_basic((uint64_t)number, 32, bitstring, size);
}

void bitstring64(int64_t number, bitstr_t bitstring, size_t size) {
    bitstring_basic((uint64_t)number, 64, bitstring, size);
}

void ubitstring8(uint8_t number, bitstr_t bitstring, size_t size) {
    bitstring_u_basic((uint64_t)number, 8, bitstring, size);
}

void ubitstring16(uint16_t number, bitstr_t bitstring, size_t size) {
    bitstring_u_basic((uint64_t)number, 16, bitstring, size);
}

void ubitstring32(uint32_t number, bitstr_t bitstring, size_t size) {
    bitstring_u_basic((uint64_t)number, 32, bitstring, size);
}

void ubitstring64(uint64_t number, bitstr_t bitstring, size_t size) {
    bitstring_u_basic(number, 64, bitstring, size);
}
#if !defined(BITSTRING_H)
#define BITSTRING_H

#include <stdint.h>

typedef char bit_t, *bitstr_t;

void bitstring_basic(int64_t number, int bits, bitstr_t bitstring, size_t size);
void bitstring_u_basic(uint64_t number, int bits, bitstr_t bitstring, size_t size);

void bitstring8(int8_t number, bitstr_t bitstring, size_t size);
void bitstring16(int16_t number, bitstr_t bitstring, size_t size);
void bitstring32(int32_t number, bitstr_t bitstring, size_t size);
void bitstring64(int64_t number, bitstr_t bitstring, size_t size);

void ubitstring8(uint8_t number, bitstr_t bitstring, size_t size);
void ubitstring16(uint16_t number, bitstr_t bitstring, size_t size);
void ubitstring32(uint32_t number, bitstr_t bitstring, size_t size);
void ubitstring64(uint64_t number, bitstr_t bitstring, size_t size);

#endif // BITSTRING_H

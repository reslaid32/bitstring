
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#include "bitstring.h"

void run_tests() {
    {
        char bitstring[65];

        { // Signed
            int8_t test_values_8[] = {0, 1, -1, 127, -128};
            bitstring8(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000") == 0);
            bitstring8(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000001") == 0);
            bitstring8(-1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "11111111") == 0);
            bitstring8(127, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "01111111") == 0);
            bitstring8(-128, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "10000000") == 0);

            int16_t test_values_16[] = {0, 1, -1, 32767, -32768};
            bitstring16(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000") == 0);
            bitstring16(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000001") == 0);
            bitstring16(-1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1111111111111111") == 0);
            bitstring16(32767, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0111111111111111") == 0);
            bitstring16(-32768, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1000000000000000") == 0);

            int32_t test_values_32[] = {0, 1, -1, 2147483647, -2147483648};
            bitstring32(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000000000000000000000000000") == 0);
            bitstring32(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000000000000000000000000001") == 0);
            bitstring32(-1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "11111111111111111111111111111111") == 0);
            bitstring32(2147483647, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "01111111111111111111111111111111") == 0);
            bitstring32(-2147483648, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "10000000000000000000000000000000") == 0);

            int64_t test_values_64[] = {0, 1, -1, 9223372036854775807, -9223372036854775807};
            bitstring64(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000000000000000000000000000000000000000000000000000") == 0);
            bitstring64(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000000000000000000000000000000000000000000000000001") == 0);
            bitstring64(-1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1111111111111111111111111111111111111111111111111111111111111111") == 0);
            bitstring64(9223372036854775807, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0111111111111111111111111111111111111111111111111111111111111111") == 0);
            bitstring64(-9223372036854775807, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1000000000000000000000000000000000000000000000000000000000000001") == 0);

        }
        { // Unsigned
            ubitstring8(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000") == 0);
            ubitstring8(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000001") == 0);
            ubitstring8(255, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "11111111") == 0);
            ubitstring8(127, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "01111111") == 0);
            ubitstring8(128, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "10000000") == 0);

            ubitstring16(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000") == 0);
            ubitstring16(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000001") == 0);
            ubitstring16(65535, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1111111111111111") == 0);
            ubitstring16(32767, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0111111111111111") == 0);
            ubitstring16(32768, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1000000000000000") == 0);

            ubitstring32(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000000000000000000000000000") == 0);
            ubitstring32(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "00000000000000000000000000000001") == 0);
            ubitstring32(4294967295, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "11111111111111111111111111111111") == 0);
            ubitstring32(2147483647, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "01111111111111111111111111111111") == 0);
            ubitstring32(2147483648, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "10000000000000000000000000000000") == 0);

            uint64_t test_values_64[] = {0, 1, 18446744073709551615ULL, 9223372036854775807ULL, 9223372036854775808ULL};
            ubitstring64(0, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000000000000000000000000000000000000000000000000000") == 0);
            ubitstring64(1, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0000000000000000000000000000000000000000000000000000000000000001") == 0);
            ubitstring64(18446744073709551615ULL, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1111111111111111111111111111111111111111111111111111111111111111") == 0);
            ubitstring64(9223372036854775807ULL, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "0111111111111111111111111111111111111111111111111111111111111111") == 0);
            ubitstring64(9223372036854775808ULL, bitstring, sizeof(bitstring));
            assert(strcmp(bitstring, "1000000000000000000000000000000000000000000000000000000000000000") == 0);
        }
    }

    printf("All tests passed!\n");
}

int main() {
    run_tests();
    return 0;
}
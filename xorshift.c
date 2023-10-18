#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

// XORShift function to generate 32-bit random integers
uint32_t xorShift(uint32_t *state) {
    uint32_t x = *state;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    *state = x;
    return x;
}

int main() {
    // proving the seed (current time) to the xorShift function
    uint32_t seed = (uint32_t)time(NULL);

    // Initializing the state
    uint32_t state = seed;

    // Generating and printing random numbers
    for (int i = 0; i < 1; i++) {
        uint32_t randomNumber = xorShift(&state);
        printf("Random Number: %" PRIu32 "\n", randomNumber);
    }

    return EXIT_SUCCESS;
}

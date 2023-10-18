# XORShift Random Number Generator

## XORShift Algorithm

The XORShift algorithm is a simple pseudorandom number generator known for its speed and efficiency. It uses bitwise XOR operations to generate a sequence of pseudorandom numbers. The algorithm operates on an internal state and updates it with each call to produce a new random value. 

### Key Properties

- XORShift is known for its simplicity and speed, making it a lightweight choice for generating random numbers.
- It has good statistical properties, making it suitable for various applications that require random numbers.
- The algorithm is easy to implement and doesn't rely on complex mathematical functions.
- XORShift can be used for tasks like simulations, gaming, and cryptography.

### Initialization

To use XORShift, you need to initialize it with a seed value. The seed value determines the starting state of the generator. You should use a different seed for each sequence of random numbers you want to generate.

### Generating Random Numbers

After initialization, you can repeatedly call the XORShift function with the current state as an argument to generate random numbers. Each call updates the state and returns a new random value.

### Explanation
```c
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
    // Providing the seed (current time) to the xorShift function
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

```

This C code does the following:

- It includes several standard C libraries (`stdio.h`, `stdlib.h`, `time.h`, and `inttypes.h`) for input and output, memory allocation, time-related functions, and integer type definitions.

- The code defines a function `xorShift` that implements the XORShift algorithm to generate 32-bit random integers. This function takes a pointer to a 32-bit integer as an input and returns a random number.

- In the `main` function, it initializes a seed for the random number generator based on the current time using the `time` function. The seed is used to start the XORShift algorithm.

- It then initializes a state variable with the seed value.

- A loop generates and prints one random number using the `xorShift` function. The loop iterates only once in this case.

- The random number is printed to the standard output using `printf`, and the `% PRIu32` format specifier is used to print the 32-bit integer as an unsigned integer.

- Finally, the program returns `EXIT_SUCCESS`, indicating successful execution.

The code effectively demonstrates the generation of a single 32-bit random number using the XORShift algorithm with a seed based on the current time.

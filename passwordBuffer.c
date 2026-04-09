#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
 * CHALLENGE: The Padded Password Buffer
 * -------------------------------------
 * Goal: Write a program that asks a user to create a password while 
 * enforcing strict memory-aware rules and validating buffer boundaries.
 *
 * Requirements:
 * 1. Define a Buffer: Create a char array with a fixed size (32 bytes).
 * 2. Size Validation: Print the "Maximum Capacity" of the buffer 
 * using 'sizeof' and 'size_t' before taking input.
 * 3. Input: Use 'fgets()' to read the password safely.
 * 4. The Analysis:
 * - Calculate the actual string length (using 'strlen').
 * - Calculate "wasted space" (Total buffer size minus used space).
 *
 * Flow Control Logic:
 * - If length < 8 chars: Print "Weak."
 * - If length == (buffer size - 1): Print "Warning: Buffer nearly full."
 * - If "wasted space" > 80% of buffer: Print "Warning: Inefficient memory usage."
 *
 * Concepts Tested: sizeof vs strlen, memory padding, null terminators, 
 * and buffer overflow prevention.
 */



int main(void) {
    char buffer[32]; // password: fixed size 32. Actual size is 31.
    size_t sizeOfBuffer = sizeof buffer;
    printf("Maximum size of the buffer is %zu\n", sizeOfBuffer);

    printf("Enter a password: ");
    fgets(buffer, sizeOfBuffer, stdin);

    int leftOverSpace = sizeOfBuffer - strlen(buffer); // the null terminator compensates for the newline from the fgets
    printf("Leftover space %d\n", leftOverSpace);

    if (leftOverSpace >= 23) {
        printf("Weak password");
    } 

    else if (leftOverSpace == 1) { // max character for the password is 31
        printf("Warning: Buffer nearly full");        
    }

    else if (leftOverSpace <= 7) { // less than 80 percent
        printf("Warning: Inefficient memory usage");
    }

    else {
        printf("Good Password");
    }

    return 0;
}
// caesar.c
// CS50x - Week 2, Problem Set 2
//
// Exercise: Caesar Cipher
// ------------------------
// Encrypt a message by rotating each letter forward in the alphabet
// by a numeric key given as a command-line argument.
//
//   Example (key = 3):  A→D, B→E, Z→C (wraps around)
//   "hello" → "khoor"
//
// Usage:
//   ./caesar KEY       (KEY must be a non-negative integer)
//   ./caesar           → prints usage error
//   ./caesar abc       → prints usage error
//
// How to compile:  make caesar
// How to run:      ./caesar 13
// How to check:    check50 cs50/problems/2024/x/caesar

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // ---------------------------------------------------------------------------
    // STEP 1: Validate command-line arguments
    // ---------------------------------------------------------------------------
    // The program must be called with exactly one argument: ./caesar KEY
    // If argc != 2, OR if the key is not all digits, print the usage message
    // and return 1 (indicating an error).
    //
  if (argc != 2 || !only_digits(argv[1]))
{
    printf("Usage: ./caesar key\n");
    return 1;
}


    // ---------------------------------------------------------------------------
    // STEP 2: Convert the key from string to int
    // ---------------------------------------------------------------------------
   int key = atoi(argv[1]);


    // ---------------------------------------------------------------------------
    // STEP 3: Get the plaintext from the user
    // ---------------------------------------------------------------------------
   string plaintext = get_string("plaintext: ");


    // ---------------------------------------------------------------------------
    // STEP 4: Encrypt and print the ciphertext
    // ---------------------------------------------------------------------------
    // TODO: Loop through each character of plaintext.
    //       Call rotate(c, key) for each character to get the encrypted version.
    //       Print each encrypted character WITHOUT a newline inside the loop.
    //
    // After the loop, print a newline:
    //   printf("\n");
    //
    // The output should start with "ciphertext: " (with a trailing space):
    //   printf("ciphertext: ");
printf("ciphertext: ");

for (int i = 0; i < strlen(plaintext); i++)
{
    printf("%c", rotate(plaintext[i], key));
}

printf("\n");
}


// ---------------------------------------------------------------------------
bool only_digits(string s)
{
for (int i = 0; i < strlen(s); i++)
{
    if (!isdigit(s[i]))
    {
        return false;
    }
}

return true;
   
}

// ---------------------------------------------------------------------------
// TODO: Implement rotate
// ---------------------------------------------------------------------------
// Rotate character c forward by n positions in the alphabet.
// Preserve case: uppercase stays uppercase, lowercase stays lowercase.
// Non-letter characters are returned UNCHANGED.
//
// The math (for uppercase):
//   char encrypted = (c - 'A' + n) % 26 + 'A';
//
// The math (for lowercase):
//   char encrypted = (c - 'a' + n) % 26 + 'a';
// ---------------------------------------------------------------------------
char rotate(char c, int n)
{
    if (isupper(c))
{
    return (c - 'A' + n) % 26 + 'A';
}
else if (islower(c))
{
    return (c - 'a' + n) % 26 + 'a';
}
else
{
    return c;
}
}

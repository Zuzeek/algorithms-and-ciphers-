#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int UPPER = 65;
const int LOWER = 97;
const int ALPHABET = 26;

int shift(char c);

int main(int argc, string argv[])
{
    int key = 0;
    string k = argv[1];

    // check if one command-line argument
    if (argc == 2)
    {
        // Iterate over the provided argument to make sure all characters are alphabetic
        for (int i = 0, n = strlen(k); i < n; i++)
        {
            if (isalpha(k[i]) == false)
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
        // Shift value
        key = shift(k[0]);
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Prompt user for plaintext
    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over the key with 'j'
    int j = 0;

    // Iterate over each character of the plaintext:
    for (int i = 0; i < strlen(p); i++)
    {
        /* If it is an uppercase/lowercase letter, shift it, preserving case,
            then print out the rotated character */
        if (isupper(p[i]))
        {
            printf("%c", ((((p[i] - UPPER) + shift(k[j % strlen(k)])) % ALPHABET) + UPPER));
            j++;
        }
        else if (islower(p[i]))
        {
            printf("%c", ((((p[i] - LOWER) + shift(k[j % strlen(k)])) % ALPHABET) + LOWER));
            j++;
        }
        /* If it is neither, print out the character as is */
        else
        {
            printf("%c", p[i]);
        }
    }

    // Print a newline
    printf("\n");
    return 0;
}

// shift value
int shift(char c)
{
    // convert that char to its positional int value
    int key = c;
    if (islower(c))
    {
        return c - LOWER;
    }
    else if (isupper(c))
    {
        return c - UPPER;
    }
    else
    {
        return c;
    }
    return 0;
}
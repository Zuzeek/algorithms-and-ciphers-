#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, string argv[])
{
    // get the key
    if (argc == 2)
    {
        // turn key (string) into integer using atoi
        int k = atoi(argv[1]);
        printf("Key: %i\n", k);

        // prompt user for plaintext
        string p = get_string("plaintext: ");
        // print Ciphertext
        printf("ciphertext: ");

        // iterate over chars; ASCII - convert letters to numbers
        for (int i = 0; i < strlen(p); i++)
        {
            // preserve capitalization: isupper
            if (isupper(p[i]))
            {
                // encipher from ASCII to Alphabetical index & back
                printf("%c", (((p[i] - 65) + k) % 26) + 65);
            }
            // preserve lowercase: islower
            else if (islower(p[i]))
            {
                // encipher from ASCII to Alphabetical index & back
                printf("%c", (((p[i] - 97) + k) % 26) + 97);
            }
            // shift letters only: isalpha
            else
            {
                printf("%c", p[i]);
            }
        }
    }
    else
    {
        printf("Error: missing command line argument.\n");
        return 1;
    }
    printf("\n");
    return 0;
}
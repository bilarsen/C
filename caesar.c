#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        string p = get_string("plaintext: ");
        int len = strlen(p);
        char c[len];
        //encryption process
        for (int i = 0; i < len; ++i)
        {
            //check that only letters would be encrypted
            if (isalpha(p[i]))
            {
                //check for uppercase
                if (isupper(p[i]))
                {
                    c[i] = ((p[i] + k % 26) - 'A') % 26 + 'A';
                }
                //lowercase
                else
                {
                    c[i] = ((p[i] + k % 26) - 'a') % 26 + 'a';
                }
            }
            //non-alphabetic characters
            else
            {
                c[i] = p[i];
            }
        }
        printf("ciphertext: %s\n", c);
        return 0;
    }
    //error message for wrong input
    else
    {
        printf("Error\n");
        return 1;
    }
}
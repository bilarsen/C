#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
   if (argc == 2)
   {
       string k = argv[1];
       int n = 0;
       bool flag = true;
       //checking keyword for chars
       while (k[n])
       {
           if (isalpha(k[n]))
           {
               ++n;
           }
           else
           {
               flag = false;
               printf("Error\n");
               return 1;
               break;
           }
       }
       //condition for keyword to consist only of chars
       if (flag)
       {
           string p = get_string("plaintext: ");
           int len = strlen(p);
           char c[len + 1];
           c[len] = '\0';
           int j = 0;
           int klen = strlen(k);
           //algorithm
           for (int i = 0; i < len; ++i)
           {
               //true position of j in a keyword
               j %= klen;
               //check for plaintext char
               if (isalpha(p[i]))
               {
                   int key = (int)k[j];
                   //keyword's value of each char
                   (key > 64 && key < 91) ? (key -= 65) : (key -= 97);
                   //uppercase char of plaintext
                   if (isupper(p[i]))
                   {
                       c[i] = (p[i] + key - 'A') % 26 + 'A';
                   }
                   //lowercase char of plaintext
                   else
                   {
                       c[i] = (p[i] + key - 'a') % 26 + 'a';
                   }
                   ++j;
               }
               //char of plaintext is not a letter
               else
               {
                   c[i] = p[i];
               }
           }
           //result
           printf("ciphertext: %s\n", c);
           return 0;
       }
   }
   //error
   else
   {
       printf("Error\n");
       return 1;
   }
}
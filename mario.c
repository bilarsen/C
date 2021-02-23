//building pyramid for Mario
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for pyramid's height
    int h;
    do
    {
        h = get_int("Choose height: ");
        //error message for user
        if (h < 0 || h > 23)
        {
            printf("Sorry, try again.\n");
        }
    }
    while (h < 0 || h > 23);

    /*drawing a pyramid*/
    for (int r = 0; r < h; r ++)
    {
        //spaces for left side
        for (int s = 0; s < h - r - 1; s++)
        {
            printf(" ");
        }
        //blocks for left side + gap + blocks for right side
        for (int b = 0; b < (r + 1) * 2; b++)
        {
            printf("#");
            if (b == r)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
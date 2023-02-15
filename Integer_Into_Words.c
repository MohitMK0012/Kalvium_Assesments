#include <stdio.h>

void spell_out_number(int number)
{
    if (number == 0)
    {
        printf("zero");
    }
    else if (number < 20)
    {
        switch (number)
        {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        case 10:
            printf("ten");
            break;
        case 11:
            printf("eleven");
            break;
        case 12:
            printf("twelve");
            break;
        case 13:
            printf("thirteen");
            break;
        case 14:
            printf("fourteen");
            break;
        case 15:
            printf("fifteen");
            break;
        case 16:
            printf("sixteen");
            break;
        case 17:
            printf("seventeen");
            break;
        case 18:
            printf("eighteen");
            break;
        case 19:
            printf("nineteen");
            break;
        }
    }
    else if (number < 100)
    {
        int tens = number / 10;
        int ones = number % 10;
        switch (tens)
        {
        case 2:
            printf("twenty");
            break;
        case 3:
            printf("thirty");
            break;
        case 4:
            printf("forty");
            break;
        case 5:
            printf("fifty");
            break;
        case 6:
            printf("sixty");
            break;
        case 7:
            printf("seventy");
            break;
        case 8:
            printf("eighty");
            break;
        case 9:
            printf("ninety");
            break;
        }
        if (tens > 0 && ones > 0)
        {
            printf("-");
        }
        if (ones > 0)
        {
            spell_out_number(ones);
        }
    }
    else if (number < 1000)
    {
        int hundreds = number / 100;
        int remainder = number % 100;
        spell_out_number(hundreds);
        printf(" hundred");
        if (remainder > 0)
        {
            printf(" ");
            spell_out_number(remainder);
        }
    }
    else if (number < 10000)
    {
        int thousands = number / 1000;
        int remainder = number % 1000;
        spell_out_number(thousands);
        printf(" thousand");
        if (remainder > 0)
        {
            if (remainder < 100)
            {
                printf(" and ");
            }
            else
            {
                printf(" ");
            }
            spell_out_number(remainder);
        }
    }
    else
    {
        printf("\nNumber is too large");
    }
}

int main()
{
    int number;
    printf("\nEnter a number: ");
    scanf("%d", &number);
    printf("\n");
    spell_out_number(number);
    printf("\n\n");
    return 0;
}

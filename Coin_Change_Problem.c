#include <stdio.h>

int min(int a, int b) 
{
    return (a < b) ? a : b;
}

int minCoins(int coins[], int num_coins, int amount) 
{
    int table[num_coins][amount + 1];

    for (int i = 0; i < num_coins; i++) {
        table[i][0] = 0;
    }

    for (int i = 0; i < num_coins; i++) 
    {
        for (int j = 1; j <= amount; j++)
        {
            if (j < coins[i]) 
            {
                table[i][j] = (i > 0) ? table[i-1][j] : -1;
            } 
            else if (i == 0) 
            {
                table[i][j] = 1 + table[i][j - coins[i]];
            } 
            else 
            {
                table[i][j] = min(table[i-1][j], 1 + table[i][j - coins[i]]);
            }
        }
    }
    return table[num_coins-1][amount];
}

int main() 
{
    int num_coins, i, amount, result;

    printf("\nEnter the number of coin denominations: ");
    scanf("%d", &num_coins);
    printf("\n");

    int coins[num_coins];

    for (i = 0; i < num_coins; i++) 
    {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("\nEnter the amount for which you need to change: ");
    scanf("%d", &amount);
    result = minCoins(coins, num_coins, amount);
    printf("\nMinimum number of coins required: %d\n\n", result);
    return 0;
}


#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //prompt for change in cents:
    float dollars;
    int coins = 0;
    int change;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0.001);

    change = round(dollars * 100);

    // coins count
    // quarter = 0.25 *100; // 25
    // dime = 0.10 *100; // 10
    // nickel = 0.05 *100; // 5
    // penny = 0.01 *100; // 1

    while (change >= 25)
    {
        ++coins;
        change -= 25;
    }
    while (change >= 10)
    {
        ++coins;
        change -= 10;
    }
    while (change >= 5)
    {
        ++coins;
        change -= 5;
    }
    while (change >= 1)
    {
        ++coins;
        change -= 1;
    }
    printf("Amount of Coins: %i\n", coins);
}
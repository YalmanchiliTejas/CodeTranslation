#include <stdio.h>
#include <string.h>

#define A "delicious"
#define B "safe"
#define C "dangerous"

int main() 
{
        int r, g, b;

        scanf("%d %d %d", &r, &g, &b);

        int temp = (r*100) + (g*10) + b;

        temp %= 4;

        if (temp == 0)
                printf("YES\n");
        else
                printf("NO\n");

        return 0;
}
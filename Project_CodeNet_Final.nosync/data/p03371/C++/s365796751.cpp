#include <stdio.h>

int main()
{
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    int min = x < y ? x : y;
    long ans = 0;
    long anst = 0;
    if (a + b > 2 * c)
    {
        if (x > y)
        {
            ans = y * 2 * c + (x - y) * a;
        }
        else
        {
            ans = x * 2 * c + (y - x) * b;
        }
    }
    else
    {
        ans = a * x + b * y;
    }

    if (x > y)
    {
        anst = x * 2 * c;
    }
    else
    {
        anst = y * 2 * c;
    }
    if (ans > anst)
    {
        ans = anst;
    }

    printf("%ld\n", ans);
}
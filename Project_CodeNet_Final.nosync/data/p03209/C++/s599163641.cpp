#include <stdio.h>
#include <stdlib.h>
    long long int b[51], a[51];
    long long int e;

long long f(long long x, long long y)
{
    if (y <= x)
        return 0;
    if (y >= b[x] - 1)
        return a[x];
    if (y == b[x] / 2 + 1)
        return a[x] / 2 + 1;
    else if (y > b[x] / 2 + 1)
        return a[x] / 2 + 1 + f(x - 1, y - b[x] / 2 - 1);
    else
        return f(x - 1, y - 1);

}
int main()
{
    long long c, d;
    a[0]=1;
    b[0]=1;
    for(e = 1; e < 51; e++)
    {
        a[e] = (a[e-1] * 2) + 1;
        b[e] = (b[e-1] * 2) + 3;
    }


    while (scanf("%lld %lld", &c, &d) != EOF)
    {
        printf("%lld\n", f(c,d));
    }
    return 0;
}

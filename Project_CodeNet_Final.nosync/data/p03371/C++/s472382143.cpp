#include <stdio.h>
int main ()
{
    int a, b, c, x, y, minxy, maxxy, p1, p2, p3;
    scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
    if (x > y)
    {
        minxy = y;
        maxxy = x;
    }
    else
    {
        minxy = x;
        maxxy = y;
    }
    p1 = c * minxy * 2 + (x - minxy) * a + (y - minxy) * b;
    p2 = maxxy * c * 2;
    p3 = a * x + b * y;
    if (p1 < p2)
    {
        if (p1 < p3) printf("%d", p1);
        else printf ("%d", p3);
    }
    else
    {
        if (p2 < p3) printf("%d", p2);
        else printf("%d", p3);
    }

    return 0;
}

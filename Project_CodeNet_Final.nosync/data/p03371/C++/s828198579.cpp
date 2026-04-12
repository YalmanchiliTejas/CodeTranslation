#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
    if (2 * c < a + b)
    {
        if (x<y)
        {
            printf("%d\n", 2 * c * x + (y - x) * min(b, 2 * c));
        }else
        {
            printf("%d\n", 2 * c * y + (x - y) * min(a, 2 * c));
        }
    }
    else
    {
        printf("%d\n", a * x + b * y);
    }
    return 0;
}
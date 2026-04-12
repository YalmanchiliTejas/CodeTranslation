#include <cstdio>
int n, h, a, m;
signed main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &h);
        if (h >= m) a++, m = h;
    }
    printf("%d", a);
}

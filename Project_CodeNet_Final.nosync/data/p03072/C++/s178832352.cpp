#include <cstdio>

int n, h, a, m;

signed main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h);
        if (h >= m) a++, m = h;
    }
    printf("%d", a);
}

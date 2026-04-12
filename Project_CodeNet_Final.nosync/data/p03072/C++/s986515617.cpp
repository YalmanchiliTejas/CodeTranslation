#include <cstdio>
int main()
{
    int n, h, t = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &h);
        if (h >= t) {++ans; t = h;}
    }
    printf("%d\n", ans);
    return 0;
}

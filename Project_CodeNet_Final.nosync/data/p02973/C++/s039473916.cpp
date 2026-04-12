#include <bits/stdc++.h>

using namespace std;

int n, a[100005], m, b[100005];

int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1; --i)
    {
        int tmp = upper_bound(b + 1, b + 1 + m, a[i]) - b;
        if (tmp == m + 1)
            b[++m] = a[i];
        else b[tmp] = a[i];
    }
    printf("%d\n", m);
    return 0;
}

#include <bits/stdc++.h>

#define int int64_t

using namespace std;

#define MAX 3005

int n, a[MAX], dp[MAX][MAX];

int f(int i, int j)
{
    if (i == j)
        return a[i] - a[i - 1];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] =
               max(a[j] - a[i] - f(i + 1, j) + a[i] - a[i - 1],
                   a[j - 1] - a[i - 1] - f(i, j - 1) + a[j] - a[j - 1]);
}

signed main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    printf("%lld\n", f(1, n) - (a[n] - f(1, n)));
}

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
    if (p == 0) return 1;
    if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
    return bin_pow(bin_pow(x, 2), p / 2);
}
ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}

const int N = 1010;
ll C[N][N];
ll dp[N];
ll f[N];
ll rf[N];
int n, a, b, c, d;

int main()
{
    for (int i = 0; i < N; i++)
        C[i][0] = C[i][i] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = mult(f[i - 1], i);
    rf[N - 1] = rev(f[N - 1]);
    for (int i = N - 1; i > 0; i--)
        rf[i - 1] = mult(rf[i], i);

    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

    dp[n] = 1;
    for (int x = a; x <= b; x++)
    {
        for (int y = 0; y <= n; y++)
        {
            ll w = 1;
            for (int i = 1; i <= d && i * x <= n - y; i++)
            {
                w = mult(w, C[y + i * x][x]);
                if (i < c) continue;
                dp[y] = add(dp[y], mult(dp[y + i * x], mult(w, rf[i])));
            }
        }
    }
    printf("%lld\n", dp[0]);

    return 0;
}
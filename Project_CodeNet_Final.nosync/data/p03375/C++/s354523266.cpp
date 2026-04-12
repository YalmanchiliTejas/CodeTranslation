#include <bits/stdc++.h>
#define oo 3005
using namespace std;
int n, m;
long long g[oo][oo], f[oo], ans, c[oo][oo];
inline long long fpow (long long x, int k, int mod)
{
    long long ret = 1;
    while(k) {if(k & 1) ret = ret * x % mod; k >>= 1; x = x * x % mod;}
    return ret;
}
void init ()
{
    for(int i = 0; i <= n; ++ i)
    c[i][0] = c[i][i] = 1;
    for(int i = 2; i <= n; ++ i)
    for(int j = 1; j < i; ++ j)
    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % m;
}
int main ()
{
    scanf("%d%d", &n, &m); init();
    for(int i = 0; i <= n; ++ i) g[0][i] = 1;
    for(int i = 1; i <= n; ++ i)
    for(int j = i; j <= n; ++ j)
    g[i][j] = (g[i - 1][j - 1] + g[i][j - 1] * (i + 1)) % m;
    for(int i = 0; i <= n; ++ i)
    {
        long long p = fpow(2, fpow(2, n - i, m - 1), m);
        long long x = fpow(2, n - i, m), y = 1;
        for(int j = 0; j <= i; ++ j)
        (f[i] += g[j][i] * p % m * y) %= m, y = y * x % m;
    }
    for(int i = 0; i <= n; ++ i)
    {
        if(i & 1) (ans -= c[n][i] * f[i]) %= m;
        else (ans += c[n][i] * f[i]) %= m;
    }
    printf("%lld", (ans + m) % m); return 0;
}
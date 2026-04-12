#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long

const int maxN = 1e7 + 2;
const int mod = 998244353;
int fac[maxN + 2], ifac[maxN + 2], pw2[maxN + 2];
int qpow(int a, int b)
{
    int ans = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1)
            ans = 1ll * ans * a % mod;
    return ans;
}
inline void Inc(int &x)
{
    x < 0 ? x += mod : 0;
}
void init(int N = 1e7)
{
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = (LL) fac[i - 1] * i % mod;
    ifac[N] = qpow(fac[N], mod - 2);
    for (int i = N - 1; i >= 0; --i)
        ifac[i] = (LL) ifac[i + 1] * (i + 1) % mod;
    pw2[0] = 1;
    for (int i = 1; i <= N; ++i)
        pw2[i] = pw2[i - 1] * 2ll % mod;
}
int C(int n, int m)
{
    if (n < m)
        return 0;
    return (LL) fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main()
{
    int n;
    scanf("%d",&n);
    init();
    int ans = qpow(3, n);
    for (int i = n / 2 + 1; i <= n; ++i)
        Inc(ans -= 2ll * C(n, i) * pw2[n - i] % mod);
    printf("%d\n", ans);
    return 0;
}

#include <iostream>
#include <cstdio>

constexpr static int ___mod = 1000000007;

long long fastExp(long long base, int index = ___mod - 2)
{
    long long ret = 1;
    for (; index; index >>= 1, base = base * base % ___mod)
        if (index & 1)
            ret = ret * base % ___mod;
    return ret;
}

int n, m, k;
long long fact[1000010], invFact[1000010];

void pre()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= n * m; ++i)
        fact[i] = fact[i - 1] * i % ___mod, invFact[i] = fastExp(fact[i]);
}

long long C(long long n, long long r)
{
    if (n < r || r < 0 || n < 0)
        return 0;
    return fact[n] * invFact[r] % ___mod * invFact[n - r] % ___mod;
}

int main()
{
    std::cin >> n >> m >> k;
    pre();
    long long ans = 0;
    for (int d = 1; d < n; ++d)
        ans = (ans + 1ll * d * (n - d) % ___mod * m % ___mod * m % ___mod * C(n * m - 2, k - 2) % ___mod) % ___mod;
    for (int d = 1; d < m; ++d)
        ans = (ans + 1ll * d * (m - d) % ___mod * n % ___mod * n % ___mod * C(n * m - 2, k - 2) % ___mod) % ___mod;
    std::cout << ans << std::endl;
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

const int MX = 200005, MOD = 1E9 + 7;

int m, n, k;
long long ans = 0, fct[MX], ivf[MX], inv[MX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> k;
    fct[0] = ivf[0] = 1;
    fct[1] = ivf[1] = inv[1] = 1;
    for (int i = 2; i <= m * n; i++)
    {
        fct[i] = fct[i - 1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        ivf[i] = ivf[i - 1] * inv[i] % MOD;
    }
    for (int i = 1; i <= m; i++)
    {
        int cur = i - (m + 1 - i);
        (ans += 1LL * n * n % MOD * i % MOD * cur) %= MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = i - (n + 1 - i);
        (ans += 1LL * m * m % MOD * i % MOD * cur) %= MOD;
    }
    (ans += MOD) %= MOD;
    cout << ans * fct[m * n - 2] % MOD * ivf[k - 2] % MOD * ivf[m * n - k] % MOD;
}

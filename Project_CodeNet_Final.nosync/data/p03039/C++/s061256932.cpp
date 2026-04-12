#include <iostream>
#include <stdio.h>
using namespace std;

const int MX = 200005, MOD = 1E9 + 7;

int m, n, k;
long long ans = 0, fct[MX], ivf[MX], inv[MX], d[MX], c[MX];
            //n giai thua, nghich dao modulo tung vi tri i, nghich dao modulo nhan lai voi nhau
void gener()
{
    fct[0] = ivf[0] = 1;
    fct[1] = ivf[1] = inv[1] = 1;
    for (int i = 2; i <= m * n; i++)
    {
        fct[i] = fct[i - 1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        ivf[i] = ivf[i - 1] * inv[i] % MOD;
    }
}

void solve()
{
    for (int i = 1; i <= max(m, n); i++)
    {
        c[i] = (c[i - 1] + (i - 1)) % MOD;
        d[i] = (c[i] + d[i - 1]) % MOD;
    }
    ans += d[m] * n % MOD * n % MOD;
    ans += d[n] * m % MOD * m % MOD;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    gener();
    solve();
    cout << ans * fct[m * n - 2] % MOD * ivf[k - 2] % MOD * ivf[m * n - k] % MOD;
}

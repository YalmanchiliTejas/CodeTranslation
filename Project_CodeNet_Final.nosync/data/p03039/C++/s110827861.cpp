#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll Sil(ll n)
{
    if (n == 0)
        return 1;
    ll w = 1;
    for (ll i = 1; i <= n; ++i)
        w = (w * i) % MOD;
    return w;
}

ll Pot(ll p, ll w)
{
    if (w == 0)
        return 1;
    if (w % 2 == 0)
    {
        ll pol = Pot(p, w / 2);
        return pol * pol % MOD;
    }
    return Pot(p, w - 1) * p % MOD;
}

ll Inv(ll n)
{
    return Pot(n, MOD - 2);
}

ll C(ll n, ll k)
{
    if (n == k || k == 0)
        return 1;
    return Sil(n) * (Inv(Sil(n - k)) * Inv(Sil(k)) % MOD) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll odp = 0;
    for (ll d = 1; d < m; ++d)
    {
        ll il = (n * n) % MOD;
        il = (il * (m - d)) % MOD;
        odp = (odp + il * d) % MOD;
    }
    for (ll d = 1; d < n; ++d)
    {
        ll il = (m * m) % MOD;
        il = (il * (n - d)) % MOD;
        odp = (odp + il * d) % MOD;
    }
    odp = (odp * C(n * m - 2, k - 2)) % MOD;
    cout << odp;
    return 0;
}

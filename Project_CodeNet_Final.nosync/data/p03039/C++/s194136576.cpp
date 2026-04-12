#include <iostream>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll fac[200005];
ll rfac[200005];

ll f(ll a, ll x)
{
    ll res = 1;

    while (x > 0)
    {
        if (x & 1)
            res = a * res % mod;

        a = a * a % mod;

        x >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r)
{
    if (n == 0 || r == 0)
        return 1;
    return fac[n] * rfac[r] % mod * rfac[n - r] % mod;
}

ll n, m, k;

int main()
{
    cin >> n >> m >> k;

    ll t = n * m;

    fac[0] = rfac[0] = 1;
    for (ll i = 1; i <= t; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        rfac[i] = f(fac[i], mod - 2);
    }

    ll ans = 0;
    ll tmp = 0;
    for (ll i = 1; i < n; i++)
    {
        tmp = (tmp + i * (n - i) % mod) % mod;
    }

    ans = tmp * m % mod * m % mod * nCr(n * m - 2, k - 2) % mod;

    tmp = 0;
    for (ll i = 1; i < m; i++)
    {
        tmp = (tmp + i * (m - i) % mod) % mod;
    }

    ans = (ans + tmp * n % mod * n % mod * nCr(n * m - 2, k - 2) % mod) % mod;

    cout << ans << endl;
}
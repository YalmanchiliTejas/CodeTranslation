#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, a, b, c, d;

const ll mod = 1e9 + 7;

ll fac[1005];
ll rfac[1005];
ll dp[1005][1005];

ll p(ll a, ll x)
{
    ll res = 1;

    while (x > 0)
    {
        if (x & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }

    return res;
}

int main()
{
    cin >> n >> a >> b >> c >> d;

    fac[0] = rfac[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        rfac[i] = p(fac[i], mod - 2);
    }
    dp[a - 1][0] = 1;

    for (ll i = a; i <= b; i++)
    {
        for (ll j = 0; j <= n; j++)
            dp[i][j] = dp[i - 1][j];
        for (ll k = c; k <= d; k++)
        {
            for (ll j = k * i; j <= n; j++)
            {

                dp[i][j] = (dp[i][j] + dp[i - 1][j - k * i] * fac[j] % mod * rfac[j - k * i] % mod * rfac[k] % mod * p(p(fac[i], k), mod - 2) % mod) % mod;
            }
        }
    }

    /* for (ll i = a; i <= b; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }
    }*/

    cout << dp[b][n] << endl;
}
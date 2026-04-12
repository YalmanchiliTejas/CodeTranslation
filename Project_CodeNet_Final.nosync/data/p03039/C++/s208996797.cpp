#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

ll mod = 1e9 + 7;

ll pow_mod(ll n, ll p)
{
    ll ret = 1;
    ll wk_n = n;
    ll wk_p = p;
    while (wk_p > 0)
    {
        if (wk_p % 2 == 0)
        {
            wk_n *= wk_n;
            wk_p /= 2;
            wk_n %= mod;
        }
        else
        {
            ret *= wk_n;
            wk_p--;
            ret %= mod;
        }
    }
    return ret;
}

ll cmb_mod(ll n, ll k)
{
    ll ret = 1;
    for (ll i = 1; i <= k; i++)
    {
        ret *= (n - i + 1);
        ret %= mod;
        ret *= pow_mod(i, mod - 2);
        ret %= mod;
        if (ret < 0)
        {
            ret += mod;
        }
    }
    return ret;
}

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll x_sum = 0;
    ll nnmod = (n * n) % mod;
    for (ll i = 0; i < m; i++)
    {
        x_sum += i * (m - i);
        x_sum %= mod;
    }
    x_sum *= nnmod;
    x_sum %= mod;

    ll y_sum = 0;
    ll mmmod = (m * m) % mod;
    for (ll i = 0; i < n; i++)
    {
        y_sum += i * (n - i);
        y_sum %= mod;
    }
    y_sum *= mmmod;
    y_sum %= mod;

    ll c = cmb_mod(n * m - 2, k - 2);
    ll sum = x_sum + y_sum;
    sum *= c;
    sum %= mod;

    cout << sum << endl;

    return 0;
}

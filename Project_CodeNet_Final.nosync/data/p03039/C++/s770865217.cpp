#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const int MAX_NM = 1000000;

ll factorial[MAX_NM];

void init_fact()
{
    factorial[0] = factorial[1] = 1;
    rep(i, 2, MAX_NM)
        factorial[i] = ((ll)i * factorial[i - 1]) % MOD;
}

ll power_mod(int x, int y)
{
    ll base = x;
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        y >>= 1;
    }
    return res;
}

map<ll, ll> inv_mod_map;
ll inv_mod(int x)
{
    if (inv_mod_map.count(x)) return inv_mod_map[x];
    else
        return inv_mod_map[x] = power_mod(x, MOD - 2);
}

ll comb(int n, int m)
{
    if (m == 0) return 1;
    if (n < m) return 0; 
    ll res = 1;
    res = (res * factorial[n]) % MOD;
    res = (res * inv_mod(factorial[m])) % MOD;
    res = (res * inv_mod(factorial[n - m])) % MOD;
    return res;
}

int main()
{
    init_fact();
    // cout << comb(4, 4) << endl;
    // cout << comb(4, 3) << endl;
    // cout << comb(4, 2) << endl;
    // cout << comb(4, 1) << endl;
    // cout << power_mod(2, 1) << endl;
    // cout << power_mod(2, 2) << endl;
    // cout << power_mod(2, 3) << endl;
    // cout << power_mod(2, 4) << endl;
    // cout << power_mod(2, 5) << endl;
    // cout << power_mod(2, 6) << endl;
    // cout << power_mod(2, 10) << endl;

    ll n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;
    rep(i, 0, n)
        ans = (ans + m * m * i * (n - i)) % MOD;
    rep(i, 0, m)
        ans = (ans + n * n * i * (m - i)) % MOD;

    ans = (ans * comb(n * m - 2, k - 2)) % MOD;
    cout << ans << endl;
    return 0;
}
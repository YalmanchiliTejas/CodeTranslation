#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 1000000007;
ll f[201010], rf[201010];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    for(int i = 1; i < 201010; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i < 201010; i++) rf[i] = inv(f[i]);
}
ll C(int n, int k) {
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * bc) % MOD;
}
//---------------------------------------------------------------------------------------------------
ll add(ll &a, ll b)
{
    a = (a+b)%MOD;
}
ll mul(ll &a, ll b)
{
    a = a * b % MOD;
}

int main()
{
    init();
    int n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(int d = 1; d <= m-1; d++)
    {
        ll tmp = 1;
        mul(tmp, m-d);
        mul(tmp, n);
        mul(tmp, n);
        mul(tmp, d);
        mul(tmp, C(n*m-2, k-2));
        add(ans, tmp);
    }
    for(int d = 1; d <= n-1; d++)
    {
        ll tmp = 1;
        mul(tmp, n-d);
        mul(tmp, m);
        mul(tmp, m);
        mul(tmp, d);
        mul(tmp, C(n*m-2, k-2));
        add(ans, tmp);
    }
    cout << (ans+MOD)%MOD << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 1e9+7;
const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
 
void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
long long C(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
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
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = 0;
    for(ll d = 1; d <= m-1; d++)
    {
        ll tmp = 1;
        mul(tmp, m-d);
        mul(tmp, n);
        mul(tmp, n);
        mul(tmp, d);
        add(ans, tmp);
    }
    for(ll d = 1; d <= n-1; d++)
    {
        ll tmp = 1;
        mul(tmp, n-d);
        mul(tmp, m);
        mul(tmp, m);
        mul(tmp, d);
        add(ans, tmp);
    }
    mul(ans, C(n*m-2, k-2));
    cout << (ans+MOD)%MOD << endl;
}

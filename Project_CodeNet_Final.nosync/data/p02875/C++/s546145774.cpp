#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll MOD = 998244353;
const ll N = 1e7+10;
ll f[N], rf[N];
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
    for(int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % MOD;
    rf[N - 1] = inv(f[N - 1]);
    for(int i = N-2; i >= 0; i--) rf[i] = (rf[i + 1] * (i + 1)) % MOD;
}
ll C(int n, int k) {
    if(n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!
    ll bc = (b * c) % MOD;
    return (a * bc) % MOD;
}

ll mod_pow(ll x, ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    init();
    int n;
    cin >> n;
    ll ans = mod_pow(3, n);
    ll tmp = 0;
    vector<ll> mod2(n/2+1);
    mod2[0] = 1;
    for(int i = 1; i < n/2+1; i++)
    {
        mod2[i] = mod2[i-1] * 2 % MOD;
    }
    for(int a = n/2 + 1; a <= n; a++)
    {
        tmp += C(n, a) * mod2[n-a] % MOD;
        tmp %= MOD;
    }
    tmp = tmp * 2 % MOD;
    ans = (ans - tmp + MOD) % MOD;
    cout << ans << endl;
}

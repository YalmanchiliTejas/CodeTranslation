#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll MOD = 1000000007;
ll mod_pow(ll a, ll n, ll mod) {
    ll res = 1, p = a % mod;
    while (n) {
        if (n & 1) res = res * p % mod;
        p = p * p % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> fact(n * m);
    fact[0] = 1;
    for (ll i = 1; i < n * m; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    ll ans = 0;
    rep(i, m) { (ans += i * (m - i) * n * n) %= MOD; }
    rep(i, n) { (ans += i * (n - i) * m * m) %= MOD; }
    (ans *= fact[n * m - 2]) %= MOD;
    (ans *= mod_pow(fact[n * m - k], MOD - 2, MOD)) %= MOD;
    (ans *= mod_pow(fact[k - 2], MOD - 2, MOD)) %= MOD;

    cout << ans << endl;

    return 0;
}
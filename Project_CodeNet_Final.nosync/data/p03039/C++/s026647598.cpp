#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, M, K, MOD = 1e9 + 7;
    cin >> N >> M >> K;
    ll ans = (N * N * (N - 1) / 2 - (N - 1) * N * (2 * N - 1) / 6) * M * M;
    ans += (M * M * (M - 1) / 2 - (M - 1) * M * (2 * M - 1) / 6) * N * N;
    ans %= MOD;
    vector<ll> f(200001, 1);
    rep(i, 200000) f[i + 1] = (f[i] * (i + 1)) % MOD;
    ans = (ans * f[N * M - 2]) % MOD;
    ans = (ans * mod_pow(f[K - 2], MOD - 2, MOD)) % MOD;
    ans = (ans * mod_pow(f[N * M  - K], MOD - 2, MOD)) % MOD;
    cout << ans << "\n";
}
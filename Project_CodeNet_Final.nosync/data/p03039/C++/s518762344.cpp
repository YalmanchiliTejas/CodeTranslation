#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll modpow(ll x, ll n, ll mod = MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll f[200005], fi[200005];

void init() {
    f[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    fi[200000] = modpow(f[200000], MOD - 2);
    for (int i = 200000; i > 0; i--) {
        fi[i - 1] = fi[i] * i % MOD;
    }
}

ll comb(ll r, ll c) {
    if (r < c) return 0;
    return f[r] * fi[c] % MOD * fi[r - c] % MOD;
}

ll calc(ll n, ll m, ll K) {
    ll res = 0;
    for (ll i = 1; i < n; i++) {
        ll hoge = i * (n - i) % MOD * m % MOD * m % MOD * comb(n * m - 2, K - 2) % MOD;
        (res += hoge) %= MOD;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    init();

    ll n, m, K;
    cin >> n >> m >> K;
    cout << (calc(n, m, K) + calc(m, n, K)) % MOD << endl;
    return 0;
}
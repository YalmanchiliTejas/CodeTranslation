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

ll f[3005], fi[3005];
ll dp[3005][3005];

ll comb(int r, int c, ll m) {
    return f[r] * fi[c] % m * fi[r - c] % m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll m;
    cin >> n >> m;
    
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % m;
    fi[n] = modpow(f[n], m - 2, m);
    for (int i = n; i >= 1; i--) fi[i - 1] = fi[i] * i % m;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * (j + 1) % m) % m;
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll tmp = 0;
        for (int j = 0; j <= i; j++) {
            (tmp += dp[i][j] * modpow(2, (n - i) * j, m)) %= m;
        }
        tmp = tmp * modpow(2, modpow(2, n - i, m - 1), m) % m;
        if (i % 2 == 0) (ans += comb(n, i, m) * tmp % m) %= m;
        else (ans += (m - comb(n, i, m) * tmp % m)) %= m;
    }
    cout << ans << endl;
    return 0;
}
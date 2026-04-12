#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

typedef long long ll;
const int N = 3e3 + 10;
ll n, mod, g[N][N], f[N], s[N], fac[N], inv[N], ans;

ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    for (; b; b >>= 1) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
    } return ret;
}

ll C(ll n, ll m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    cin >> n >> mod;
    fac[0] = inv[0] = inv[1] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * i % mod;
    rep(i, 2, n) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    rep(i, 2, n) inv[i] = inv[i] * inv[i - 1] % mod;
    rep(i, 0, n) {
        g[i][0] = 1;
        ll t1 = qpow(2, n - i, mod), t2 = qpow(2, n - i, mod - 1), cur = 1;
        rep(j, 0, i) {
            if (j) g[i][j] = (g[i - 1][j - 1] + (j + 1) * g[i - 1][j] % mod) % mod;
            (f[i] += g[i][j] * cur % mod) %= mod;
            (cur *= t1) %= mod;
        }
        (ans += (i & 1 ? -1ll : 1ll) * qpow(2, t2, mod) * C(n, i) % mod * f[i] % mod + mod) %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}
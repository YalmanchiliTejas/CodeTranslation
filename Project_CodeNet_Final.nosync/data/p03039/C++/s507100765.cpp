#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000 + 5;
const ll MOD = 1e9 + 7;

ll n, m, k;
ll fact[N], invFact[N], ans;

void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
    if (!b) g = a, x = 1, y = 0;
    else exgcd(b, a % b, g, y, x), y -= x * (a / b);
}

inline ll inv(ll a) {
    ll g, res, tmp;
    exgcd(a, MOD, g, res, tmp);
    return res % MOD;
}

inline void init() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
    invFact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 0; i--) invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

inline ll C(int n, int m) {
    // if (m == 0) return 1;
    if (m > n) return 0;
    return fact[n] * (invFact[m] * invFact[n - m] % MOD) % MOD;
}

int main() {
    init();
    scanf("%lld %lld %lld", &n, &m, &k);
    for (ll i = 1; i <= n; i++) {
        ll tmp = (n - i) * m % MOD * m % MOD * C(n * m - 2, k - 2) % MOD * i % MOD;
        (ans += tmp) %= MOD;
    }
    for (ll i = 1; i <= m; i++) {
        ll tmp = (m - i) * n % MOD * n % MOD * C(n * m - 2, k - 2) % MOD * i % MOD;
        (ans += tmp) %= MOD;
    }
    printf("%lld\n", ans % MOD);
    return 0;
}
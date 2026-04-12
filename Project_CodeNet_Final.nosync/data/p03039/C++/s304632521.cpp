// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii> 
using vec = vector<T>;

const ll INF = numeric_limits<ll>::max(),
         MOD = 1e9 + 7;

const int INF_i = numeric_limits<int>::max(),
          MAX = 1e6;

ll powm(ll a, ll n = MOD - 2) {
    ll res = 1;
    for (; n; a = (a * a) % MOD, n >>= 1)
        if (n & 1)
            res = (res * a) % MOD;
    return res;
}

ll C(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; i++) {
        (res *= n + 1 - i) %= MOD;
        (res *= powm(i)) %= MOD;
    }
    return res;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);

    ll n, m, k;
    cin >> n >> m >> k;
    ll res = 0;
    const ll a = C(n * m - 2, k - 2);
    for (int d = 0; d < n; d++) {
        ll ans = (m * m) % MOD;
        (ans *= ((n - d) * a) % MOD) %= MOD;
        (res += (ans * d) % MOD) %= MOD;
    }
    for (int d = 0; d < m; d++) {
        ll ans = (n * n) % MOD;
        (ans *= ((m - d) * a) % MOD) %= MOD;
        (res += (ans * d) % MOD) %= MOD;
    }
    cout << res << '\n';

}
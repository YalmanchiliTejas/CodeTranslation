#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <random>
#include <tuple>
#include <cstdint>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;

const int INF = 1 << 30;
const int MOD = 1e9 + 7;

const int MAX = 210000;
ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

ll modpow(ll a, ll n, ll MOD) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    ll n, m, k; cin >> n >> m >> k;
    COMinit();

    // ((x_dist * n * n + y_dist * m * m)) * com(n*m-2, k-2)
    ll x_dist = 0;
    rep(i, m) {
        if (i < m-1) {
            x_dist += ll(1 + m-i-1) * ll(m-i-1) / 2;
            x_dist %= MOD;
        }
    }
    ll y_dist = 0;
    rep(i, n) {
        if (i < n-1) {
            y_dist += ll(1 + n-i-1) * ll(n-i-1) / 2;
            y_dist %= MOD;
        }
    }
    
    x_dist *= n;
    x_dist %= MOD;
    x_dist *= n;
    x_dist %= MOD;

    y_dist *= m;
    y_dist %= MOD;
    y_dist *= m;
    y_dist %= MOD;

    ll ans = (x_dist + y_dist) % MOD * COM(n*m-2, k-2) % MOD;

    cout << ans << endl;


    return 0;
}
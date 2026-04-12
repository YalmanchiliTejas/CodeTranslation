#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 1000000000000000007LL;
constexpr int inf = 1000000007;

/*
    nCk, nPk, 階乗をmodをとりつつ求めるライブラリ
*/
template <int MAX_N = 100000, long long MOD = 1000000007LL>
class Combination {
    array<long long, MAX_N + 1> _fact;
    array<long long, MAX_N + 1> _fact_inv;

public:
    // xの逆元
    // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
    long long inv(long long a) const {
        long long b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);

            u -= t * v;
            swap(u, v);
        }
        u %= MOD;
        if (u < 0)
            u += MOD;
        return u;
    }
    // n!
    long long fact(long long n) const {
        return _fact[n];
    }
    // 1 / n!
    long long fact_inv(long long n) const {
        return _fact_inv[n];
    }
    // nPk
    long long perm(long long n, long long k) const {
        return fact(n) * fact_inv(n - k) % MOD;
    }
    // nCk
    long long comb(long long n, long long k) const {
        return perm(n, k) * fact_inv(k) % MOD;
    }

    Combination() : _fact{}, _fact_inv{} {
        _fact[0] = _fact[1] = 1LL;
        for (int i = 2; i <= MAX_N; ++i) {
            _fact[i] = _fact[i - 1] * i % MOD;
        }
        _fact_inv[MAX_N] = inv(_fact[MAX_N]);
        for (int i = MAX_N - 1; i >= 0; --i) {
            _fact_inv[i] = _fact_inv[i + 1] * (i + 1) % MOD;
        }
    }
};

constexpr ll mod = inf;
Combination<200000> cm;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    ll ans = 0;
    for (ll d = 1; d <= n - 1; ++d) {
        ans += (n - d) * m * m * d;
        ans %= mod;
    }
    for (ll d = 1; d <= m - 1; ++d) {
        ans += (m - d) * n * n * d;
        ans %= mod;
    }
    cout << ans * cm.comb(n * m - 2, k - 2) % mod << endl;
    return 0;
}
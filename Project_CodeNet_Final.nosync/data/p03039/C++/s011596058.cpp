#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

class Enumeration {
public:
  explicit Enumeration(int n, uint64_t m) : mod(m), fact(n), inv(n), finv(n) {
    fact[0] = finv[0] = inv[1] = 1;
    for (int i = 2; i < n; ++i) inv[i] = mod - inv[mod % i] * (mod / i) % mod;
    for (int i = 1; i < n; ++i) {
      fact[i] = fact[i - 1] * i % mod;
      finv[i] = finv[i - 1] * inv[i] % mod;
    }
  }
  uint64_t operator()(int n, int k) {
    if (n < k || n < 0 || k < 0) return 0;
    return fact[n] * finv[n - k] % mod * finv[k] % mod;
  }
  uint64_t modpow(uint64_t x, uint64_t e) {
    uint64_t res = 1;
    while (e > 0) {
      if (e & 1) res = res * x % mod;
      x = x * x % mod;
      e >>= 1;
    }
    return res;
  }

private:
  uint64_t mod;
  vector<uint64_t> fact, inv, finv;
};

int main() {

  ll n, m, k;
  cin >> n >> m >> k;

  Enumeration e(n * m, MOD);
  ll ans = 0;
  for (ll i = 1; i < m; ++i) {
    ll j = (m - i) * n * n % MOD;
    ans = (ans + i * j) % MOD;
  }
  for (ll i = 1; i < n; ++i) {
    ll j = (n - i) * m * m % MOD;
    ans = (ans + i * j) % MOD;
  }
  cout << ans * e(n * m - 2, k - 2) % MOD << '\n';

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
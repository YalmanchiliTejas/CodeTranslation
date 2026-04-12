#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

const ll MOD = 1e9 + 7;

ll power(ll x, ll e) {
  ll v = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) {
      v = v * x % MOD;
    }
    x = x * x % MOD;
  }
  return v;
}

ll inverse(ll x) {
  return power(x, MOD - 2);
}

ll arithmeticSum(ll n, ll a, ll d) {
  static ll inv2 = inverse(2);
  return n * (2 * a % MOD + (n - 1) * d % MOD) % MOD * inv2 % MOD;
}

vector<ll> fact, factInv;
void initFact(int N) {
  fact.resize(N + 1);
  factInv.resize(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }
  factInv[N] = inverse(fact[N]);
  for (int i = N - 1; i >= 0; i--) {
    factInv[i] = factInv[i + 1] * (i + 1) % MOD;
  }
}

ll choose(int n, int k) {
  if (k > n) {
    return 0;
  } else {
    return fact[n] * factInv[k] % MOD * factInv[n - k] % MOD;
  }
}

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  initFact(2000010);
  ll N, M, K;
  while (cin >> N >> M >> K) {
    ll res = 0;
    ll a = 0;
    for (int i = 0; i < N; i++) {
      a += arithmeticSum(N - i, i + 1, 1) - (i + 1) * (N - i) % MOD + MOD;
      a %= MOD;
    }
    a = a * M % MOD * M % MOD;
    ll b = 0;
    for (int i = 0; i < M; i++) {
      b += arithmeticSum(M - i, i + 1, 1) - (i + 1) * (M - i) % MOD + MOD;
      b %= MOD;
    }
    b = b * N % MOD * N % MOD;
    res = (res + a) % MOD;
    res = (res + b) % MOD;
    res = res * choose(N * M - 2, K - 2) % MOD;
    cout << res << endl;
  }
  return 0;
}

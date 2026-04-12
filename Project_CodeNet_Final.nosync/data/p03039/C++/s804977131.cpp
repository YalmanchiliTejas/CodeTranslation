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
  int N, M, K;
  while (cin >> N >> M >> K) {
    ll res = 0;
    for (int d = 1; d < N; d++) {
      ll ways = M * M % MOD * (N - d) % MOD;
      ll cost = d * ways % MOD;
      res = (res + cost) % MOD;
    }
    for (int d = 1; d < M; d++) {
      ll ways = N * N % MOD * (M - d) % MOD;
      ll cost = d * ways % MOD;
      res = (res + cost) % MOD;
    }
    res = res * choose(N * M - 2, K - 2) % MOD;
    cout << res << endl;
  }
  return 0;
}

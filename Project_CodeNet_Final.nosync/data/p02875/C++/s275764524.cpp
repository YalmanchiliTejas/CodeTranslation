#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (size_t i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (size_t i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

const i64 mod = 998244353;
i64 fact_memo[10000001];
i64 fact(i64 x) {
  if (x == 0) return 1;
  if (fact_memo[x]) return fact_memo[x];
  return fact_memo[x] = x * fact(x - 1) % mod;
}
i64 ipow(i64 a, i64 b) {
  return (b & 1 ? a : 1) * (b > 1 ? ipow(a * a % mod, b >> 1) : 1) % mod;
}
i64 inv(i64 x) {
  return ipow(x, mod - 2);
}
i64 fact_inv(i64 x) {
  return inv(fact(x));
}
i64 perm(i64 a, i64 b) {
  return fact(a) * fact_inv(a - b) % mod;
}
i64 conb(i64 a, i64 b) {
  return perm(a, b) * fact_inv(b) % mod;
}
i64 n;
int main() {
  cin >> n;
  fact_memo[0] = 1;
  for (i64 i = 1; i <= n; ++i) {
    fact_memo[i] = fact_memo[i - 1] * i % mod;
  }
  i64 sum = ipow(3, n), sub = 0;
  for (i64 i = n / 2 + 1; i <= n; ++i) {
    (sub += conb(n, i) * ipow(2, n - i) % mod) %= mod;
  }
  i64 ans = (sum - 2 * sub + 2 * mod) % mod;
  cout << ans << endl;
  return 0;
}

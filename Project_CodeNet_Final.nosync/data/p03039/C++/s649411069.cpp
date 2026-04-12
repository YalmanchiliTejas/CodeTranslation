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
#include <cassert>
#include <utility>
#include <functional>
#include <bitset>
#include <cstdint>

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

const i64 mod = 1e9 + 7;
i64 fact_memo[200001];
i64 fact(i64 x) {
  if (x == 0) return 1;
  if (fact_memo[x]) return fact_memo[x];
  return fact_memo[x] = x * fact(x - 1) % mod;
}
i64 ipow(i64 a, i64 b) {
  return (b & 1 ? a : 1) * (b > 1 ? ipow(a * a % mod, b >> 1) : 1) % mod;
}
i64 fact_inv(i64 x) {
  return ipow(fact(x), mod - 2);
}
i64 perm(i64 a, i64 b) {
  return fact(a) * fact_inv(a - b) % mod;
}
i64 conb(i64 a, i64 b) {
  return fact(a) * fact_inv(b) % mod * fact_inv(a - b) % mod;
}

i64 n, m, k;
int main() {
  cin >> n >> m >> k;

  i64 ans = 0;
  for (i64 i = 0; i < 2; ++i) {
    for (i64 d = 1; d < m; ++d) {
      ans = (ans + 
          (m - d) * n * n % mod * conb(n * m - 2, k - 2) % mod * d % mod)
          % mod;
    }
    swap(n, m);
  }
  cout << ans << '\n';
  return 0;
}

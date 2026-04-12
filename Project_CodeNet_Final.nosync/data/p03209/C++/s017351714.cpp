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

i64 n, x;
array<i64, 51> ps, pbs;

i64 f(i64 lv, i64 x) {
  if (lv == 0) return 1;
  if (x <= 1) return 0;
  if (x < pbs[lv] / 2 + 1) return f(lv - 1, x - 1);
  if (x == pbs[lv] / 2 + 1) return ps[lv - 1] + 1;
  if (x < pbs[lv]) return ps[lv - 1] + 1 + f(lv - 1, x - pbs[lv - 1] - 2);
  /* if (x == pbs[lv]) */ return ps[lv];
}

int main() {
  cin >> n >> x;
  ps[0] = pbs[0] = 1;
  for (i64 lv = 1; lv <= n; ++lv) {
    ps[lv] = 2 * ps[lv - 1] + 1;
    pbs[lv] = 2 * pbs[lv - 1] + 3;
  }
  cout << f(n, x) << endl;
  return 0;
}

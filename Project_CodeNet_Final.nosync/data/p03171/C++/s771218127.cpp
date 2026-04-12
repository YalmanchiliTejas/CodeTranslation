#include <algorithm>
#include <bitset>
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
/* clang-format on */

int N;
ll a[3010];

bool done[3010][3010];
ll dp[3010][3010];

ll solve(int l, int r) {
  if (l > r) return 0;
  if (done[l][r]) return dp[l][r];
  ll& res = dp[l][r];
  int turn = (l + r) % 2;
  if (turn != N % 2) {
    ll resL = solve(l + 1, r) + a[l];
    ll resR = solve(l, r - 1) + a[r];
    res = max(resL, resR);
  } else {
    ll resL = solve(l + 1, r) - a[l];
    ll resR = solve(l, r - 1) - a[r];
    res = min(resL, resR);
  }
  done[l][r] = true;
  return res;
}

int main() {
  while (cin >> N) {
    for (int i = 0; i < N; i++) cin >> a[i];
    memset(done, false, sizeof(done));
    cout << solve(0, N - 1) << endl;
  }
  return 0;
}

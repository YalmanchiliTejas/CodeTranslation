#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdint>
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

int main() {
#ifdef DEBUG
  ifstream ifs("in.txt");
  cin.rdbuf(ifs.rdbuf());
#endif
  string N;
  int K;
  while (cin >> N >> K) {
    int sz = N.size();
    vec<ll, 3> dp = make_v(sz + 1, 2, K + 2, 0ll);
    dp[0][0][0] = 1;
    for (int i = 0; i < sz; i++) {
      int cur = N[i] - '0';
      for (int less = 0; less < 2; less++) {
        for (int k = 0; k <= K; k++) {
          for (int d = 0; d < 10; d++) {
            if (d <= cur || less) {
              dp[i + 1][(d < cur) | less][k + (d != 0)] += dp[i][less][k];
            }
          }
        }
      }
    }
    cout << (dp[sz][0][K] + dp[sz][1][K]) << endl;
  }
  return 0;
}

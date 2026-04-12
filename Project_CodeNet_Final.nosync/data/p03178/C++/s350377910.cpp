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

const int MOD = 1000000007;
int dp[10010][102][2];

string S;
vector<int> N;
int D;

int solve(int dig, int m, bool less) {
  if (dig >= N.size()) {
    return (m == 0);
  }
  if (dp[dig][m][less] != -1) return dp[dig][m][less];

  int res = 0;
  for (int d = 0; d < 10; d++) {
    if (less || (d <= N[dig])) {
      res = (res + solve(dig + 1, (m + d) % D, less || (d < N[dig]))) % MOD;
    }
  }

  return dp[dig][m][less] = res;
}

int main() {
  while (cin >> S >> D) {
    N.clear();
    for (int i = 0; i < S.size(); i++) N.push_back(S[i] - '0');

    memset(dp, -1, sizeof(dp));
    int res = solve(0, 0, false);
    res = (res - 1 + MOD) % MOD;

    cout << res << endl;
  }
  return 0;
}

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define REP(i, n) FOR(i, 0, n)
#define REP1(i, n) FOR(i, 1, int(n) + 1)
#define RREP(i, n) RFOR(i, 0, n)
#define RREP1(i, n) RFOR(i, 1, int(n) + 1)
#define ALL(c) begin(c), end(c)

int _ = (
#ifndef LOCAL
    std::cin.tie(nullptr), std::ios::sync_with_stdio(false),
#endif
    std::cout.precision(10), std::cout.setf(std::ios::fixed));

using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <typename T> using vec = std::vector<T>;
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vec<vec<char>> a(H, vec<char>(W));
  REP(i, H) REP(j, W) cin >> a[i][j];

  unordered_set<int> sy;
  REP(y, H) {
    REP(x, W) {
      if (a[y][x] == '#') {
        sy.emplace(y);
        break;
      }
    }
  }
  unordered_set<int> sx;
  REP(x, W) {
    REP(y, H) {
      if (a[y][x] == '#') {
        sx.emplace(x);
        break;
      }
    }
  }

  REP(y, H) {
    if (sy.count(y) == 0) {
      continue;
    }
    REP(x, W) {
      if (sx.count(x) == 0) {
        continue;
      } else {
        cout << a[y][x];
      }
    }
    cout << endl;
  }
  return 0;
}

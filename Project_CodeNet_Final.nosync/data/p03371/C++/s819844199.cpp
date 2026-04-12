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
  ll A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  if (2 * C > A + B) {
    cout << A * X + B * Y << endl;
    return 0;
  }

  ll answer = 0;
  for (ll i = 0; i <= 100'100; i++) {
    answer = 2 * C * i;
    if (i == X) {
      const ll rest = Y - i;
      answer += min(B * rest, 2 * C * rest);
      break;
    }
    if (i == Y) {
      const ll rest = X - i;
      answer += min(A * rest, 2 * C * rest);
      break;
    }
  }
  cout << answer << endl;
  return 0;
}

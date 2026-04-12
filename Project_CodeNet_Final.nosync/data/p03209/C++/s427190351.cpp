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
using ld = long double;
// constexpr auto mod = 1000000007;
using namespace std;

vector<ll> d, p;

ll solve(ll N, ll X) {
  if (N == 0) {
    return X <= 0 ? 0 : 1;
  }
  else if (X <= 1 + d[N - 1]) {
    return solve(N - 1, X - 1);
  }
  else if (X == 2 + d[N - 1]){
    return 1 + p[N - 1];
  }
  else if (X <= 2 + 2 * d[N - 1]) {
    return 1 + p[N - 1] + solve(N - 1, X - 2 - d[N - 1]);
  }
  else if (X == 3 + 2 * d[N - 1]) {
    return 1 + 2 * p[N - 1];
  }
}

int main() {
  ll N, X;
  cin >> N >> X;

  d.resize(N + 1), p.resize(N + 1);
  d[0] = p[0] = 1;
  REP(i, N) {
    d[i + 1] = 2 * d[i] + 3;
    p[i + 1] = 2 * p[i] + 1;
  }
  cout << solve(N, X) << endl;

  return 0;
}

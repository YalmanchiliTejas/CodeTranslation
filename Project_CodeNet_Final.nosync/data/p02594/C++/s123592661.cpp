#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using f64 = double;

#define FOR(i, s, n) for (size_t i = (s); i < (size_t)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) (v).begin(), (v).end()

template <typename T, typename U>
inline bool chmax(T &a, U b) {
  return a < b ? (a = b, true) : false;
}

template <typename T, typename U>
inline bool chmin(T &a, U b) {
  return a > b ? (a = b, true) : false;
}

int main() {
  int X;
  cin >> X;
  cout << (X >= 30 ? "Yes" : "No");
  return 0;
}

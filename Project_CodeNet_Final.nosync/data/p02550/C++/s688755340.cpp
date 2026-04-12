// 2020-09-19 21:41:40
// clang-format off
#include <bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
// #include <atcoder/convolution>
// #include <atcoder/dsu>
// #include <atcoder/fenwicktree>
// #include <atcoder/lazysegtree>
// #include <atcoder/math>
// #include <atcoder/maxflow>
// #include <atcoder/mincostflow>
// #include <atcoder/modint>
// #include <atcoder/scc>
// #include <atcoder/segtree>
// #include <atcoder/string>
// #include <atcoder/twosat>
// #include <atcoder/all>
// using namespace atcoder;

// clang-format on
const int MX = 100010;
bool visited[MX + 10];
void answer() {
  ll n, x, m;
  cin >> n >> x >> m;
  if (n < 1000000) {
    ll ans = 0, cur = x;
    rep(i, n) {
      ans += cur;
      cur = (cur * cur) % m;
    }
    cout << ans << '\n';
    return;
  }
  ll cur = x;
  ll loop = -1;
  for (int i = 0;; i++) {
    if (visited[cur]) {
      loop = cur;
      break;
    }
    visited[cur] = true;
    cur = (cur * cur) % m;
  }
  cur = x;
  ll ans = 0, rem = n;
  {
    ll now = 0, i = 0;
    while (cur != loop) {
      now += cur;
      cur = (cur * cur) % m;
      i++;
    }
    ans += now;
    rem -= i;
  }
  {
    ll tot = cur, i = 1;
    cur = (cur * cur) % m;
    while (cur != loop) {
      tot += cur;
      cur = (cur * cur) % m;
      i++;
    }
    ans += tot * (rem / i);
    rem %= i;
  }
  rep(i, rem) {
    ans += cur;
    cur = (cur * cur) % m;
  }
  cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
// 2020-09-20 13:10:15
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
void answer() {
  ll n, X, m;
  cin >> n >> X >> m;
  int cnt = 0;
  ll tot = 0;
  vector<int> mp(m + 10, -1);
  vector<ll> a;
  ll x = X;
  while (mp[x] == -1) {
    a.push_back(x);
    tot += x;
    mp[x] = cnt++;
    x = x * x % m;
  }
  if (n <= cnt) {
    ll ans = 0;
    rep(i, n) ans += a[i];
    cout << ans << '\n';
    return;
  }
  ll c = tot;
  rep(i, mp[x]) c -= a[i];
  ll ans = tot;
  n -= cnt;
  ans += n / (cnt - mp[x]) * c;
  n %= cnt - mp[x];
  rep(i, n) ans += a[i + mp[x]];
  cout << ans << '\n';
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
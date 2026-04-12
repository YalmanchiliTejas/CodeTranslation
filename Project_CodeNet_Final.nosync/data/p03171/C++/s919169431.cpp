#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define REP(i, a) for (ll i(0), _##i(a); i < _##i; ++i)
#define FOR(i, a, b) for (ll i(a), _##i(b); i <= _##i; ++i)

#ifdef LOCAL
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(__VA_ARGS__, _FE_6, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1)              \
  (MACRO, __VA_ARGS__)
#define watch(x) cerr << "\033[1;32m" #x " = \033[1;34m" << (x) << "\033[0m; ";
#define debug(...)                                                             \
  cerr << "\033[2;31mLine " << __LINE__ << ": \033[0m";                        \
  FOR_EACH_MACRO(watch, __VA_ARGS__)                                           \
  cerr << endl
#else
#define debug(...)
#endif

using namespace std;

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decltype(begin(declval<T>())),
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  for (auto it = begin(c); it != end(c); ++it)
    os << (it == begin(c) ? "" : ", ") << *it;
  return os << ']';
}
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &x : a) cin >> x;

  const ll INF = 1ll << 62;
  vector<vector<pair<ll,ll>>> dp(n, vector<pair<ll,ll>>(n, {INF, INF}));
  function<pair<ll,ll>(int,int)> bt = [&](int l, int r) -> pair<ll,ll>{
    if (l == r) {
      return {a[l], 0};
    }
    auto &res = dp[l][r];
    if (res != make_pair(INF, INF)){
      return res;
    }
    auto go1 = bt(l + 1, r);
    auto go2 = bt(l, r - 1);
    ll x = a[l] + go1.S; 
    ll y = a[r] + go2.S;
    if (x > y){
      return res = {x, go1.F};
    } else {
      return res = {y, go2.F};
    }
  };

  auto ans = bt(0, n - 1);
  cout << ans.F - ans.S << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }
}

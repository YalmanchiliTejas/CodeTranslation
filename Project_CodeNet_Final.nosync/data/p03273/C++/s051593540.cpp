#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define reps(i, m, n) for (int i = m; i <= n; ++i)

using i64 = long long;
using pii = pair<i64, i64>;

template<class A, class B>inline bool chmax(A &a, const B &b){return b > a ? a = b,1 : 0;}
template<class A, class B>inline bool chmin(A &a, const B &b){return b < a ? a = b,1 : 0;}

constexpr int INF = 0x3f3f3f3f;
constexpr i64 LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int MOD = int(1e9) + 7;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int h, w;
  cin >> h >> w;

  string a[128];
  vector<bool> side_all(h+1, false);
  vector<bool> ver_all(w+1, true);

  rep(i, h) {
    cin >> a[i];
    side_all[i] = all_of(all(a[i]), [](char c) { return c == '.'; });
  }

  rep(j, w) {
    rep(i, h) {
      if (a[i][j] == '#') ver_all[j] = false;
    }
  }

  rep(i, h) {
    rep(j, w) {
      if (side_all[i]) break;
      if (ver_all[j]) continue;
      cout << a[i][j];
    }
    if (!side_all[i]) cout << "\n";
  }

  return 0;
}
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

typedef pair<ll, ll> P;

#define bit(n) (1LL << (n))

//#define int long long

#define all(v) v.begin(), v.end()
#define sortAl(v) sort(all(v))
#define sortAlr(v)          \
  sort(v.begin(), v.end()); \
  reverse(v.begin(), v.end())

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)

template <class T>
inline void chmax(T &a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T &a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();

  // dp[桁数][k(1〜9を何個含むか)][未満フラグ]
  vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 2, vector<ll>(2)));
  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      int D = s[i] - '0';

      // ============================================ この桁を0にする場合
      //未満フラグが立っているものはそのまま引き継ぎ
      dp[i + 1][j][1] += dp[i][j][1];

      if (D == 0) {
        // 未満フラグOffを引き継ぎ
        dp[i + 1][j][0] += dp[i][j][0];
      } else {
        // 該当桁の値Dが1以上なら未満フラグOff→Onで引き継ぎ
        dp[i + 1][j][1] += dp[i][j][0];
      }
      // ============================================

      // ============================================ この桁を0以外にする場合([k]が変化する)
      for (int h = 1; h <= 9; h++) {
        // 未満フラグOnのものはそのまま引き継ぎ
        dp[i + 1][j + 1][1] += dp[i][j][1];

        if (h < D) {
          // 未満フラグOnで引き継ぎ
          dp[i + 1][j + 1][1] += dp[i][j][0];
        } else if (h == D) {
          // 未満フラグOffで引き継ぎ
          dp[i + 1][j + 1][0] += dp[i][j][0];
        }
      }
      // ============================================
    }
  }
  ll ans = dp[n][k][0] + dp[n][k][1];
  cout << ans << endl;
}
#include <bits/stdc++.h>
#define GET_REP(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_REP(__VA_ARGS__, irep, _rep)(__VA_ARGS__)
#define rep1(...) GET_REP(__VA_ARGS__, irep1, _rep1)(__VA_ARGS__)
#define _rep(i, n) irep (i, 0, n)
#define _rep1(i, n) irep1(i, 1, n)
#define irep(i, a, n) for (int i = a; i < (int)(n); ++i)
#define irep1(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rrep1(i, n) for (int i = (int)(n); i >= 1; --i)
#define allrep(X, x) for (auto &&X : x)
#define all(x) begin(x), end(x)
#define debug(x) cout << #x " => " << (x) << endl
#ifdef LOCAL
  #include "../../Lib/cout_container.hpp"
#endif
using lint = long long;
constexpr int MOD = (int)1e9 + 7;
constexpr double EPS = 1e-9;
using namespace std;
namespace { struct INIT { INIT() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } INIT; }

int main(void) {
  string n;
  int k;
  cin >> n >> k;
  vector<vector<vector<lint>>> dp(n.length() + 1, vector<vector<lint>>(2, vector<lint>(k + 2)));
  dp[0][1][0] = 1;
  rep (i, n.length()) {
    rep (j, k + 1) {
      dp[i + 1][0][j] += dp[i][0][j];
      dp[i + 1][0][j + 1] += dp[i][0][j] * 9;
      if (n[i] == '0') {
        dp[i + 1][1][j] += dp[i][1][j];
      } else {
        dp[i + 1][0][j] += dp[i][1][j];
        dp[i + 1][1][j + 1] += dp[i][1][j];
        dp[i + 1][0][j + 1] += dp[i][1][j] * (n[i] - '0' - 1);
      }
    }
  }
  cout << dp.back()[0][k] + dp.back()[1][k] << endl;
  return 0;
}
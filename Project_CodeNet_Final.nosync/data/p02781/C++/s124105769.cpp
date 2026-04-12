#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
using ll = long long;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  vl n(s.size());
  rep(i, s.size()) n[i] = s[i] - '0';
  ll k;
  cin >> k;
  vvvl dp(n.size(), vvl(k + 1, vl(2, 0)));
  rep(d, 10) {
    if (n[0] == d) {
      dp[0][1][0]++;
    } else if (d < n[0]) {
      if (d == 0)
        dp[0][0][1]++;
      else
        dp[0][1][1]++;
    }
  }
  REP(i, 1, n.size()) {
    rep(j, k + 1) {
      rep(d, 10) {
        if (n[i] == d) {
          if (d == 0) {
            dp[i][j][0] += dp[i - 1][j][0];
            dp[i][j][1] += dp[i - 1][j][1];
          } else {
            if (0 < j) {
              dp[i][j][0] += dp[i - 1][j - 1][0];
              dp[i][j][1] += dp[i - 1][j - 1][1];
            }
          }
        } else if (d < n[i]) {
          if (d == 0) {
            dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][0];
          } else {
            if (0 < j) {
              dp[i][j][1] += dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
            }
          }
        } else {
          if (0 < j) {
            dp[i][j][1] += dp[i - 1][j - 1][1];
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(l, 2) { ans += dp[n.size() - 1][k][l]; }
  cout << ans << endl;
  return 0;
}

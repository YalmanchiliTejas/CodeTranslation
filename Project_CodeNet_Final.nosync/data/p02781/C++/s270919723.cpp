#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int dp[101][5][2];
int main() {

  string s;
  int k;
  cin >> s >> k;
  int n = (int)s.size();
  dp[0][0][1] = 1;
  rep(i, 0, n) {
    rep(j, 0, k + 1) {
      rep(giri, 0, 2) {
        int x = s[i] - '0';
        int mx = (giri ? x : 9);
        rep(n, 0, mx + 1) {
          int girigiri = giri && (n == mx);
          if (n != 0)
            dp[i + 1][j + 1][girigiri] += dp[i][j][giri];
          else
            dp[i + 1][j][girigiri] += dp[i][j][giri];
        }
      }
    }
  }
  cout << dp[n][k][0] + dp[n][k][1] << endl;
  return 0;
}
#include <bits/stdc++.h>
#include <iomanip>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll dp[200001][2][3];

int main() {
  int n;
  cin >> n;
  int eo = 2 + n%2;
  ll a;
  rep(k, n) rep(i, 2) rep(j, eo) dp[k][i][j] = 0;
  cin >> a;
  dp[0][1][0] = a + 1000000001;
  for (int i=1; i<n-1; i++) {
    cin >> a;
    rep(j, eo) {
      dp[i][0][j] = dp[i-1][1][j];
      if (j > 0) dp[i][0][j] = max(dp[i][0][j], dp[i-1][0][j-1]);
      dp[i][1][j] = dp[i-1][0][j] + a + 1000000001;
    }
  }
  dp[n-1][0][eo-1] = max(dp[n-2][0][eo-2], dp[n-2][1][eo-2]);
  cin >> a;
  dp[n-1][1][eo-1] = dp[n-2][0][eo-1] + a + 1000000001;
  ll ans = max(dp[n-1][0][eo-1], dp[n-1][1][eo-1]) - 1000000001 * ll(n/2);
  cout << ans << endl;
  return 0;
}
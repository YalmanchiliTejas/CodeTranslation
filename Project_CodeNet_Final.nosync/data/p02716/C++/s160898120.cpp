#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int k = n%2+1;
  ll dp[200005][4];
  for(int i = 0; i < n+1; i++) {
    for(int j = 0; j < k+1; j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < k+1; j++) {
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
      ll now = dp[i][j];
      if ((i+j)%2 == 0) now += a[i];
      dp[i+1][j] = max(dp[i+1][j], now);
    }
  }

  ll ans = dp[n][k];
  cout << ans << endl;
  return 0;
}
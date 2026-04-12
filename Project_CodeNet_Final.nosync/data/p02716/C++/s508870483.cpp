#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll INF = 1e17;

int main(){
  int n;
  cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  vector<vector<ll>> dp(n+1,vector<ll>(3,-INF));
  dp[0][1] = 0; dp[1][1] = 0; dp[1][2] = a[0];
  for(int i = 2; i <= n; i++) {
    if(i % 2 == 0) {
      dp[i][0] = dp[i-1][1];
      dp[i][1] = dp[i-1][2];
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
    }
    dp[i][0] = max(dp[i][0],dp[i-2][0]+a[i-1]);
    dp[i][1] = max(dp[i][1],dp[i-2][1]+a[i-1]);
    dp[i][2] = max(dp[i][2],dp[i-2][2]+a[i-1]);
  }
  cout << dp[n][1] << endl;
  return 0;
}

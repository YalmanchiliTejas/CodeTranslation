#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  string s;
  cin >> s;
  int l = s.length();
  int k;
  cin >> k;
  vector<vector<vector<ll>>> dp(l+1,vector<vector<ll>>(k+2,vector<ll>(2,0)));
  dp[0][0][0] = 1;
  rep(i,l) {
    rep(j,k+1) {
      if(s[i] == '0') {
        dp[i+1][j][0] = dp[i][j][0];
      } else {
        dp[i+1][j+1][0] += dp[i][j][0];
        dp[i+1][j][1] += dp[i][j][0];
        dp[i+1][j+1][1] += (ll)(s[i]-'1') * dp[i][j][0]; 
      }
      dp[i+1][j][1] += dp[i][j][1];
      dp[i+1][j+1][1] += dp[i][j][1] * 9;
    }
  }
  cout << dp[l][k][0] + dp[l][k][1] << endl;
  return 0;
}
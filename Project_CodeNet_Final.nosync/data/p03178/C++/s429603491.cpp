#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
const ll mod = 1e9+7;

int main(){
  string s;
  cin >> s;
  int n = s.length();
  int d;
  cin >> d;
  vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(n+1,vector<ll>(d,0)));
  dp[0][0][0] = 1;
  rep(i,n) {
    int a = s[i] - '0';
    rep(j,d) (dp[0][i+1][(j+a)%d] += dp[0][i][j]) %= mod;
    rep(j,a) {
      rep(k,d) (dp[1][i+1][(k+j)%d] += dp[0][i][k]) %= mod;
    }
    rep(j,10) {
      rep(k,d) (dp[1][i+1][(k+j)%d] += dp[1][i][k]) %= mod;
    }
  }
  ll ans = (((dp[0][n][0] + dp[1][n][0] - 1) % mod) + mod) % mod;  
  cout << ans << endl; 
  return 0;
}
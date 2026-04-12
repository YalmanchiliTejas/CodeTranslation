#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ll long long
#define MOD 1000000007
#define MAX 1000010
using namespace std;

int main(){
  string s;
  int k;
  cin >> s >> k;
  int dp[110][10][2] = {0};
  int n = s.size();
  
  dp[0][0][0] = 1;
  REP(i,n) {
    REP(j,k+1) {
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
  
  cout << dp[n][k][0] + dp[n][k][1] << endl;
  return 0;
}
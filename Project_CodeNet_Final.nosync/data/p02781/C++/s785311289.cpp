#include<bits/stdc++.h>
using namespace std;

string S;
int K;
int dp[2][100+1][5];

signed main() {
  //https://atcoder.jp/contests/abc154/tasks/abc154_e
  cin >> S >> K;
  int n = S.size();

  dp[0][0][0] = 1;

  for(int i=0; i<n; i++) {
    int s = (int)(S[i] - '0');
    for(int k=0; k<=K; k++) {
      for(int d=0; d<=9; d++) dp[1][i+1][k + (int)(d!=0)] += dp[1][i][k];
      for(int d=0; d<s; d++)  dp[1][i+1][k + (int)(d!=0)] += dp[0][i][k];
      dp[0][i+1][k + (int)(s!=0)] += dp[0][i][k];
    }
  }
  cout << dp[1][n][K] + dp[0][n][K] << endl;
}
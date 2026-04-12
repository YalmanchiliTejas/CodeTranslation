#include <bits/stdc++.h>
using namespace std;

int dp[102][4][2];

int main(){
  string s;
  int kp;
  cin >> s >> kp;
  int n = s.size();
  dp[0][0][0] = 1;
  for(int i=0; i<n; ++i) for(int j=0; j<4; ++j) for(int k=0; k<2; ++k){
    int si = s[i] - '0';
    for(int l=0; l<10; ++l){
      int nk = k;
      if(k == 0){
        if(l > si) continue;
        if(l < si) nk = 1;
      }
      if(l==0) dp[i+1][j][nk] += dp[i][j][k];
      else if(j<kp) dp[i+1][j+1][nk] += dp[i][j][k];
    }
  }
  int ans = dp[n][kp][0] + dp[n][kp][1];
  cout << ans << endl;
}

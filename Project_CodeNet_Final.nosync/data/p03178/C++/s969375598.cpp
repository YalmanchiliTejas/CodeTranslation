#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

const int MOD = 1e9 + 7;

signed main(){

  string k; cin >> k;
  int d; cin >> d;

  static int dp[100001][101][2];
  dp[0][0][0] = 1;
  for(int i = 0; i < k.size(); i++){
    for(int j = 0; j < d; j++){
      int D = (int)(k[i]-'0');
      for(int l = 0; l < 10; l++){
        if(l < D){
          dp[i+1][(j+l)%d][1] += (dp[i][j][0] + dp[i][j][1]);
        }
        if(l == D){
          dp[i+1][(j+l)%d][0] += dp[i][j][0];
          dp[i+1][(j+l)%d][1] += dp[i][j][1];
        }
        if(l > D){
          dp[i+1][(j+l)%d][1] += dp[i][j][1];
        }
        dp[i+1][(j+l)%d][0] %= MOD;
        dp[i+1][(j+l)%d][1] %= MOD;
      }
    }
  }
  cout << (dp[k.size()][0][0] + dp[k.size()][0][1] - 1 + MOD) % MOD  << endl;

  return 0;
}

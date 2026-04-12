#include<bits/stdc++.h>
using namespace std;
using lint = long long;
lint dp[100010][2][110];
const lint MOD = 1e9+7;

signed main(){
  lint D; string s; cin >> s >> D;
  dp[0][0][0] = 1;
  lint len = s.size();
  for(lint i = 0; i < len; i++){
    for(lint j = 0; j < 2; j++){
      for(lint amari = 0; amari < D; amari++){
        if(j == 1){
          for(lint k = 0; k <= 9; k++){
            dp[i + 1][j][(amari + k) % D] += dp[i][j][amari];
            dp[i + 1][j][(amari + k) % D] %= MOD;
          }
        }
        if(j == 0){
          lint lim = s[i] - '0';
          for(lint k = 0; k <= lim; k++){
            dp[i + 1][k != lim][(amari + k) % D] += dp[i][j][amari];
            dp[i + 1][k != lim][(amari + k) % D] %= MOD;
          }
        }
      }
    }
  }
  lint ans = (dp[len][0][0] + dp[len][1][0] - 1) % MOD;
  if(ans < 0) ans += MOD;
  cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[110][4][2] = {};

int main(void){
  string n;
  int k;
  cin >> n;
  cin >> k;
  int len = (int)n.size();
  dp[0][0][0] = 1LL;
  for(int i = 0;i < len;++i){
    ll c = n[i] - '0';
    for(int j = 0;j < 4;++j){
      if(c != 0) {
        dp[i+1][j][1] += dp[i][j][0]; // 0
        if (j + 1 < 4) {
          dp[i+1][j+1][1] += dp[i][j][0] * (c - 1); // c - 1
          dp[i+1][j+1][0] += dp[i][j][0]; // c
        }
      } else {
        dp[i+1][j][0] += dp[i][j][0];
      }
      dp[i+1][j][1] += dp[i][j][1]; // 0
      if (j + 1 < 4) {
        dp[i+1][j + 1][1] += dp[i][j][1] * 9;
      }
    }
  }
  cout << dp[len][k][0] + dp[len][k][1] << endl;
  return 0;
}

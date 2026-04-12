#include <bits/stdc++.h>
using namespace std;

int64_t comb(int a, int b){
  if(a < b) return 0;

  int64_t res = 1;
  for(int i=0; i<b; i++) res *= a-i;
  for(int i=0; i<b; i++) res /= b-i;
  return res;
}

int main(){
  string S; int K;
  cin >> S >> K;
  int L = S.length();

  // dp1[i][j][0] : 上からiケタ目までで0でない数がj個，かつそこまではNと一致
  // dp1[i][j][1] : 上からiケタ目までで0でない数がj個，かつN未満であることが確定
  vector<vector<vector<int>>> dp(110, vector<vector<int>>(4, vector<int>(2)));

  dp[0][0][0] = 1;

  for(int i=0; i<L; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<2; k++){
        int nd = S[i] - '0'; // 元の数のiケタ目
        for(int d=0; d<=9; d++){ // iケタ目の候補
          int ni = i+1, nj = j, nk = k;
          if(d != 0) nj++;
          if(nj > K) continue;
          if(nk == 0){
            if(d > nd) continue;
            if(d < nd) nk = 1;
          }
          dp[ni][nj][nk] += dp[i][j][k];
        }
      }
    }
  }

  cout << dp[L][K][0] + dp[L][K][1] << endl;
  

}
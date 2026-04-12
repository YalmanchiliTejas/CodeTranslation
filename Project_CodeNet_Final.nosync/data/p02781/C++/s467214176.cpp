#include<iostream>
#include<string>
#include<cstring>
/*
i : 0 ~ m, j: 0 ~ K, k: 0 or 1
dp[i][j][k] := 上からi桁目まで決めてj個の非ゼロを使って
k = 0 : そこまでの桁はNと全て一致しているとき
k = 1 : そこまでの桁はNと全て一致しているわけではないとき
の場合の数
*/

int main(){
  std::string N;
  int K;
  std::cin >> N;
  std::cin >> K;
  int keta = N.length();

  int dp[105][4][2];
  memset(dp, 0, sizeof dp);
  dp[0][0][0] = 1; // 最初は1ずつ足すので初期値は1
  for(int i = 0; i < keta; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 2; k++){
        int now_digit_val = N[i] - '0'; // Nの上からi桁目を取り出す

        // 次の桁を0 ~ 9のどれにするか？
        for(int d = 0; d < 10; d++){
          int next_i = i + 1;
          int next_j = j;
          int next_k = k;
          if(d != 0) next_j++;
          if(next_j > K) continue; // 非ゼロが多すぎる
          if(k == 0){
            if(d > now_digit_val) continue; // 数値がオーバー
            if(d < now_digit_val) next_k = 1;
          }
          dp[next_i][next_j][next_k] += dp[i][j][k];
        }
      }
    }
  }

  int ans = dp[keta][K][0] + dp[keta][K][1];
  std::cout << ans << std::endl;

  return 0;
}
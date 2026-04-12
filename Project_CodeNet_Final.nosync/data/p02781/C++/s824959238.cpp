#include <bits/stdc++.h>
using namespace std;

// dp[i][j][k]
// i:確定している桁数（最大100桁だが少し多めに）
// j:Kより、0から3まで調べる必要がある
// k:N未満(1)か否(0)か
int dp[105][4][2];

int main() {

  string N;
  cin >> N;

  int K;
  cin >> K;

  // 桁数
  int n = N.size();

  // 初期化  
  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 2; k++) {

        // 1桁ずつ見ていく
        int c_ = N[i] - '0';
        
        for (int c = 0; c < 10; c++) {
          
          // 値を入れる場所を決める
          int i_ = i + 1;
          int j_ = j;
          int k_ = k;
          
          // j が 0 じゃない場合は次(j_++)を見るが
          // K を超えていたらこのループは終わり
          if (c != 0) {
            j_++;
          }
          if (j_ > K) {
            continue;
          }

          // k が N 未満か確定していないときは
          // 見ている桁の値(c_)が c 未満だと確定できないので、このループは終わり
          // 見ている桁の値(c_)が c を超えると N 未満が確定する
          if (k_ == 0) {
            if (c_ < c) {
              continue;
            } else if (c < c_) {
              k_ = 1;
            }
          }

          // 決めた場所に値を入れる
          dp[i_][j_][k_] += dp[i][j][k];

        }
      }
    }
  }

  // n 桁の値で 0 じゃない数字が K 個あって、
  // N 未満が確定している場合と確定していない場合の値を足したものが答え
  int answer = dp[n][K][0] + dp[n][K][1];

  cout << answer << endl;

  return 0;

}
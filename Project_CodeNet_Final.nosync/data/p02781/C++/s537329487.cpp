#include <iostream>

using namespace std;

int main() {
  int K, siz;
  string N;
  cin >> N >> K;

  siz = N.size();
  N = "@" + N; // sentinel

  // dp[i][j][k] := i桁目まで見た時, smaller flagがjで,
  // 0でない数字がk個であるような数の総数
  long long dp[102][2][102] = {0};
  dp[0][0][0] = 1;

  for (int i = 1; i <= siz; i++) {
    for (int smaller = 0; smaller < 2; smaller++) {
      for (int k = 0; k <= i; k++) {
        // smaller が flag が立っている, すなわち
        // それまで見ていた数字が N より小さいならば
        if (smaller == 1) {
          // 現在の桁の数字は何でも良い
          for (int c = 0; c <= 9; c++) {
            // 0以外を選ぶと0出ない数の総数が増える
            if (c != 0) {
              dp[i][1][k + 1] += dp[i - 1][1][k];
            } else {
              dp[i][1][k] += dp[i - 1][1][k];
            }
          }
        }
        // smaller が flag が立っていない, すなわち
        // それまで見ていた数字が N と一致するならば
        if (smaller == 0) {
          int cur = N[i] - '0';
          if (cur == 0) {
            dp[i][0][k] += dp[i - 1][0][k];
          } else {
            for (int c = 0; c <= cur; c++) {
              if (c == 0) {
                dp[i][1][k] += dp[i - 1][0][k];
              } else if (c == cur) {
                dp[i][0][k + 1] += dp[i - 1][0][k];
              } else {
                dp[i][1][k + 1] += dp[i - 1][0][k];
              }
            }
          }
        }
      }
    }
  }

  cout << dp[siz][0][K] + dp[siz][1][K] << endl;

  return 0;
}
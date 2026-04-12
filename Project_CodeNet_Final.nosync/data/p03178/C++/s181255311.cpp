#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

string s;
int d;
//桁番号、less、あまり
// 1はs以下確定、0は未確定
long long dp[10001][2][100] = {0};

int main() {
  cin >> s >> d;
  dp[0][0][0] = 1;
  for(int i = 1; i <= s.size(); ++i) {
    for(int j = 0; j < d; ++j) {
      for(int k = 0; k < 10; ++k) {
        // i桁目の数字をkにしたときに、それが指定された数字のi桁目の数字
        //より大きいか小さいか
        if(k < s[i - 1] - '0')
          dp[i][1][(j + k) % d] +=
              (dp[i - 1][1][j] + dp[i - 1][0][j]) % N;
        else if(k == s[i - 1] - '0') {
          dp[i][1][(j + k) % d] += dp[i - 1][1][j];
          dp[i][0][(j + k) % d] += dp[i - 1][0][j];
        }
        else
          dp[i][1][(j + k) % d] += dp[i - 1][1][j];
        dp[i][1][(j + k) % d] %= N;
        dp[i][0][(j + k) % d] %= N;
      }
    }
  }
  // 0が含まれているので０を排除
  cout << (N+dp[s.size()][1][0] + dp[s.size()][0][0] - 1) % N
       << endl;
  return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[105][4][2];
int main() {
  ios::sync_with_stdio(false);
  string S;
  int K;
  cin >> S >> K;
  dp[0][K-1][1] = 1;
  dp[0][K-1][0] = S[0] - '0' - 1;
  dp[0][K][0] = 1;
  //for (int i=0; i<=K; i++) cout << dp[0][i][0] << ' ' << dp[0][i][1] << ' ';
  //cout << endl;
  int N = S.size();
  for (int i=1; i<N; i++) {
    int d = S[i] - '0';
    for (int j=0; j<=K; j++) {
      dp[i][j][0] = dp[i-1][j][0];
      if (j < K) dp[i][j][0] += dp[i-1][j+1][0] * 9;
      if (d > 0 && j < K) dp[i][j][0] += dp[i-1][j+1][1] * (d-1);
      if (d > 0) dp[i][j][0] += dp[i-1][j][1];

      if (d > 0 && j < K) dp[i][j][1] = dp[i-1][j+1][1];
      else dp[i][j][1] = dp[i-1][j][1];

    }
    //for (int j=0; j<=K; j++) cout << dp[i][j][0] << ' ' << dp[i][j][1] << ' ';
    //cout << endl;
  }
  cout << dp[N-1][0][0] + dp[N-1][0][1] << endl;
}
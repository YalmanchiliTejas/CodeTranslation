#include <iostream>
#include <string>
using namespace std;

typedef long long ll;


ll dp[101][2][5];
int main() {
  string s; cin >> s;
  int K; cin >> K;
  int n = s.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) { 
    int d = s[i]-'0';
    for (int k = 0; k < 4; ++k) {
      dp[i+1][1][k] += dp[i][1][k]; // 0
      dp[i+1][1][k+1] += 9*dp[i][1][k]; // 1-9
      if (d > 0) {
        dp[i+1][1][k] += dp[i][0][k]; // 0
        dp[i+1][1][k+1] += (d-1)*dp[i][0][k]; // 1-(d-1)
        dp[i+1][0][k+1] += dp[i][0][k]; // d
      }
      else {
        dp[i+1][0][k] += dp[i][0][k]; // d = 0
      }
    }
  }
  cout << dp[n][0][K]+dp[n][1][K] << endl;
}


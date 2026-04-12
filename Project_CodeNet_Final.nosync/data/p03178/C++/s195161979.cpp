#include <iostream>
#include <string>

using namespace std;

const int M = 1e9+7;

string k;
int d;

long long dp[10005][100][2];

int main()
{
  cin >> k >> d;

  dp[0][0][0] = 1;

  for (int i = 0; i < k.length(); i++) {
    for (int j = 0; j < d; j++) {
      dp[i+1][(j+(k[i]-'0'))%d][0] += dp[i][j][0];
      for (int l = 0; l < k[i]-'0'; l++) {
        dp[i+1][(j+l)%d][1] += dp[i][j][0];
      }
      for (int l = 0; l < 10; l++) {
        dp[i+1][(j+l)%d][1] += dp[i][j][1];
      }
    }
    for (int j = 0; j < d; j++) {
      dp[i+1][j][0] %= M;
      dp[i+1][j][1] %= M;
    }
  }

  int ans = (dp[k.length()][0][0] + dp[k.length()][0][1]-1+M) % M;
  cout << ans << endl;
  return 0;
}

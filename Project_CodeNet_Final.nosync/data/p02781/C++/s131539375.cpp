#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s; int k; cin >> s >> k;
  int len = s.length();
  int a[105]; for (int i = 0; i < len; ++i) a[i] = s[i] - '0';
  
  long long dp[105][5][2] = {}; dp[0][0][0] = 1;
  for (int i = 0; i < len; ++i)
    for (int j = 0; j <= 3; ++j) {
      dp[i+1][j+1][1] += dp[i][j][1]*9;
      dp[i+1][j][1] += dp[i][j][1];
      if (a[i] == 0)
        dp[i+1][j][0] += dp[i][j][0];
      else {
        dp[i+1][j+1][0] += dp[i][j][0];
        dp[i+1][j+1][1] += dp[i][j][0]*(a[i]-1);
        dp[i+1][j][1] += dp[i][j][0];
      }
    }
  
  cout << dp[len][k][0] + dp[len][k][1] << endl;
  return 0;
}
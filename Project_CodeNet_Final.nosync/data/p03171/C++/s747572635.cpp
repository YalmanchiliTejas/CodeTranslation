#include <algorithm>
#include <iostream>

using namespace std;

int n, a[100];
long long dp[3100][3100];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> dp[i][1];
  }

  for (int len = 2; len <= n; len++) {
    for (int i = 0; i+len <= n; i++) {
      dp[i][len] = max(dp[i][1]-dp[i+1][len-1], dp[i+len-1][1]-dp[i][len-1]);
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}
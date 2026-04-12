#include <algorithm>
#include <iostream>

using namespace std;

int n;
long long dp[3100][3100];

int main()
{
  cin >> n;
  for (int l = 0; l < n; l++) {
    cin >> dp[l][l+1];
  }

  for (int l = n-2; l >= 0; l--) {
    for (int r = l+2; r <= n; r++) {
      dp[l][r] = max(dp[l][l+1]-dp[l+1][r], dp[r-1][r]-dp[l][r-1]);
    }
  }

  cout << dp[0][n] << endl;
  return 0;
}
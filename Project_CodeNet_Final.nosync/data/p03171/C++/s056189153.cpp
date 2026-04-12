#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  long long dp[3005][3005]; for(int i = 0; i < n; i++) cin >> dp[1][i];
  
  for(int len = 2; len <= n; len++) for(int i = 0; i + len <= n; i++)
    dp[len][i] = max(dp[1][i+len-1]-dp[len-1][i], dp[1][i]-dp[len-1][i+1]);
  
  cout << dp[n][0] << endl;
  return 0;
}
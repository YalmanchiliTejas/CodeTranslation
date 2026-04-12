#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N; cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++){
    cin >> a[i];
  }

  vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0));
  for (int len=1; len<=N; len++) {
    for (int i=0; i+len<=N; i++) {
      int j = i+len;
      if ((N-len)%2 == 0) {
        // dp[i,j) = max(dp[i,j-1)+a[i] , a[i]+dp[i+1, j))
        dp[i][j] = max(dp[i][j-1]+a[j-1], a[i]+dp[i+1][j]);
      } else {
        // dp[i,j) = min(dp[i,j-1)-a[i] , -a[i]+dp[i+1, j))
        dp[i][j] = min(dp[i][j-1]-a[j-1], -a[i]+dp[i+1][j]);
      }
    }
  }
  cout << dp[0][N] << endl;

  return 0;
}

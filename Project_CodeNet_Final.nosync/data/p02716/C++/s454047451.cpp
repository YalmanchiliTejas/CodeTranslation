#include <stdio.h>
#include <vector>
using namespace std;

int main() {
  long long n, a;
  scanf("%ld", &n);
  vector<int> v(n);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  vector<vector<long long>> dp(n+1, vector<long long>(4, -1e15));
  dp[0][0] = 0; dp[1][0] = v[0]; dp[2][1] = v[1]; if(n > 2) dp[3][2] = v[2];
  for(int i = 3; i <= n; ++i){
    if(i & 1){
      dp[i][0] = dp[i-2][0] + v[i-1];
      dp[i][2] = max(dp[i][2], max(dp[i-2][2] + v[i-1], dp[i-3][1] + v[i-1]));
      if(i > 3) dp[i][2] = max(dp[i][2], dp[i-4][0] + v[i-1]);
    }
    else dp[i][1] = max(dp[i-2][1] + v[i-1], dp[i-3][0] + v[i-1]);
  }
  if(n % 2 == 0) a = max(dp[n][1], dp[n-1][0]);
  else a = max(dp[n][2], max(dp[n-1][1], dp[n-2][0]));
  printf("%ld\n", a);
  return 0;
}
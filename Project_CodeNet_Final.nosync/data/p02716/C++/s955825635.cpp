#include <stdio.h>
#include <vector>

int main() {
  long int n, a;
  scanf("%ld", &n);
  std::vector<int> v(n);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(4, -1e15));
  dp[0][0] = 0; dp[1][0] = v[0]; dp[2][1] = v[1]; if(n > 2) dp[3][2] = v[2];
  for(int i = 3; i <= n; ++i){
    if(i & 1){
      dp[i][0] = dp[i-2][0] + v[i-1];
      dp[i][2] = std::max(dp[i][2], std::max(dp[i-2][2] + v[i-1], dp[i-3][1] + v[i-1]));
      if(i > 3) dp[i][2] = std::max(dp[i][2], dp[i-4][0] + v[i-1]);
    }
    else dp[i][1] = std::max(dp[i-2][1] + v[i-1], dp[i-3][0] + v[i-1]);
  }
  if(n % 2 == 0) a = std::max(dp[n][1], dp[n-1][0]);
  else a = std::max(dp[n][2], std::max(dp[n-1][1], dp[n-2][0]));
  printf("%ld\n", a);
  return 0;
}
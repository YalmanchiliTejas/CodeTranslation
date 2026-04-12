#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  long long A[200001];
  long long dp[200001][2];
  
  scanf("%d", &N);
  
  for (int i = 1; i <= N; i++) {
    scanf("%lld", A + i);
  }
  
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = 0;
  dp[1][1] = A[1];
  dp[2][0] = max(A[1], A[2]);
  
  long long odd_sum = A[1];
  for (int i = 3; i <= N; i++) {
    if (i % 2 == 1) {
      odd_sum += A[i];
      dp[i][1] = odd_sum;
      dp[i][0] = max({dp[i - 1][0], dp[i - 2][1], A[i] + dp[i - 2][0]});
    }
    else {
      dp[i][0] = max({dp[i - 1][1], dp[i - 2][0] + A[i], dp[i - 3][1] + A[i]});
    }
  }
  
  
  printf("%lld\n", dp[N][0]);
  
  return 0;
}
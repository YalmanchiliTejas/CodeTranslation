#include <cstdio>
#include <algorithm>

int n;
int A[3000];

long long int dp[3001][3001];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", A+i);
  for(int i = n-1; i >= 0; i--){
    for(int j = i + 1; j <= n; j++){
      dp[i][j] = std::max(A[j-1] - dp[i][j-1], A[i] - dp[i+1][j]);
    }
  }
  printf("%lld\n", dp[0][n]);
  return 0;
}

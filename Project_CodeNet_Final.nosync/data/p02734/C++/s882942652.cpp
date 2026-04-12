#include <cstdio>

using namespace std;

long long dp[3001][3001];
int a[3001];

const int mod = 998244353;

int main()
{
  int N, S;
  
  scanf("%d %d", &N, &S);
  
  long long ans = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i]);
    dp[i - 1][0] = i;
    for (int j = S; j >= 0; j--) {
      dp[i][j] = (dp[i - 1][j] + (j >= a[i] ? dp[i - 1][j - a[i]] : 0)) % mod;
    }
    ans = (ans + dp[i][S]) % mod;
  }
  
  printf("%lld\n", ans);
  
  return 0;
}
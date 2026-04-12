#include <bits/stdc++.h>

const int N = 2e5 + 10;
typedef long long ll;

ll sum[N], dp[N], a[N];
int n, m, i, j, k;

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    if (i & 1) {
      sum[i] = sum[i - 2] + a[i];
    }
  }
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (i & 1) {
      dp[i] = std::max(dp[i - 2] + a[i], dp[i - 1]);
    } else {
      dp[i] = std::max(sum[i - 1], dp[i - 2] + a[i]);
    }
  }
  printf("%lld\n", dp[n]);
  return 0;  
}
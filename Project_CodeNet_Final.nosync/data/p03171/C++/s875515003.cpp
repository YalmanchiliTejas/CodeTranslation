#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 3001;

int N;
ll a[MAX_N];
ll dp[MAX_N][MAX_N][2];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  for(int i = 0; i < N; ++i) dp[i][i][0] = dp[i][i][1] = a[i];
  
  for(int d = 1; d < N; ++d) {
    for(int p = 0; p < 2; ++p) {
      for(int i = 0; i + d < N; ++i) {
        int j = i + d;
        dp[i][j][p] = max(a[i] - dp[i + 1][j][1 - p], a[j] - dp[i][j - 1][1 - p]);
      }
    }
  }
  
  printf("%lld\n", dp[0][N - 1][0]);
  return 0;
}
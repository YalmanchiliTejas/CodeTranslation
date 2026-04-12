#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXA = 1e9+5;
const int MAXN = 3005;
const lld INFN = 1LL * MAXA * MAXN;
lld dp[MAXN][MAXN];
int  A[MAXN];
int N;

void init() {
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      dp[i][j] = INFN;
    }
  }
}

// dp[l][r] = value of X - Y using elements A[l, r]

lld dfs(int l, int r) {
  if (l > r) return 0;
  if (dp[l][r] != INFN) {
    return dp[l][r];
  }
  return dp[l][r] = std::max(
    A[l] - dfs(l+1, r),
    A[r] - dfs(l, r-1)
  );
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
  }
  init();
  printf("%lld\n", dfs(1, N));
  return 0;
}
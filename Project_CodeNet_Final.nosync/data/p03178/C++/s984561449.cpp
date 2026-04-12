#include <cstdio>
#include <cstring>
const int MAXB = 10;  // Base representation.
const int MAXD = 105;
const int MAXN = 1e4+5;
const int MOD = 1e9+7;
const int NOPE = -1;
char K[MAXN];
int dp[MAXN][MAXD][2]{ };
int D, N;

// dp[i][j] = numbers of length i and digit sum j (mod D).

int dfs(int pos, int sum, bool less) {
  if (dp[pos][sum][less] != NOPE) {
    return dp[pos][sum][less];
  }
  if (pos == N) {
    return dp[pos][sum][less] = (sum == 0) ? 1 : 0;
  }
  int ans = 0;
  int val = K[pos] - '0';
  int end = (less) ? MAXB : (val + 1);
  for (int i = 0; i < end; ++i) {
    int nsum = (1LL * sum + i) % D;
    bool nless = less || (i < val);
    ans = (1LL * ans + dfs(pos + 1, nsum, nless)) % MOD;
  }
  return dp[pos][sum][less] = ans;
}

void init() {
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j < D; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i][j][k] = NOPE;
      }
    }
  }
}

int main() {
  scanf("%s", K);
  scanf("%d", &D);
  N = strlen(K);
  init();
  int ret = dfs(0, 0, false);
  // Exclude zero.
  ret = (1LL * ret + MOD - 1) % MOD;
  printf("%d\n", ret);
  return 0;
}
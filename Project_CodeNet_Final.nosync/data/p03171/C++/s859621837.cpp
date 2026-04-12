#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long llt;

const int MaxN = 3000 + 5;

int N;
llt A[MaxN];
llt dp[MaxN][MaxN];

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]);
}

llt dfs(int l, int r) {
  if (l == r) return dp[l][r] = A[l];
  if (l > r) return dp[l][r] = 0;
  if (dp[l][r] != 0) return dp[l][r];

  dp[l][r] = A[l] + min(dfs(l + 2, r), dfs(l + 1, r - 1));
  dp[l][r] = max(dp[l][r], A[r] + min(dfs(l + 1, r - 1), dfs(l, r - 2)));
  return dp[l][r];
}

void solve() {
  llt sum = 0;
  for (int i = 1; i <= N; ++i) sum += A[i];
  cout << dfs(1, N) * 2 - sum << endl;
}

int main() {
  init();
  solve();
  return 0;
}
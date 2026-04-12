#include <cstdio>

const int MaxN = 3000 + 5;

int N;
int A[MaxN];
long long Dp[MaxN][MaxN];
bool Vis[MaxN][MaxN];

template <typename Typ>
inline Typ max(Typ x, Typ y) { return x > y ? x : y; }
template <typename Typ>
inline Typ min(Typ x, Typ y) { return x < y ? x : y; }

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i)
    scanf("%d", &A[i]);
}

long long dfs(int l, int r) {
  if (l > r) return 0LL;
  if (Vis[l][r] == true) return Dp[l][r];
  Vis[l][r] = true;
  int d = l - 1 + N - r;
  if (d & 1) Dp[l][r] = min(dfs(l + 1, r) - A[l], dfs(l, r - 1) - A[r]);
  else Dp[l][r] = max(dfs(l + 1, r) + A[l], dfs(l, r - 1) + A[r]);
  return Dp[l][r];
}

void solve() {
  printf("%lld\n", dfs(1, N));
}

int main() {
  init();
  solve();
  return 0;
}
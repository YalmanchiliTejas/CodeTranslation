#include <cstdio>
#include <cstring>

const int MaxN = 10000 + 5;
const int MaxD = 100 + 5;
const int Mod = 1000000007;

int N, D;
char K[MaxN];
int Dp[MaxN][MaxD][2];
bool Vis[MaxN][MaxD][2];

inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }
inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }
inline void inc(int &x, int y = 1) { x = add(x, y); }

void init() {
  scanf("%s", K + 1);
  N = strlen(K + 1);
  scanf("%d", &D);
}

int dfs(int x, int s, bool limit) {
  if (x > N) return s == 0;
  if (Vis[x][s][limit] == true) return Dp[x][s][limit];
  Vis[x][s][limit] = true;
  int mx = 9;
  if (limit == true) mx = K[x] - '0';
  for (int d = 0; d <= mx; ++d) {
    bool new_lim = limit && (d == mx);
    int new_s = (s + d) % D;
    inc(Dp[x][s][limit], dfs(x + 1, new_s, new_lim));
  }
  return Dp[x][s][limit];
}

void solve() {
  printf("%d\n", sub(dfs(1, 0, 1), 1));
}

int main() {
  init();
  solve();
  return 0;
}
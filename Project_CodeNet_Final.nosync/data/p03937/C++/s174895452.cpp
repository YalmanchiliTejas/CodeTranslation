#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
using LL = long long;
typedef long long LL;
int n, m;
char g[22][22];

bool v[22][22];
int dfs(int x, int y) {
  if (x < 0 || y < 0 || x == n || y == m) return 0;
  if (v[x][y] || g[x][y] != '#') return 0;
  v[x][y] = true;
  return 1 + dfs(x+1,y) + dfs(x,y+1);
}

void f() {
  puts("Impossible");
  exit(0);
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%s", g[i]);
  int cnt = 0;
  REP(i, n) REP(j, m) cnt += g[i][j] == '#';
  if (cnt != n + m - 1) f();
  if (g[0][0] != '#') f();
  if (g[n - 1][m - 1] != '#') f();
  if (dfs(0, 0) != cnt) f();
  puts("Possible");
  return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;
 
const int nmax = 9;

int n, m;
int G[nmax][nmax];
int vis[nmax];

int dfs(int cur) {
  int visited = 0;
  for (int i = 1; i <= n; i++) {
    visited += vis[i];
  }
  if (visited == n) return 1;
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (G[cur][i] && !vis[i]) {
      vis[i] = 1;
      ret += dfs(i);
      vis[i] = 0;
    }
  }
  return ret;
}
 
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    G[x][y] = 1;
    G[y][x] = 1;
  }
  vis[1] = 1;
  cout << dfs(1) << endl;
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long u64;

bool edge[8][8];

u64 dfs(int now, vector< bool > & path, int n)
{
  int p = 0;
  path[now] = true;
  bool full = true;
  for (int i = 0; i < n; ++i) {
    if (!path[i]) {
      full = false;
      break;
    }
  }
  if (full) {
    return 1;
  }
  for (int i = 0; i < n; ++i) {
    if (edge[now][i] && !path[i]) {
      vector< bool > c_path(path);
      p += dfs(i, c_path, n);
    }
  }
  return p;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      edge[i][j] = false;
    }
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edge[a-1][b-1] = true;
    edge[b-1][a-1] = true;
  }
  int now = 0;
  vector< bool > path(8, false);
  cout << dfs(now, path, n) << endl;

  return 0;
}

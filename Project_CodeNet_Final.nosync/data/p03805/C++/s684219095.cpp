#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool g[8][8];
int dfs(int v, int n, bool visited[8])
{
  bool all_visited = true;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      all_visited = false;
      break;
    }
  }

  if (all_visited)
  {
    return 1;
  }

  int res = 0;
  for (int i = 0; i < n; i++)
  {
    if (visited[i] || !g[v][i])
    {
      continue;
    }
    else
    {
      visited[i] = true;
      res += dfs(i, n, visited);
      visited[i] = false;
    }
  }

  return res;
}

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      g[i][j] = false;
    }
  }

  int a, b;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = g[b][a] = true;
  }

  bool visited[8];
  for (int i = 0; i < 8; i++)
  {
    visited[i] = false;
  }
  visited[0] = true;

  cout << dfs(0, n, visited) << endl;
}
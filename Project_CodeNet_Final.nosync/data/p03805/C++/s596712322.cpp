#include <bits/stdc++.h>
#include <tuple>
using namespace std;
using ll = long long;

int n, m;
int graph[8][8];

// 訪れた頂点=bool配列で引数に渡す
int dfs(int v, bool visited[8])
{
  bool judge = true;
  for (int i = 0; i < n; ++i)
  {
    if (!visited[i])
      judge = false;
  }
  if (judge)
  {
    return 1;
  }
  int ret = 0;
  for (int i = 0; i < n; ++i)
  {
    if (graph[v][i] == 0)
      continue;
    if (visited[i])
      continue;
    visited[i] = true;
    ret += dfs(i, visited);
    visited[i] = false;
  }

  return ret;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = graph[b][a] = 1;
  }
  bool visited[8] = {};
  visited[0] = true;
  cout << dfs(0, visited) << endl;

  return 0;
}
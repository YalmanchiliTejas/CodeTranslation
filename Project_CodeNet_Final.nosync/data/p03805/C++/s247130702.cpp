#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> graph(8, vector<int>(8, 0));
int n, m, a, b;

int dfs(int s, vector<int> visited)
{
  bool all_visited = true;
  for (int i = 0;i < n;i++)
  {
    if(visited[i] == 0)
      all_visited = false;
  }

  if(all_visited) return 1;

  int ret=0;

  visited[s] = 1;
  for (int i=0;i < n;i++) 
  {
    if(graph[s][i] == 0) continue;
    if(visited[i] ==1) continue;

    visited[i] = 1;
    ret += dfs(i, visited);
    visited[i] = 0;
  }
  return ret;
}

int main()
{
  cin >> n >> m;
  for (int i=0;i < m;i++)
  {
    cin >> a >> b;
    a--;b--;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  vector<int> visited(8, 0);
  visited[0] = 1;
  cout << dfs(0, visited) << endl;
  return 0;
}

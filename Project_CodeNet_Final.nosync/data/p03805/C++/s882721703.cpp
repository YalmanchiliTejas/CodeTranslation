#include <iostream>

using namespace std;

bool graph[8][8] = {false};

int dfs(int iterate, bool * visited, int n)	{
  bool all_visited = true;
  for (int i = 0; i < n; i++)	{
    if (visited[i] == false)	
      all_visited = false;
  }
  if (all_visited)
    return 1;
  int rval = 0;
  for (int i = 0; i < n; i++)	{
    if (graph[iterate][i] == false)	{
      continue;
    }
    if (visited[i] == true)	{
      continue;
    }
    visited[i] = true;
    rval += dfs(i, visited, n);
    visited[i] = false;
  }
  return rval;
}

int main()	{
  int n, m;
  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++)	{
    cin >> a >> b;
    graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
  }
  bool visited[n] = {false};
  visited[0] = true;
  cout << dfs(0, visited, n) << endl;
  return 0;
}
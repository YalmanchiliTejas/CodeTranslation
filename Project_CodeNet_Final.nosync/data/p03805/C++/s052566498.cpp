#include <bits/stdc++.h>
using namespace std;

int c = 0;
int N, M;
vector<int> a(28), b(28), v(8, false);
int dfs(int current, vector<int> visited)
{
  int result = 0;
  bool all_visited = true;
  for (int i = 0; i <N; i++)
  {
    if (visited[i] == false)
    {
      all_visited = false;
      break;
    }
  }
  if (all_visited)
  {
    c++;
    return 0;
  }

  for (int i = 0; i < M; i++)
  {
    if (a[i] == current && visited[b[i]-1] == false)
    {
      visited[b[i]-1] = true;
      result += dfs(b[i], visited);
      visited[b[i]-1] = false;
    }
    if (b[i] == current && visited[a[i]-1] == false)
    {
      visited[a[i]-1] = true;
      result += dfs(a[i], visited);
      visited[a[i]-1] = false;
    }
  }
  return 0;
}

int main()
{
  cin >> N >> M;

  for (int i = 0; i < M; i++)
  {
    cin >> a[i] >> b[i];
  }
  v[0] = true;
  dfs(1, v);
  cout << c << endl;
  return 0;
}

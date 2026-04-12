#include <cstdio>
#include <vector>
#include <algorithm>

int n;
bool visit[9];
std::vector<int> v[9];

int dfs(int vert)
{
  visit[vert] = true;
  
  int count = 0;
  for (int i = 0; i < v[vert].size(); ++i)
  {
    if (visit[v[vert][i]]) continue;
    count += dfs(v[vert][i]);
  }

  bool all = true;
  for (int i = 1; i <= n; ++i)
  {
    all &= visit[i];
  }
  if (all) ++count;
  
  visit[vert] = false;
  return count;
}

int main()
{
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].emplace_back(b);
    v[b].emplace_back(a);
  }

  printf("%d\n", dfs(1));
  return 0;
}
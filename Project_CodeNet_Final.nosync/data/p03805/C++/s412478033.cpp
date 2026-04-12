#include <iostream>
#include <algorithm>
#include <vector>

const int MAX_N = 8;
std::vector<int> edge[MAX_N];
std::vector<int> visitList;

int64_t dfs(const int& x, const int& nodeNum, const int& last = -1)
{
  visitList.push_back(x);
  int64_t ret = 0;
  for (const auto& to : edge[x])
  {
    bool isVisited = false;
    for (const auto& visited : visitList)
    {
      if(to == visited)
      {
        isVisited = true;
        break;
      }
    }
    if (isVisited == true) continue;
    ret += dfs(to, nodeNum, x);
  }

  if (visitList.size() == nodeNum)
  {
    ++ret;
  }
  visitList.pop_back();
  return ret;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i)
  {
    int u, v;
    std::cin >> u >> v; --u; --v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int64_t ans = dfs(0, n);
  std::cout << ans << std::endl;
  return 0;
}
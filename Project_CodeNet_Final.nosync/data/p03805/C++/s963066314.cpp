#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int

struct edge
{
  int to, cost;
};
typedef std::vector<std::vector<int>> graph;
const ll MOD = 1000000007;
using namespace std;

int dfs(int now, graph &g, int n, set<int> s)
{
  if (s.count(now) == 1)
  {
    return 0;
  }
  s.insert(now);
  if (s.size() == n)
  {
    return 1;
  }

  int val = 0;

  for (auto v : g[now])
  {
    val += dfs(v, g, n, s);
  }
  return val;
}

int main()
{
  int n, m;
  cin >> n >> m;
  graph g(n);
  REP(i, m)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  set<int> s;
  cout << dfs(0, g, n, s) << endl;
}

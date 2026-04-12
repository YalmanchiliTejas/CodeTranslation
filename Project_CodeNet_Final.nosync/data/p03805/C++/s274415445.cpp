#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> g;
vector<bool> chk;

int dfs(int p = 0, int c = 0)
{
  if (chk[p])
    return 0;
  c++;
  if (c == n)
    return 1;
  chk[p] = true;
  int ret = 0;
  for (auto& nxt : g[p])
    ret += dfs(nxt, c);
  chk[p] = false;
  return ret;
}

int main()
{
  int m;
  cin >> n >> m;
  g.resize(n);
  rep(i, m)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  chk.resize(n);
  fill(chk.begin(), chk.end(), false);
  cout << dfs() << endl;
  return 0;
}
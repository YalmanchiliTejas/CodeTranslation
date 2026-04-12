#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

using Graph = vector<vector<int>>;
vector<bool> seen;
int n, m;
int ans = 0;

void dfs(const Graph &g, int v, int num) {
  seen[v] = true;
  if (num == n) {
    ans++;
  }

  for (auto next_v: g[v]) {
    if (seen[next_v]) continue;
    dfs(g, next_v, num + 1);
  }

  seen[v] = false;
}

int main(void) {
  cin >> n >> m;
  Graph g(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  seen.assign(n, false);
  dfs(g, 0, 1);

  cout << ans << endl;

  return 0;
}
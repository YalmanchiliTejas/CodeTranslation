#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using Graph = vector<vector<int>>;

const int MAX = 8;
Graph g(MAX);

void dfs(int v, vector<bool> &seen, int &ans) {
  bool allSeen = true;
  rep(i, seen.size()) {
    if (!seen[i] && i != v) {
      allSeen = false;
      break;
    }
  }
  if (allSeen) {
    ans++;
    return;
  }

  seen[v] = true;
  for (auto nv : g[v]) {
    if (seen[nv]) continue;
    dfs(nv, seen, ans);
  }
  seen[v] = false;
}

int main() {
  int n, m;
  cin >> n >> m;
  g.assign(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> seen(n, false);
  int ans = 0;
  dfs(0, seen, ans);
  cout << ans << endl;
  return 0;
}

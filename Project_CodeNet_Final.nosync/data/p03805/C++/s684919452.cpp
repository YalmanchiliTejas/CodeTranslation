#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

vector<vector<int>> to;

void dfs(int node, vector<bool>& visited, int& acc) {
  auto& v = visited;
  v[node] = true;

  if (all_of(v.begin(), v.end(), [](bool b) { return b; }))
    acc++;
  else
    for (auto n : to[node])
      if (!v[n])
        dfs(n, v, acc);

  v[node] = false;
  return;
}

int main() {
  int N, M;
  cin >> N >> M;

  to.resize(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  vector<bool> visited(N, false);
  int ans = 0;
  dfs(0, visited, ans);

  cout << ans << endl;
}
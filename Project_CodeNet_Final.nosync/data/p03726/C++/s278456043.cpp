#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

int rec(int v = 0, int pre = -1) {
  int res = 0;
  for (auto &u : G[v]) {
    if (u == pre) continue;
    res += rec(u, v);
  }

  if (res >= 2) return res;
  return !res;
}

int main() {
  int n;
  cin >> n;

  G.resize(n);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << (rec() ? "First" : "Second") << endl;
}

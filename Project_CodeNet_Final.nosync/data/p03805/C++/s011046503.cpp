#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> V;
int ans;

void dfs(int v) {
  if (accumulate(V.begin(), V.end(), 0) == V.size() - 1) {
    ans++;
    return;
  }
  for (auto g : G.at(v)) {
    if (V.at(g)) continue;
    V.at(v) = 1;
    dfs(g);
    V.at(v) = 0;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  G.resize(N);
  V.resize(N);
  for (int i = 0, a, b; cin >> a >> b; i++) {
    G.at(--a).push_back(--b), G.at(b).push_back(a);
  }
  dfs(0);
  cout << ans << "\n";
}

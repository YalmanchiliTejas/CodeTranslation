#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> G;
int ans;

void dfs(int v, vector<int> V) {
  if (accumulate(V.begin(), V.end(), 0) == N - 1) {
    ans++;
    return;
  }
  V.at(v) = 1;
  for (auto g : G.at(v)) {
    if (V.at(g)) continue;
    dfs(g, V);
  }
}

int main() {
  cin >> N >> M;
  G.resize(N);
  for (int i = 0, a, b; cin >> a >> b; i++) {
    G.at(--a).push_back(--b), G.at(b).push_back(a);
  }
  vector<int> V(N);
  dfs(0, V);
  cout << ans << "\n";
}
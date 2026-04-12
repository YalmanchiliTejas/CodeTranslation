#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> V;
int ans;

void dfs(int v) {
  if (accumulate(V.begin(), V.end(), 0) == N - 1) {
    ans++;
    return;
  }
  V.at(v) = 1;
  for (auto g : G.at(v)) if (!V.at(g)) dfs(g);
  V.at(v) = 0;
}

int main() {
  int M;
  cin >> N >> M;
  G.resize(N);
  V.resize(N);
  for (int i = 0, a, b; cin >> a >> b; i++) {
    G.at(--a).push_back(--b), G.at(b).push_back(a);
  }
  dfs(0);
  cout << ans << "\n";
}

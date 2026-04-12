#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> G;
vector<int> V;
int ans;

void dfs(int v, int cnt) {
  if (cnt == N) {
    ans++;
    return;
  }
  V.at(v) = 1;
  for (int i = 0; i < G.at(v).size(); i++)
    if (!V.at(G.at(v).at(i)))
      dfs(G.at(v).at(i), cnt + 1);
  V.at(v) = 0; 
}

int main() {
  int M;
  cin >> N >> M;
  G.resize(N + 1), V.resize(N + 1);
  for (int i = 0, a, b; i < M && cin >> a >> b; i++)
    G.at(a).push_back(b), G.at(b).push_back(a);
  dfs(1, 1);
  cout << ans << "\n";
}
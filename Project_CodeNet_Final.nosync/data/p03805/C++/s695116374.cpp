#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> G;
vector<bool> visited;

bool allVisited() {
  for (const auto &_ : visited) if (!_) return false;
  return true;
}

int dfs(int v) {
  if (visited[v]) return 0;

  visited[v] = true;
  int cnt = 0;
  if (allVisited()) cnt = 1;
  else for (const int &to : G[v]) cnt += dfs(to);
  visited[v] = false;

  return cnt;
}

int main() {
  int N, M;
  cin >> N >> M;

  G.resize(N);
  visited.resize(N);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }

  cout << dfs(0) << endl;
}

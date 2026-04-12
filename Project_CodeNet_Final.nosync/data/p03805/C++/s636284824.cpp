#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > G;

int dfs(int v, vector<bool> &visited) {
  bool flag = true;
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      flag = false;
      break;
    }
  }
  if (flag) return 1;
  int result = 0;
  for (int i = 0; i < G[v].size(); i++) {
    int to = G[v][i];
    if (!visited[to]) {
      visited[to] = true;
      result += dfs(to, visited);
      visited[to] = false;
    }
  }
  return result;
}

int main() {
  cin >> N >> M;
  G.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> visited(N, false);
  visited[0] = true;
  cout << dfs(0, visited) << endl;

  return 0;
}

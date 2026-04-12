#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> vertex;
int ans;

void Dfs(int u) {
  vertex[u] = true;
  int visit = 0;
  for (int i = 0; i < N; i++) if (vertex[i]) visit++;
  if (visit == N) ans++;
  for (int i = 0; i < N; i++) if (graph[u][i] && !vertex[i]) Dfs(i);
  vertex[u] = false;
}

int main() {
  cin >> N >> M;
  graph.resize(N, vector<int>(N)), vertex.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1][b - 1]++;
    graph[b - 1][a - 1]++;
  }
  Dfs(0);
  cout << ans << endl;
  return 0;
}
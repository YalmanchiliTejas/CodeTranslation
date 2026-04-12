#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
using Graph = vector<vector<int> >;
bool all_visited;

// visitedは訪問回数
int dfs(Graph &G, int v, bool visited[]) {
  bool all_visited = true;
  for (int i = 0; i < N; i++) {
    if (visited[i] == false) all_visited = false;
  }

  if (all_visited) return 1;
  int ans = 0;

  for (auto next_v : G[v]) {
    if (visited[next_v]) continue;
    visited[next_v] = true;
    ans += dfs(G, next_v, visited);
    visited[next_v] = false;
  }

  return ans;
}

int main() {
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bool visited[N];
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
  }

  visited[0] = true;
  cout << dfs(G,0,visited) << endl;
  return 0;
}
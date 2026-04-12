#include <iostream>
using namespace std;

constexpr int MAX_N = 8;

bool graph[MAX_N+1][MAX_N+1];
bool visited[MAX_N+1];
int N, M;

int dfs(int v) {
  bool all{true};
  for (int i{1}; i <= N; ++i) {
    if (!visited[i]) {
      all = false;
      break;
    }
  }
  if (all) return 1;

  int count{};
  for (int i{1}; i <= N; ++i) {
    if (!graph[v][i] || visited[i]) continue;

    visited[i] = true;
    count += dfs(i);
    visited[i] = false;
  }

  return count;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i{}; i < M; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    graph[a][b] = graph[b][a] = true;
  }

  visited[1] = true;
  printf("%d\n", dfs(1));
}

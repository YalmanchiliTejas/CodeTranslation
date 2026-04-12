#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

bool graph[8][8];

int dfs(int v, int N, bool visited[8]) {
  bool all_visited = true;
  for (int i = 0; i < N; i++) {
    if (visited[i] == false) {
      all_visited = false;
    }
  }
  if (all_visited) {
    return 1;
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    if (graph[v][i] == false) {
      continue;
    }
    if (visited[i] == true) {
      continue;
    }
    visited[i] = true;
    ret += dfs(i, N, visited);
    visited[i] = false;
  }
  return ret;
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1][b - 1] = graph[b - 1][a - 1] = true;
  }
  bool visited[N];
  for (int i = 0; i < N; i++) {
    visited[i] = false;
  }
  visited[0] = true;
  cout << dfs(0, N, visited) << endl;
  return 0;
}
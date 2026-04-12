#include <bits/stdc++.h>

using namespace std;
const int NMAX = 8;
const int MMAX = (NMAX * (NMAX - 1)) / 2;
bool graph[NMAX][NMAX];
int N, M;

int dfs(int v, bool visited[NMAX]) {
  bool isValid = true;
  for (int i = 0; i < N; ++i) {
    if (!visited[i]) isValid = false;
  }
  
  if (isValid) return 1;
  int ret = 0;
  for (int i = 1; i < N; ++i) {
    if (!graph[v][i]) continue;
    if (visited[i]) continue;
    visited[i] = true;
    ret += dfs(i, visited);
    visited[i] = false;
  }

  return ret;
}

int main() {
  cin >> N >> M;
  vector<int> a(M);
  vector<int> b(M);
  for (int i = 0; i < M; ++i) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    graph[a[i]][b[i]] = true;
    graph[b[i]][a[i]] = true;
  }
  bool visited[NMAX];
  for (int i = 0; i < NMAX; ++i) visited[i] = false;
  visited[0] = true;
  cout << dfs(0, visited) << endl;
  return 0;
}


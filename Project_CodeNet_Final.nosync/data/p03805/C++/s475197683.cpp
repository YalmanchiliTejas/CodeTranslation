#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int nmax = 8;
vector<vector<bool>> graph(nmax, vector<bool>(nmax));

int dfs(int v, int n, vector<bool>visited) {

  bool all_visited = true;

  rep(i, n) {
    if (visited[i] == false) {
      all_visited = false;
    }
  }

  if (all_visited) {
    return 1;
  }

  int ret = 0;
  rep(i, n) {
    if(graph[v][i] == false) continue;
    if(visited[i]) continue;

    visited[i] = true;
    ret += dfs(i, n, visited);
    visited[i] = false;
  }

  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  rep(i, m) {
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = true;
  }

  vector<bool> visited(nmax, false);

  visited[0] = true;
  cout << dfs(0, n, visited) << endl;

  return 0;
}
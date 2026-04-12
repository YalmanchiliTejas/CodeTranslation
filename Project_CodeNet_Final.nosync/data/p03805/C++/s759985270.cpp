#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

constexpr int N_MAX = 8;
bool graph[N_MAX][N_MAX];

int dfs(int v, int n, bool* visited) {
  int count = 0;
  rep(i, n) { if (visited[i]) count++; }
  if (count == n) return 1;

  int result = 0;
  rep(i, n) {
    if (graph[v][i] == false) continue;
    if (visited[i]) continue;

    visited[i] = true;
    result += dfs(i, n, visited);
    visited[i] = false;
  }
  return result;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(20);

  int n, m;
  cin >> n >> m;
  rep(i, m) {
    int a, b;
    cin >> a >> b; --a; --b;
    graph[a][b] = graph[b][a] = true;
  }

  bool visited[n] {};
  fill(visited, visited+n, false);
  visited[0] = true;
  cout << dfs(0, n, visited) << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll paths = 0;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int current) {
  bool ok = true;
  for (ll i = 0; i < visited.size(); i++) {
    if (visited[i] == false) {
      ok = false;
      break;
    }
  }

  if (ok) {
    paths++;
    return;
  }

  visited[current] = true;
  for (ll i = 0; i < graph[0].size(); i++) {
    if (graph[current][i] == 1 && visited[i] == false) {
      visited[i] = true;
      dfs(graph, visited, i);
      visited[i] = false;
    }
  }
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N, vector<int>(N, 0));
  for (ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    graph[a - 1][b - 1] = 1;
    graph[b - 1][a - 1] = 1;
  }

  vector<bool> visited(N, false);

  dfs(graph, visited, 0);

  cout << paths << endl;
}
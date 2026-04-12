#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

typedef long long ll;

void dfs(vector<vector<ll>> &graph, vector<bool> &visited, ll current, ll &count){
  visited[current] = true;

  bool all_passed = true;
  for (auto v : visited) {
    if (v == false) {
      all_passed = false;
      break;
    }
  }

  if (all_passed) {
    visited[current] = false;
    count++;
    return;
  }

  for (auto n : graph[current]) {
    if (visited[n]) continue;

    dfs(graph, visited, n, count);
  }
  visited[current] = false;
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> graph(N);
  for (ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    graph[a-1].push_back(b-1);
    graph[b-1].push_back(a-1);
  }

  vector<bool> visited(N, false);
  ll count = 0;
  dfs(graph, visited, 0, count);

  cout << count << endl;
  return 0;
}

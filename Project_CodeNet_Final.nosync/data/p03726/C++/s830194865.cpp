#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

vector<vector<Edge>> ReadUndirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge(v1, v2));
    graph[v2].push_back(Edge(v2, v1));
  }
  return graph;
}

bool Solve() {
  int n;
  cin >> n;

  auto graph = ReadUndirectedGraph(n, n - 1, true);

  if (n % 2 == 1) {
    return true;
  }

  if (n == 2) {
    return false;
  }

  vector<int> degrees(n);
  for (int v = 0; v < n; v++) {
    degrees[v] = graph[v].size();
  }
  vector<int> removed(n);

  queue<int> q;
  for (int v = 0; v < n; v++) {
    if (degrees[v] == 1) {
      q.push(v);
    }
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (removed[v]) {
      continue;
    }
    int p = -1;
    for (const auto& e : graph[v]) {
      if (removed[e.to]) {
        continue;
      }
      p = e.to;
    }

    if (p == -1) {
      return true;
    }

    vector<int> us;
    for (const auto& e : graph[v]) {
      if (removed[e.to]) continue;
      if (e.to == p) continue;
      us.push_back(e.to);
    }
    for (const auto& e : graph[p]) {
      if (removed[e.to]) continue;
      if (e.to == v) continue;
      us.push_back(e.to);
    }

    for (int u : us) {
      degrees[u]--;
      if (degrees[u] == 1) {
        q.push(u);
      }
    }
    degrees[v] = 0;
    degrees[p] = 0;
    removed[v] = true;
    removed[p] = true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  if (Solve()) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
}
#include <bits/stdc++.h>

using namespace std;

int n;
unordered_map<int, vector<int>> edge;
vector<int> visited;
set<pair<int, int>> used;

bool filled() {
  for (int i = 1; i <= n; ++i) {
    if (visited[i] == 0) return false;
  }
  return true;
}

void dfs(int from, function<void()> f) {
  visited[from] = 1;
  if (filled()) {
    f();
  }
  for (auto &e : edge[from]) {
    if (visited[e] == 1)
      continue;
    used.insert(make_pair(from, e));
    dfs(e, f);
    used.erase(make_pair(from, e));
  }
  visited[from] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    edge[from].push_back(to);
    edge[to].push_back(from);
  }

  int ans = 0;
  set<set<pair<int, int>>> pattern;
  visited.resize(n + 1);
  for (auto &e : visited) {
    e = 0;
  }
  used.clear();
  dfs(1, [&]() {
      set<pair<int, int>> p;
      for (auto& e : used) {
        if (e.first < e.second) {
          p.insert(make_pair(e.first, e.second));
          // cout << e.first << "->" << e.second << ", ";
        } else {
          p.insert(make_pair(e.second, e.first));
          // cout << e.second << "->" << e.first << ", ";
        }
      }
      pattern.insert(p);
      cout << "\n";
    });
  cout << pattern.size() << "\n";
}

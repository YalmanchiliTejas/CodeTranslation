#include <bits/stdc++.h>
using namespace std;

class Increase {
public:
  int n, flowMax = 1000000;
  vector<map<int, int>> p;
  vector<int> parent;
  vector<int> stack;

  Increase(int n, vector<map<int, int>> &p) : n(n), p(p) { parent.resize(n); }

  int dfs(int id, int from, int flow) {
    if (parent[id] != id)
      return 0;
    stack.push_back(id);
    parent[id] = from;
    if (id == n - 1)
      return flow;
    for (auto &v : p[id])
      if (v.second > 0) {
        int next = dfs(v.first, id, min(flow, v.second));
        if (next > 0)
          return next;
      }
    return 0;
  }

  int solve() {
    int ret = 0, flow;
    for (int i = 0; i < n; i++)
      parent[i] = i;

    while ((flow = dfs(0, -1, flowMax)) > 0) {
      int now = n - 1;
      ret += flow;
      while (parent[now] >= 0) {
        p[parent[now]][now] -= flow;
        p[now][parent[now]] += flow;
        now = parent[now];
      }
      for (auto &v : stack)
        parent[v] = v;
      stack.clear();
    }
    return ret;
  }
};

bool solve() {
  int n, m;
  cin >> n >> m;
  if (n == 0)
    return false;
  vector<map<int, int>> p(n + m + 2);
  int base = n + 1;
  int sink = n + m + 1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    p[a][base] = 1;
    p[b][base] = 1;
    p[base++][sink] = 1;
  }

  Increase flow(n + m + 2, p);
  int f = 0;
  int maxp = 1;
  for (; true; maxp++) {
    for (int i = 0; i < n; i++)
      flow.p[0][i + 1] += 1;
    f += flow.solve();
    if (f == m) {
      break;
    }
  }
  flow = Increase(n + m + 2, p);
  f = 0;
  int minp = 0;
  for (; true; minp++) {
    for (int i = 0; i < n; i++)
      flow.p[0][i + 1] += 1;
    f += flow.solve();
    if (f != n * (minp + 1)) {
      break;
    }
  }
  cout << minp << " " << maxp << endl;

  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}

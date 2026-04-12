#include <bits/stdc++.h>
using namespace std;
class disjoint_set {
  public:
    vector<int> rank, p;
    disjoint_set(){};
    disjoint_set (int size) {
      rank.resize(size, 0);
      p.resize(size, 0);
      for (int i = 0; i < size; i++) {
        makeSet(i);
      }
    }
    void makeSet (int x) {
      p[x] = x;
      rank[x] = 0;
    }
    bool same (int x, int y) {
      return find_set(x) == find_set(y);
    }
    void unite (int x, int y) {
      link(find_set(x), find_set(y));
    }
    void link (int x, int y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
    int find_set (int x) {
      if (x != p[x]) {
        p[x] = find_set(p[x]);
      }
      return p[x];
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  disjoint_set ds(n);
  vector<pair<int, int>> x(n);
  vector<pair<int, int>> y(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    x[i] = {a, i};
    y[i] = {b, i};
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  for (int i = 1; i < n; i++) {
    {
      int u, v, d;
      d = x[i].first - x[i - 1].first;
      u = x[i - 1].second;
      v = x[i].second;
      pq.push({d, {u, v}});
    }
    {
      int u, v, d;
      d = y[i].first - y[i - 1].first;
      u = y[i - 1].second;
      v = y[i].second;
      pq.push({d, {u, v}});
    }
  }
  int cnt = 0;
  int ans = 0;
  while (!pq.empty()) {
    auto e = pq.top();
    pq.pop();
    int dst = e.first;
    int one = e.second.first;
    int ant = e.second.second;
    if (ds.same(one, ant)) {
      continue;
    }
    ds.unite(one, ant);
    ans += dst;
  }
  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> oya(1e5 + 10);
vector<int> rnk(1e5 + 10);
void init(int n) {
  for (int i = 0; i < n; i++) {
    oya[i] = i;
    rnk[i] = 0;
  }
}
int find(int x) {
  if (oya[x] == x) return x;
  return oya[x] = find(oya[x]);
}
void unite(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    oya[x] = y;
  } else {
    oya[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}
bool same(int x, int y) {
  return find(x) == find(y);
}
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  struct town { int i; long long x, y; };
  int n; cin >> n;
  vector<town> t(n);
  for (int i = 0; i < n; i++) {
    t[i].i = i;
    cin >> t[i].x >> t[i].y;
  }
  struct edge { int from, to; long long cost; };
  vector<edge> e;
  sort(t.begin(), t.end(), [](auto a, auto b) { return a.x < b.x; });
  for (int i = 0; i < n - 1; i++) {
    e.push_back(edge{t[i].i, t[i + 1].i, min(abs(t[i + 1].x - t[i].x), abs(t[i + 1].y - t[i].y))});
  }
  sort(t.begin(), t.end(), [](auto a, auto b) { return a.y < b.y; });
  for (int i = 0; i < n - 1; i++) {
    e.push_back(edge{t[i].i, t[i + 1].i, min(abs(t[i + 1].x - t[i].x), abs(t[i + 1].y - t[i].y))});
  }
  sort(e.begin(), e.end(), [](auto a, auto b) { return a.cost < b.cost; });
  init(n);
  long long res = 0;
  for (auto i : e) {
    if (same(i.from, i.to)) continue;
    res += i.cost;
    unite(i.from, i.to);
  }
  cout << res << '\n';
  return 0;
}
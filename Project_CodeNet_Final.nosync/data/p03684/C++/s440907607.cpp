#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct point {
  int x, y, id;

  point(double _x = 0, double _y = 0) { x = _x; y = _y; }

  void read() {
    int a, b;
    cin >> a >> b;
    x = a; y = b;
  }

  int dist(point b) {
    int dx = abs(x - b.x);
    int dy = abs(y - b.y);
    return min(dx, dy);
  }

  bool operator < (const point &p) const {
    return x < p.x || x == p.x && y < p.y;
  }
};

int i, j, n, p[N];
long long rs;
point a[N], b[N];

int pfind(int x) { return p[x] == x ? x : p[x] = pfind(p[x]); }

void punite(int x, int y) { p[pfind(x)] = pfind(y); }

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n;
  for(i = 1; i <= n; ++i) a[i].read(), a[i].id = p[i] = i, b[i] = a[i];

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1, [](point a, point b) { return a.y < b.y || a.x == b.x && a.y < b.y; });

  set<pair<int, pair<int, int>>> S;

  for(i = 1; i < n; ++i) {
    S.insert(make_pair(a[i].dist(a[i + 1]), make_pair(a[i].id, a[i + 1].id)));
    S.insert(make_pair(b[i].dist(b[i + 1]), make_pair(b[i].id, b[i + 1].id)));
  }

  for(i = 1; i < n; ++i) {
    while(1) {
      if(!S.size()) break;
      auto it = *S.begin();
      if(pfind(it.second.first) != pfind(it.second.second)) break;
      S.erase(S.begin());
    }
    if(!S.size()) break;

    auto it = *S.begin();
    rs += it.first;
    punite(it.second.first, it.second.second);
  }

  cout << rs << '\n';

  return 0;
}
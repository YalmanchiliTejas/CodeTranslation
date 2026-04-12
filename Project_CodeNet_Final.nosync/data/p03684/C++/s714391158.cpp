#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

const int N = 1e5 + 5;

pair<int, int> points_x[N], points_y[N];

struct Point {
  int x, y, ind;
} points[N];

vector<int> adj[N];
int n;

bool vis[N];

int getDist(int i, int j) {
  int dx = points[i].x - points[j].x;
  int dy = points[i].y - points[j].y;
  return min(abs(dx), abs(dy));
}

Long Prim() {
  sort(points, points + n, [](const Point& i , const Point& j) {
    return i.ind < j.ind;
  });

  Long res = 0;

  priority_queue<pair<int, int>> q;
  q.emplace(0, 0);

  while (!q.empty()) {
    auto curr = q.top();
    q.pop();
    if (vis[curr.second]) continue;
    vis[curr.second] = true;
    res -= curr.first;

    for (int v : adj[curr.second]) {
      if (vis[v]) continue;
      q.emplace(-getDist(curr.second, v), v);
    }
  }

  return res;
}

void Build() {
  for (int k = 0; k < 2; ++k) {
    sort(points, points + n, [](const Point& i , const Point& j) {
      return make_pair(i.x,i.y) < make_pair(j.x,j.y);
    });

    for (int i = 0; i < n; ++i) {
      if (i + 1 < n) {
        adj[points[i].ind].push_back(points[i + 1].ind);
      }
      if (i > 0) {
        adj[points[i].ind].push_back(points[i - 1].ind);
      }
    }

    for (int i = 0; i < n; ++i) {
      swap(points[i].x, points[i].y);
    }
  }
}

int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

#ifdef Local
  freopen("test.in", "r", stdin);
#endif

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
    points[i].ind = i;
  }

  Build();
  cout << Prim();

}

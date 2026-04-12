#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
  int i = 0;
  map<int, int> visited;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<int>> ab(n, vector<int>(m));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ab[a].push_back(b);
    ab[b].push_back(a);
  }

  queue<Point> q;
  q.push({});

  int cnt = 0;
  while (!q.empty()) {
    Point p = q.front();
    q.pop();
    if (p.visited[p.i] > 0) continue;
    p.visited[p.i]++;
    if (p.visited.size() == n) {
      cnt++;
      continue;
    }
    for (int i = 0; i < ab[p.i].size(); i++) {
      q.push({i : ab[p.i][i], visited : p.visited});
    }
  }
  cout << cnt << endl;
}
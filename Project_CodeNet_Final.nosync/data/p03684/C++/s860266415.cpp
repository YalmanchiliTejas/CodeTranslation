/***********************************************
#
#      Filename: sol.cpp
#
#        Author: Comsyl - ylsong15@fudan.edu.cn
#   Description: ---
#        Create: 2017-06-30 22:24:50
***********************************************/
#include <bits/stdc++.h>
using namespace std;

struct point {
  int id, x, y;
};

struct edge {
  int u, v, val;
  edge(int u, int v, int val) : u(u), v(v), val(val) {}
  bool operator>(const edge& e) const {
    return val > e.val;
  }
};

vector<point> points;
priority_queue<edge, vector<edge>, greater<edge> > E;
vector<int> par;

int mabs(int x, int y) {
  return x > y ? x - y : y - x;
}

int root(int v) {
  return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) {
  if ((x = root(x)) == (y = root(y))) return ;
  if (par[x] > par[y]) swap(x, y);
  par[x] += par[y];
  par[y] = x;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int x, y;
  for (int i = 0; i < n; ++ i) {
    point p;
    cin >> p.x >> p.y;
    p.id = i;
    points.push_back(p);
  }

  sort(points.begin(), points.end(), [](const point& a, const point& b) -> bool {
    return a.x < b.x;
    });
  for (int i = 0; i + 1 < points.size(); ++ i) {
    int u = points[i].id;
    int v = points[i + 1].id;
    int val = mabs(points[i].x, points[i+1].x);
    E.push(edge(u, v, val));
  }

  sort(points.begin(), points.end(), [](const point& a, const point& b) -> bool {
    return a.y < b.y;
    });
  for (int i = 0; i + 1 < points.size(); ++ i) {
    int u = points[i].id;
    int v = points[i + 1].id;
    int val = mabs(points[i].y, points[i+1].y);
    E.push(edge(u, v, val));
  }

  par = vector<int> (n, -1);

  int count = 0;
  long long cost = 0;
  while (count < n - 1) {
    edge e = E.top(); E.pop(); // not const edge& e !
    if (root(e.u) == root(e.v)) continue;
    else {
      merge(e.u, e.v);
      cost += e.val;
      ++ count;
    }
  }

  cout << cost << endl;
  return 0;
}

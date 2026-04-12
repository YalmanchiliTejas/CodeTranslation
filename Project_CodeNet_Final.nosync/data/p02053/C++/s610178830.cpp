/*  -*- coding: utf-8 -*-
 *
 * 2953.cc: 
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_H = 30;
const int MAX_W = 30;
const int MAX_N = MAX_H * MAX_W;

/* typedef */

template <typename T>
struct Pt {
  T x, y;

  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt<T> &pt) : x(pt.x), y(pt.y) {}

  Pt<T> operator+(const Pt<T> pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt<T> pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt<T> v) const { return x * v.x + y * v.y; }
  T cross(Pt<T> v) const { return x * v.y - y * v.x; }

  bool operator==(const Pt<T> pt) const { return x == pt.x && y == pt.y; }
  bool operator<(const Pt<T> &pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }

  int md(const Pt<T> p) const { return abs(x - p.x) + abs(y - p.y); }

  void print() { printf("(%d,%d)", x, y); }
};

typedef Pt<int> pt;
typedef vector<pt> vpt;

/* global variables */

char s[MAX_W + 4];

/* subroutines */

// convex_hull()
//   make a convex_hull 'chs' from a set of points 'ps'
//   Note: ps must be sorted, and must contain at least 2 points
void convex_hull(const vpt& ps, vpt& chs) {
  int n = ps.size();
  vpt lhs, uhs;

  lhs.push_back(ps[0]);
  lhs.push_back(ps[1]);
  for (int i = 2; i < n; i++) {
    while (lhs.size() >= 2) {
      int ln = lhs.size();
      pt &lh0 = lhs[ln - 2], &lh1 = lhs[ln - 1];
      if ((lh1 - lh0).cross(ps[i] - lh1) > 0) break;
      lhs.pop_back();
    }
    lhs.push_back(ps[i]);
  }

  uhs.push_back(ps[n - 1]);
  uhs.push_back(ps[n - 2]);
  for (int i = n - 3; i >= 0; i--) {
    while (uhs.size() >= 2) {
      int un = uhs.size();
      pt &uh0 = uhs[un - 2], &uh1 = uhs[un - 1];
      if ((uh1 - uh0).cross(ps[i] - uh1) > 0) break;
      uhs.pop_back();
    }
    uhs.push_back(ps[i]);
  }

  lhs.pop_back();
  uhs.pop_back();

  chs.clear();
  chs.reserve(lhs.size() + uhs.size());
  chs.assign(lhs.begin(), lhs.end());
  chs.insert(chs.end(), uhs.begin(), uhs.end());
}

/* main */

int main() {
  int h, w;
  scanf("%d%d", &h, &w);

  vpt ps;
  for (int y = 0; y < h; y++) {
    scanf("%s", s);
    for (int x = 0; x < w; x++)
      if (s[x] == 'B') ps.push_back(pt(x, y));
  }

  vpt chs;
  convex_hull(ps, chs);
  //printf("ps=%lu, chs=%lu\n", ps.size(), chs.size());

  int maxd = 0, n = chs.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int d = chs[i].md(chs[j]);
      if (maxd < d) maxd = d;
    }

  printf("%d\n", maxd);
  return 0;
}


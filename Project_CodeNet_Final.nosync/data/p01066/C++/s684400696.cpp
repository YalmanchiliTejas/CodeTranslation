/*  -*- coding: utf-8 -*-
 *
 * 1581.cc: Reflection Warp Machine
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

const int MAX_N = 8;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;

/* typedef */

// typedefs

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

template <typename T>
struct Pt {
  T x, y;

  Pt() {}
  Pt(T _x, T _y) : x(_x), y(_y) {}
  Pt(const Pt<T> &pt) : x(pt.x), y(pt.y) {}

  bool operator==(const Pt<T> pt) const { return x == pt.x && y == pt.y; }
  Pt<T> operator+(const Pt<T> pt) const { return Pt<T>(x + pt.x, y + pt.y); }
  Pt<T> operator-() const { return Pt<T>(-x, -y); }
  Pt<T> operator-(const Pt<T> pt) const { return Pt<T>(x - pt.x, y - pt.y); }
  Pt<T> operator*(T t) const { return Pt<T>(x * t, y * t); }
  Pt<T> operator/(T t) const { return Pt<T>(x / t, y / t); }
  T dot(Pt<T> v) const { return x * v.x + y * v.y; }
  T cross(Pt<T> v) const { return x * v.y - y * v.x; }
  T d2() { return x * x + y * y; }

  Pt<T> rot90() { return Pt<T>(-y, x); }

  bool operator<(const Pt& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
  }

  void print() { printf("(%d,%d)", x, y); }
};

typedef Pt<int> pt;

struct UFT {
  int links[MAX_N], ranks[MAX_N], sizes[MAX_N];
  UFT() {}

  void init(int n) {
    for (int i = 0; i < n; i++) links[i] = i, ranks[i] = sizes[i] = 1;
  }

  int root(int i) {
    int i0 = i;
    while (links[i0] != i0) i0 = links[i0];
    return (links[i] = i0);
  }

  int rank(int i) { return ranks[root(i)]; }
  int size(int i) { return sizes[root(i)]; }
  bool same(int i, int j) { return root(i) == root(j); }

  int merge(int i0, int i1) {
    int r0 = root(i0), r1 = root(i1), mr;
    if (r0 == r1) return r0;
    if (ranks[r0] == ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      ranks[r0]++;
      mr = r0;
    }
    else if (ranks[r0] > ranks[r1]) {
      links[r1] = r0;
      sizes[r0] += sizes[r1];
      mr = r0;
    }
    else {
      links[r0] = r1;
      sizes[r1] += sizes[r0];
      mr = r1;
    }
    return mr;
  }
};

/* global variables */

pt ps[MAX_N], cs[MAX_M], vs[MAX_M];
vpii ess[MAX_M];
UFT uft;

/* subroutines */

void comb(int u, int k, int n, int bits, vi &cs) {
  if (k == 0) {
    cs.push_back(bits);
    return;
  }
  if (u >= n) return;

  for (int i = u, bi = 1 << i; i < n; i++, bi <<= 1)
    comb(i + 1, k - 1, n, bits | bi, cs);
}

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    scanf("%d%d", &ps[i].x, &ps[i].y), ps[i] = ps[i] * 2;

  int m = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      pt c((ps[i] + ps[j]) / 2), v((ps[j] - ps[i]).rot90());
      int k = 0;
      for (; k < m; k++)
	if (vs[k].cross(v) == 0 && vs[k].cross(c - cs[k]) == 0)
	  break;
      if (k < m)
	ess[k].push_back(pii(i, j));
      else {
	cs[m] = c, vs[m] = v;
	ess[m++].push_back(pii(i, j));
      }
    }
  //printf("m=%d\n", m);

  for (int l = 1; l <= n - 2; l++) {
    vi cs;
    comb(0, l, m, 0, cs);

    for (vi::iterator vit = cs.begin(); vit != cs.end(); vit++) {
      int &bits = *vit;
      uft.init(n);

      for (int i = 0, bi = 1; i < m; i++, bi <<= 1)
	if (bits & bi) {
	  vpii &es = ess[i];
	  for (vpii::iterator eit = es.begin(); eit != es.end(); eit++)
	    uft.merge(eit->first, eit->second);
	}

      if (uft.size(0) == n) {
	printf("%d\n", l);
	return 0;
      }
    }
  }

  printf("%d\n", n - 1);
  return 0;
}


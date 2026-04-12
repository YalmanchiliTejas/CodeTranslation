/*  -*- coding: utf-8 -*-
 *
 * j.cc: J - Segment Tree
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

const int MAX_N = 200000;
const int MAX_E2 = 1 << 19; // = 524288

/* typedef */

template <typename T, const int MAX_E2>
struct SegTreeMax {
  int e2;
  T nodes[MAX_E2], defv;
  SegTreeMax() {}

  void init(int n, T _defv) {
    defv = _defv;
    for (e2 = 1; e2 < n; e2 <<= 1);
    fill(nodes, nodes + MAX_E2, defv);
  }

  T &get(int i) { return nodes[e2 - 1 + i]; }
  void seti(int i, T v) { get(i) = v; }

  void setall() {
    for (int j = e2 - 2; j >= 0; j--)
      nodes[j] = max(nodes[j * 2 + 1], nodes[j * 2 + 2]);
  }

  void set(int i, T v) {
    int j = e2 - 1 + i;
    nodes[j] = v;
    while (j > 0) {
      j = (j - 1) / 2;
      nodes[j] = max(nodes[j * 2 + 1], nodes[j * 2 + 2]);
    }
  }

  T max_range(int r0, int r1, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return defv;
    if (r0 <= i0 && i1 <= r1) return nodes[k];

    int im = (i0 + i1) / 2;
    T v0 = max_range(r0, r1, k * 2 + 1, i0, im);
    T v1 = max_range(r0, r1, k * 2 + 2, im, i1);
    return max(v0, v1);
  }
  T max_range(int r0, int r1) { return max_range(r0, r1, 0, 0, e2); }
};

/* global variables */

SegTreeMax<int,MAX_E2> st;

/* subroutines */

/* main */

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  st.init(n, 0);

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    st.seti(i, ai);
  }
  st.setall();

  while (q--) {
    int op, x, v;
    scanf("%d%d%d", &op, &x, &v);
    x--;

    if (op == 1) {
      st.set(x, v);
    }
    else if (op == 2) {
      int ma = st.max_range(x, v);
      printf("%d\n", ma);
    }
    else {
      int l = x, r = n;
      if (st.max_range(l, r) < v) printf("%d\n", n + 1);
      else {
	while (l + 1 < r) {
	  int m = (l + r) / 2;
	  if (st.max_range(l, m) >= v) r = m;
	  else l = m;
	}
	printf("%d\n", l + 1);
      }
    }
  }
  return 0;
}

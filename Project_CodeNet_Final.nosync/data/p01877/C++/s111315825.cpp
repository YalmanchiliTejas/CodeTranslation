/*  -*- coding: utf-8 -*-
 *
 * 2777.cc: Kitsuchiri
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

const int MAX_N = 500000;
const int MAX_M = MAX_N / 2; // = 250000
const int MAX_E2 = 1 << 19;  // = 524288
const int INF = 1 << 30;

/* typedef */

template <typename T, const int MAX_E2>
struct SegTreeSumMinMax {
  int n, e2, inf;
  T sums[MAX_E2], mins[MAX_E2], maxs[MAX_E2], ds[MAX_E2];
  SegTreeSumMinMax() {}

  void init(int _n, int _inf) {
    n = _n, inf = _inf;
    for (e2 = 1; e2 < n; e2 <<= 1);
    fill(sums, sums + MAX_E2, 0);
    fill(mins, mins + MAX_E2, inf);
    fill(maxs, maxs + MAX_E2, -inf);
    fill(ds, ds + MAX_E2, 0);
  }

  void set(int i, T v) { sums[e2 - 1 + i] = v; }
  
  void setall() {
    for (int i = e2 * 2 - 2; i >= e2 - 1; i--)
      mins[i] = maxs[i] = sums[i];
    for (int i = e2 - 2; i >= 0; i--) {
      int i0 = i * 2 + 1, i1 = i0 + 1;
      sums[i] = sums[i0] + sums[i1];
      mins[i] = min(mins[i0], mins[i1]);
      maxs[i] = max(maxs[i0], maxs[i1]);
    }
  }
  
  void add_range(int r0, int r1, T v, int k, int i0, int i1) {
    if (r1 <= i0 || i1 <= r0) return;
    if (r0 <= i0 && i1 <= r1) {
      sums[k] += v, mins[k] += v, maxs[k] += v, ds[k] += v;
      return;
    }

    int im = (i0 + i1) / 2, k0 = k * 2 + 1, k1 = k0 + 1;
    if (ds[k] != 0) {
      sums[k0] += ds[k], mins[k0] += ds[k], maxs[k0] += ds[k], ds[k0] += ds[k];
      sums[k1] += ds[k], mins[k1] += ds[k], maxs[k1] += ds[k], ds[k1] += ds[k];
      ds[k] = 0;
    }

    add_range(r0, r1, v, k0, i0, im);
    add_range(r0, r1, v, k1, im, i1);

    sums[k] = sums[k0] + sums[k1];
    mins[k] = min(mins[k0], mins[k1]);
    maxs[k] = max(maxs[k0], maxs[k1]);
  }
  void add_range(int r0, int r1, T v) { add_range(r0, r1, v, 0, 0, e2); }
};

/* global variables */

int as[MAX_N];
SegTreeSumMinMax<int,MAX_E2> st;

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);

  int m = n / 2;

  st.init(m, INF);
  for (int i = 0; i < m; i++) st.set(i, as[i] - as[n - 1 - i]);
  st.setall();

  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    l--;

    if (r <= m) st.add_range(l, r, x);
    else if (m <= l) st.add_range(n - r, n - l, -x);
    else {
      int l0 = m - l, r0 = r - m;
      if (l0 > r0) st.add_range(l, n - r, x);
      else if (l0 < r0) st.add_range(n - r, l, -x);
    }

    printf("%d\n", (st.mins[0] == 0 && st.maxs[0] == 0) ? 1 : 0);
  }
  return 0;
}


/*  -*- coding: utf-8 -*-
 *
 * 2964.cc: Restore Shortest Path
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
#include<unistd.h>
 
using namespace std;

/* constant */

const int MAX_N = 300;
const int INF = 1 << 29;

/* typedef */

typedef pair<int,int> pii;

/* global variables */

int ds[MAX_N][MAX_N], xs[MAX_N];
pii ps[MAX_N];

/* subroutines */

int getdist(int i, int j) {
  if (ds[i][j] > 0) return ds[i][j];

  printf("? %d %d\n", i + 1, j + 1); fflush(stdout);

  int d;
  scanf("%d", &d);
  if (d < 0) exit(0);
  ds[i][j] = ds[j][i] = d;
  return d;
}

/* main */

int main() {
  int n, st, gl;
  scanf("%d%d%d", &n, &st, &gl);
  st--, gl--;

  //for (int i = 0; i < n; i++) fill(ds[i], ds[i] + n, INF);
  int gd = getdist(st, gl);

  ps[0] = pii(0, st), ps[1] = pii(gd, gl);
  int m = 2;

  for (int i = 0; i < n; i++)
    if (i != st && i != gl) {
      int d0 = getdist(st, i), d1 = getdist(i, gl);
      if (d0 + d1 == gd) ps[m++] = pii(d0, i);
    }
  sort(ps, ps + m);

  xs[0] = st;
  int pd = 0, px = st, k = 1;

  for (int i = 1; i < m; i++) {
    int di = ps[i].first, xi = ps[i].second;
    int dd = getdist(px, xi);
    if (pd + dd == di) {
      xs[k++] = xi;
      pd = di;
      px = xi;
    }
  }

  putchar('!');
  for (int i = 0; i < k; i++) printf(" %d", xs[i] + 1);
  putchar('\n'); fflush(stdout);

  //sleep(1);
  return 0;
}


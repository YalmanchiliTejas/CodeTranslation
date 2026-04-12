/*  -*- coding: utf-8 -*-
 *
 * 1390.cc: Arithmetic Progressions
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

const int MAX_N = 5000;
const int MAX_M = MAX_N * MAX_N / 2;

/* typedef */

typedef pair<int,int> pii;

/* global variables */

int vs[MAX_N];
pii ps[MAX_M];
bool used[MAX_M];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", vs + i);
  sort(vs, vs + n);

  int m = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ps[m++] = pii(vs[j] - vs[i], vs[i]);
  sort(ps, ps + m);

  int maxc = 0;
  for (int i = 0; i < m; i++)
    if (! used[i]) {
      used[i] = true;
      int c = 2, j = i;
      for (;;) {
	pii pj(ps[j].first, ps[j].first + ps[j].second);
	j = lower_bound(ps, ps + m, pj) - ps;
	if (j >= m || ps[j] != pj) break;
	c++;
	used[j] = true;
      }

      if (maxc < c) maxc = c;
    }
  printf("%d\n", maxc);
  return 0;
}


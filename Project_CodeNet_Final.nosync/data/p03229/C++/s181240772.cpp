/*  -*- coding: utf-8 -*-
 *
 * c.cc: C: Align
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

const int MAX_N = 100000;

/* typedef */

typedef long long ll;

/* global variables */

int as[MAX_N], ps[MAX_N], qs[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", as + i);
  sort(as, as + n);

  for (int i = 0; i < n - 1; i++) {
    if (i & 1) ps[i + 1]++, ps[i]--, qs[i]++, qs[i + 1]--;
    else ps[i]++, ps[i + 1]--, qs[i + 1]++, qs[i]--;
  }
  sort(ps, ps + n);
  sort(qs, qs + n);

  ll sump = 0, sumq;
  for (int i = 0; i < n; i++) {
    sump += ps[i] * as[i];
    sumq += qs[i] * as[i];
  }

  printf("%lld\n", max(sump, sumq));
  return 0;
}

/*  -*- coding: utf-8 -*-
 *
 * 2840.cc: Unique Subsequence
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

/* typedef */

/* global variables */

char t[MAX_N + 4], p[MAX_N + 4];
int as[MAX_N], bs[MAX_N];

/* subroutines */

/* main */

int main() {
  scanf("%s%s", t, p);
  int m = strlen(t), n = strlen(p);

  int an = 0;
  for (int i = 0; i < m && an < n; i++)
    if (t[i] == p[an]) as[an++] = i;
  if (an < n) {
    puts("no");
    return 0;
  }

  int bn = n - 1;
  for (int i = m - 1; i >= 0 && bn >= 0; i--)
    if (t[i] == p[bn]) bs[bn--] = i;

  bool ok = true;
  for (int i = 0; ok && i < n; i++)
    ok = (as[i] == bs[i]);

  if (ok) puts("yes");
  else puts("no");
  return 0;
}


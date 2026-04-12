/*  -*- coding: utf-8 -*-
 *
 * 2938.cc: 
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

/* global variables */

bool ts[MAX_N];

/* subroutines */

inline bool m(bool a, bool b) { return (! a || b); }

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    char s[4];
    scanf("%s", s);
    ts[i] = (s[0] == 'T');
  }

  bool t = ts[0];
  for (int i = 1; i < n; i++) t = m(t, ts[i]);

  putchar(t ? 'T' : 'F');
  putchar('\n');
  return 0;
}


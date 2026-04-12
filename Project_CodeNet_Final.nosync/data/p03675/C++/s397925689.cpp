/*  -*- coding: utf-8 -*-
 *
 * a.cc: C: pushpush
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

/* typedef */

/* global variables */

int as[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", &as[i]);

  bool cont = false;
  for (int i = n - 1; i >= 0; i -= 2) {
    if (cont) putchar(' ');
    printf("%d", as[i]);
    cont = true;
  }
  for (int i = (n & 1); i < n; i += 2) {
    if (cont) putchar(' ');
    printf("%d", as[i]);
    cont = true;
  }
  putchar('\n');

  return 0;
}

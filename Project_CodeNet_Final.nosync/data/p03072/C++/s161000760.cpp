/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: Great Ocean View
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

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int maxh = 0, c = 0;
  for (int i = 0; i < n; i++) {
    int h;
    scanf("%d", &h);
    if (maxh <= h) c++, maxh = h;
  }

  printf("%d\n", c);
  return 0;
}

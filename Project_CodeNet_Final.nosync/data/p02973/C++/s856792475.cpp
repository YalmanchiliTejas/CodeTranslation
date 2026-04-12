/*  -*- coding: utf-8 -*-
 *
 * e.cc: E - Sequence Decomposing
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

typedef deque<int> di;

/* global variables */

di bs;

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);

    int k = lower_bound(bs.begin(), bs.end(), ai) - bs.begin() - 1;
    if (k < 0)
      bs.push_front(ai);
    else
      bs[k] = ai;
  }

  printf("%lu\n", bs.size());
  return 0;
}

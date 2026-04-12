/*  -*- coding: utf-8 -*-
 *
 * 2921.cc: Working
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

const int INF = 1 << 30;

/* typedef */

/* global variables */

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  int minave = INF, sum = 0;
  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);
    sum += ai;
    int ave = sum / (i + 1);
    if (minave > ave) minave = ave;
  }

  printf("%d\n", minave);
  return 0;
}


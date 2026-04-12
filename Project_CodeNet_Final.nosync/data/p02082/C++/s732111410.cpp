/*  -*- coding: utf-8 -*-
 *
 * 2982.cc: Expensive Function
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
  int s, t, p, q, m, y;
  scanf("%d%d%d%d%d%d", &s, &t, &p, &q, &m, &y); 

  printf("%d\n", t ^ s ^ y);
  return 0;
}


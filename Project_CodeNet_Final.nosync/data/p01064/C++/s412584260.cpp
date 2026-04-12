/*  -*- coding: utf-8 -*-
 *
 * 1579.cc: Array Update 2
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

const int MAX_M = 200000;

/* typedef */

struct Op {
  int x, y, z;
  Op() {}
  Op(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
};

/* global variables */

Op ops[MAX_M];
int xs[MAX_M];

/* subroutines */

/* main */

int main() {
  int n, a, d, m;
  scanf("%d%d%d%d", &n, &a, &d, &m);

  for (int i = 0; i < m; i++)
    scanf("%d%d%d", &ops[i].x, &ops[i].y, &ops[i].z);

  int k;
  scanf("%d", &k);

  int l = 0;
  for (int i = m - 1; i >= 0; i--) {
    Op &op = ops[i];
    if (op.y <= k && k <= op.z) {
      if (op.x != 0)
	xs[l++] = op.x;
      else
	k = op.z - (k - op.y);
    }
  }
  //printf("l=%d, k=%d\n", l, k);

  int v = a + d * (k - 1);
  for (int i = l - 1; i >= 0; i--) {
    if (xs[i] == 1) v++;
    else v >>= 1;
  }

  printf("%d\n", v);
  return 0;
}


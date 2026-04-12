/*  -*- coding: utf-8 -*-
 *
 * b.cc: B: Grid Compression
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

const int MAX_H = 100;
const int MAX_W = 100;

/* typedef */

/* global variables */

char flds[MAX_H][MAX_W + 4];
bool uys[MAX_H], uxs[MAX_W];

/* subroutines */

/* main */

int main() {
  int h, w;
  scanf("%d%d", &h, &w);

  for (int y = 0; y < h; y++) {
    scanf("%s", flds[y]);
    for (int x = 0; x < w; x++)
      if (flds[y][x] == '#') uys[y] = uxs[x] = true;
  }

  for (int y = 0; y < h; y++)
    if (uys[y]) {
      for (int x = 0; x < w; x++)
	if (uxs[x]) putchar(flds[y][x]);
      putchar('\n');
    }
  return 0;
}

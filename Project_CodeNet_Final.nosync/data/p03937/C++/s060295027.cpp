/*  -*- coding: utf-8 -*-
 *
 * a.cc: 
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

const int MAX_H = 8;
const int MAX_W = 8;

/* typedef */

/* global variables */

string as[MAX_H];
bool bs[MAX_H][MAX_W];

/* subroutines */

void impossible() {
  puts("Impossible");
  exit(0);
}

/* main */

int main() {
  int h, w;
  cin >> h >> w;
  for (int y = 0; y < h; y++) cin >> as[y];

  if (as[0][0] != '#') impossible();
  bs[0][0] = true;

  int x = 0, y = 0;
  while (x != w - 1 || y != h - 1) {
    if (x < w - 1 && as[y][x + 1] == '#')
      bs[y][++x] = true;
    else if (y < h - 1 && as[y + 1][x] == '#')
      bs[++y][x] = true;
    else
      impossible();
  }

  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if ((bs[y][x] && as[y][x] == '.') || (! bs[y][x] && as[y][x] == '#'))
	impossible();

  puts("Possible");
  return 0;
}

/*  -*- coding: utf-8 -*-
 *
 * f.cc: F - I hate Matrix Construction
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

const int MAX_N = 500;
const int BN = 64;

enum { AND0 = 0, AND1 = 1, OR0 = 2, OR1 = 3 };
enum { ND = 2, NG = 3 };

const int qm[4][4] = {
  //           AND0, AND1,  OR0,  OR1
  /* AND0 */ {    0,    1,    0,   ND },
  /* AND1 */ {    1,    1,   NG,    1 },
  /*  OR0 */ {    0,   NG,    0,    0 },
  /*  OR1 */ {   ND,    1,    0,    1 },
};

/* typedef */

typedef unsigned long long ull;

/* global variables */

int ss[MAX_N], ts[MAX_N], sus[MAX_N], tvs[MAX_N];
ull us[MAX_N], vs[MAX_N];
ull fs[MAX_N][MAX_N];
int fbs[MAX_N][MAX_N], hbs[MAX_N][2], vbs[MAX_N][2];

/* subroutines */

inline void setbit(int y, int x, int b) {
  fbs[y][x] = b, hbs[y][b]++, vbs[x][b]++;
}

/* main */

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) scanf("%d", ss + i);
  for (int i = 0; i < n; i++) scanf("%d", ts + i);
  for (int i = 0; i < n; i++) scanf("%llu", us + i);
  for (int i = 0; i < n; i++) scanf("%llu", vs + i);

  for (int k = 0; k < BN; k++) {
    memset(fbs, -1, sizeof(fbs));
    memset(hbs, 0, sizeof(hbs));
    memset(vbs, 0, sizeof(vbs));

    for (int i = 0; i < n; i++) {
      sus[i] = (ss[i] << 1) | (int)((us[i] >> k) & 1);
      tvs[i] = (ts[i] << 1) | (int)((vs[i] >> k) & 1);
    }

    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++) {
	int q = qm[sus[y]][tvs[x]];
	if (q == NG) { puts("-1"); return 0; }
	setbit(y, x, (q == ND) ? 0 : q);
      }

    for (int y = 0; y < n; y++)
      if (sus[y] == OR1 && hbs[y][1] == 0) {
	bool ok = false;
	for (int x = 0; ! ok && x < n; x++)
	  if (tvs[x] == AND0 && vbs[x][0] > 1) {
	    setbit(y, x, 1);
	    hbs[y][0]--, vbs[x][0]--;
	    ok = true;
	  }
	if (! ok) { puts("-1"); return 0; }
      }

    for (int x = 0; x < n; x++)
      if (tvs[x] == OR1 && vbs[x][1] == 0) {
	bool ok = false;
	for (int y = 0; ! ok && y < n; y++)
	  if (sus[y] == AND0 && hbs[y][0] > 1) {
	    setbit(y, x, 1);
	    hbs[y][0]--, vbs[x][0]--;
	    ok = true;
	  }
	if (! ok) { puts("-1"); return 0; }
      }

    for (int i = 0; i < n; i++)
      if ((sus[i] == AND0 && hbs[i][0] == 0) ||
	  (sus[i] == AND1 && hbs[i][0] > 0) ||
	  (sus[i] == OR0 && hbs[i][1] > 0) ||
	  (sus[i] == OR1 && hbs[i][1] == 0) ||
	  (tvs[i] == AND0 && vbs[i][0] == 0) ||
	  (tvs[i] == AND1 && vbs[i][0] > 0) ||
	  (tvs[i] == OR0 && vbs[i][1] > 0) ||
	  (tvs[i] == OR1 && vbs[i][1] == 0)) {
	puts("-1");
	return 0;
      }
    
    ull bk = 1ULL << k;
    for (int y = 0; y < n; y++)
      for (int x = 0; x < n; x++)
	if (fbs[y][x]) fs[y][x] |= bk;
  }

  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      if (x) putchar(' ');
      printf("%llu", fs[y][x]);
    }
    putchar('\n');
  }
  return 0;
}

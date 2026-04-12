/*  -*- coding: utf-8 -*-
 *
 * d.cc: D: Black and White Tree
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
const int INF = 1 << 30;

/* typedef */

typedef vector<int> vi;
typedef queue<int> qi;
typedef pair<int,int> pii;

/* global variables */

vi nbrs[MAX_N];
int cns[MAX_N], ps[MAX_N];
bool used[MAX_N];

/* subroutines */

/* main */

int main() {
  int n;
  scanf("%d", &n);

  if (n & 1) {
    puts("First");
    return 0;
  }

  for (int i = 0; i < n - 1; i++) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    ai--, bi--;
    nbrs[ai].push_back(bi);
    nbrs[bi].push_back(ai);
  }

  ps[0] = -1;
  queue<pii> q0;
  q0.push(pii(0, -1));
  while (! q0.empty()) {
    pii u = q0.front(); q0.pop();
    int &ui = u.first, &up = u.second;
    vi &nbru = nbrs[ui];
    cns[ui] = nbru.size() - (up >= 0 ? 1 : 0);
    
    for (vi::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
      int &vi = *vit;
      if (vi != up) {
	ps[vi] = ui;
	q0.push(pii(vi, ui));
      }
    }
  }
  //for (int i = 0; i < n; i++) printf("%d: ps=%d, cns=%d\n", i, ps[i], cns[i]);

  qi q1;
  for (int i = 0; i < n; i++)
    if (cns[i] == 0) q1.push(i);
  while (! q1.empty()) {
    int u = q1.front(); q1.pop();
    int &up = ps[u];
    if (up < 0) {
      if (! used[u]) {
	puts("First");
	return 0;
      }
      continue;
    }

    if (used[u]) {
      if (--cns[up] == 0) q1.push(up);
    }
    else {
      if (used[up]) {
	puts("First");
	return 0;
      }
      used[up] = true;
      if (-- cns[up] == 0) q1.push(up);
    }
  }

  puts("Second");
  return 0;
}

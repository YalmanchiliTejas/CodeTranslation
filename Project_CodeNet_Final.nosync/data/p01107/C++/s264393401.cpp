/*  -*- coding: utf-8 -*-
 *
 * 1622.cc: Go around the Labyrinth
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

const int MAX_H = 50;
const int MAX_W = 50;
const int MAX_N = MAX_H * MAX_W * 2;
const int INF = 1 << 30;

const int dxs[] = { 1, 0, -1, 0 }, dys[] = { 0, -1, 0, 1 };

/* typedef */

typedef pair<int,int> pii;
typedef vector<pii> vpii;

/* global variables */

vpii nbrs[MAX_N];
int minfs[MAX_N], flows[MAX_N][MAX_N], prvs[MAX_N];
char flds[MAX_H][MAX_W + 4];

/* subroutines */

inline int xy2p(int x, int y, int w) { return y * w + x; }

int maxflow(int st, int gl) {
  memset(flows, 0, sizeof(flows));
  int max_flow = 0;

  for (;;) {
    //printf("max_flow = %d, limit = %d\n", max_flow, limit);

    memset(prvs, -1, sizeof(prvs));
    prvs[st] = st;
    minfs[st] = INF;

    queue<int> q;
    q.push(st);

    while (! q.empty()) {
      int ui = q.front(); q.pop();

      if (ui == gl) break;
      vpii& nbru = nbrs[ui];
      for (vpii::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
        int vi = vit->first;
        int vc = vit->second - flows[ui][vi];
        if (prvs[vi] < 0 && vc > 0) {
          prvs[vi] = ui;
          minfs[vi] = (minfs[ui] < vc) ? minfs[ui] : vc;
          q.push(vi);
        }
      }
    }
    if (prvs[gl] < 0) break;

    int min_flow = minfs[gl];
    for (int j = gl; j != st;) {
      int i = prvs[j];
      flows[i][j] += min_flow;
      flows[j][i] -= min_flow;
      j = i;
    }

    max_flow += min_flow;
  }

  return max_flow;
}

/* main */

int main() {
  for (int h, w; scanf("%d%d", &h, &w) == 2 && h > 0;) {
    for (int y = 0; y < h; y++) scanf("%s", flds[y]);

    int n = h * w, n2 = n * 2;
    int st = xy2p(0, 0, w) + n;
    int gl0 = xy2p(w - 1, 0, w);
    int gl1 = xy2p(0, h - 1, w);
    int gl2 = xy2p(w - 1, h - 1, w);

    for (int i = 0; i < n2; i++) nbrs[i].clear();
    
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
	if (flds[y][x] == '.') {
	  int u0 = xy2p(x, y, w), u1 = u0 + n;
	  nbrs[u0].push_back(pii(u1, 1));
	  nbrs[u1].push_back(pii(u0, 0));

	  for (int di = 0; di < 4; di++) {
	    int vx = x + dxs[di], vy = y + dys[di];
	    if (vx >= 0 && vx < w && vy >= 0 && vy < h &&
		flds[vy][vx] == '.') {
	      int v0 = xy2p(vx, vy, w), v1 = v0 + n;
	      nbrs[v1].push_back(pii(u0, 1));
	      nbrs[u0].push_back(pii(v1, 0));
	      nbrs[u1].push_back(pii(v0, 1));
	      nbrs[v0].push_back(pii(u1, 0));
	    }
	  }
	}

    bool ok =
      (maxflow(st, gl0) >= 2 &&
       maxflow(st, gl1) >= 2 &&
       maxflow(st, gl2) >= 2);

    if (ok) puts("YES");
    else puts("NO");
  }
  
  return 0;
}


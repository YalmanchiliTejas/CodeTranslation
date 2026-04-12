#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
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
const int MAX_C = 50;
const int MAX_M = 50;
const int MAX_GN = 2 + MAX_H + (MAX_W + MAX_C + MAX_M + 3) * 2;

const int INF = 1 << 30;

/* typedef */

typedef vector<int> vi;

struct Edge {
  int i, c;

  Edge() {}
  Edge(int _i, int _c): i(_i), c(_c) {}
};

typedef vector<Edge> ve;

/* global variables */

int h, w, c, m, nw, nc, nm;
vi whs[MAX_W], cws[MAX_C], mcs[MAX_M];

ve nbrs[MAX_GN];
int gn, st, gl;
int minfs[MAX_GN], flows[MAX_GN][MAX_GN], prvs[MAX_GN];

/* subroutines */

void read_vi(vi& v) {
  int vn, d;

  v.clear();
  cin >> vn;
  for (int i = 0; i < vn; i++) {
    cin >> d;
    v.push_back(--d);
  }
}

int maxflow() {
  memset(flows, 0, sizeof(flows));
  int max_flow = 0;

  for (;;) {
    //printf("max_flow = %lld\n", max_flow);

    memset(prvs, -1, sizeof(prvs));
    prvs[st] = st;
    minfs[st] = INF;

    queue<int> q;
    q.push(st);

    while (! q.empty()) {
      int ui = q.front(); q.pop();

      if (ui == gl) break;
      ve& nbru = nbrs[ui];
      for (ve::iterator vit = nbru.begin(); vit != nbru.end(); vit++) {
        int vi = vit->i;
        int vc = vit->c - flows[ui][vi];
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
  for (;;) {
    cin >> h >> w >> c >> m >> nw >> nc >> nm;
    if (h < 0) break;

    for (int i = 0; i < w; i++) read_vi(whs[i]);
    for (int i = 0; i < c; i++) read_vi(cws[i]);
    for (int i = 0; i < m; i++) read_vi(mcs[i]);
    
    gn = 2 + h + (w + c + m + 3) * 2;
    st = gn - 2;
    gl = gn - 1;

    for (int i = 0; i < gn; i++) nbrs[i].clear();

    for (int i = 0; i < h; i++)
      nbrs[st].push_back(Edge(i, 1));

    int w0 = h;
    int w1 = w0 + w + 1;

    for (int i = 0; i < w; i++) {
      vi& whi = whs[i];
      for (vi::iterator vit = whi.begin(); vit != whi.end(); vit++) {
	nbrs[*vit].push_back(Edge(w0 + i, 1));
	nbrs[w0 + i].push_back(Edge(*vit, 0));
      }
    }
    for (int i = 0; i < h; i++) {
      nbrs[i].push_back(Edge(w0 + w, 1));
      nbrs[w0 + w].push_back(Edge(i, 0));
    }

    for (int i = 0; i < w; i++) {
      nbrs[w0 + i].push_back(Edge(w1 + i, 1));
      nbrs[w1 + i].push_back(Edge(w0 + i, 0));
    }
    nbrs[w0 + w].push_back(Edge(w1 + w, nw));
    nbrs[w1 + w].push_back(Edge(w0 + w, 0));

    int c0 = w1 + w + 1;
    int c1 = c0 + c + 1;

    for (int i = 0; i < c; i++) {
      vi& cwi = cws[i];
      for (vi::iterator vit = cwi.begin(); vit != cwi.end(); vit++) {
	nbrs[w1 + *vit].push_back(Edge(c0 + i, 1));
	nbrs[c0 + i].push_back(Edge(w1 + *vit, 0));
      }
      nbrs[w1 + w].push_back(Edge(c0 + i, 1));
      nbrs[c0 + i].push_back(Edge(w1 + w, 0));
    }
    for (int i = 0; i < w; i++) {
      nbrs[w1 + i].push_back(Edge(c0 + c, 1));
      nbrs[c0 + c].push_back(Edge(w1 + i, 0));
    }

    for (int i = 0; i < c; i++) {
      nbrs[c0 + i].push_back(Edge(c1 + i, 1));
      nbrs[c1 + i].push_back(Edge(c0 + i, 0));
    }
    nbrs[c0 + c].push_back(Edge(c1 + c, nc));
    nbrs[c1 + c].push_back(Edge(c0 + c, 0));

    int m0 = c1 + c + 1;
    int m1 = m0 + m + 1;

    for (int i = 0; i < m; i++) {
      vi& mci = mcs[i];
      for (vi::iterator vit = mci.begin(); vit != mci.end(); vit++) {
	nbrs[c1 + *vit].push_back(Edge(m0 + i, 1));
	nbrs[m0 + i].push_back(Edge(c1 + *vit, 0));
      }
      nbrs[c1 + c].push_back(Edge(m0 + i, 1));
      nbrs[m0 + i].push_back(Edge(c1 + c, 0));
    }
    for (int i = 0; i < c; i++) {
      nbrs[c1 + i].push_back(Edge(m0 + m, 1));
      nbrs[m0 + m].push_back(Edge(c1 + i, 0));
    }

    for (int i = 0; i < m; i++) {
      nbrs[m0 + i].push_back(Edge(m1 + i, 1));
      nbrs[m1 + i].push_back(Edge(m0 + i, 0));
    }
    nbrs[m0 + m].push_back(Edge(m1 + m, nm));
    nbrs[m1 + m].push_back(Edge(m0 + m, 0));

    for (int i = 0; i < m; i++)
      nbrs[m1 + i].push_back(Edge(gl, 1));
    nbrs[m1 + m].push_back(Edge(gl, nm));

    int max_flow = maxflow();
    cout << max_flow << endl;
  }

  return 0;
}
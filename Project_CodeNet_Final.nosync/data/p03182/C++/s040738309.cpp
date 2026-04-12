#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct seg {
  int start, end, value;
};


long long INF=1e18;

struct ST {

  vector<long long> t;
  vector<long long> lazy;
  int size;

  ST(int N) {
    size = N;
    t.assign(N*4+10, 0);
    lazy.assign(N*4+10, 0);
  }

  void push(int nodeid) {
    // push lazy[nodeid] to childs
    t[nodeid*2] += lazy[nodeid];
    t[nodeid*2+1] += lazy[nodeid];
    lazy[nodeid*2] += lazy[nodeid];
    lazy[nodeid*2+1] += lazy[nodeid];
    lazy[nodeid] = 0;
  }

  void update(int l, int r, int ql, int qr, int nodeid, long long addvalue) {
    if(ql > qr) return;
    if (l==ql && r==qr) {
      t[nodeid] += addvalue;
      lazy[nodeid] += addvalue;
    } else {
      push(nodeid);
      int m = (l + r) / 2;
      update(l, m, ql, min(m, qr), nodeid*2, addvalue);
      update(m+1, r, max(m+1, ql), qr, nodeid*2+1, addvalue);
      t[nodeid] = max( t[nodeid*2], t[nodeid*2+1] );
    }
  }

  long long query(int l, int r, int ql, int qr, int nodeid) {
    if (ql > qr) return -INF;
    if (l>=ql && r <=qr) return t[nodeid];
    push(nodeid);
    int m = (l+r) / 2;
    return max(
      query(l, m, ql, min(m, qr), nodeid*2),
      query(m+1, r, max(m+1, ql), qr, nodeid*2+1)
    );
  }
};

vector<seg> l;

int main() {

  int N, M;

  cin >> N >> M;

  l.resize(M);
  vector< vector<int> > open_seg(N+2), close_seg(N+2);
  ST st(N+2);


  for (auto i=0; i<M; i++) {
    cin >> l[i].start >> l[i].end >> l[i].value;
    open_seg[ l[i].start ].push_back(i);
    close_seg[ l[i].end ].push_back(i);
  }


  // st.update(0, N, 0, N, 1, -INF);

  for (int i=1; i<=N+1; i++) {
    for (auto segid: open_seg[i]) {
      st.update(0, N+1, 0, l[segid].start-1, 1, l[segid].value);
    }

    auto dp = st.query(0, N+1, 0, i-1, 1);
    st.update(0, N+1, i, i, 1, dp);

    for (auto segid: close_seg[i]) {
      st.update(0, N+1, 0, l[segid].start-1, 1, -l[segid].value);
    }

    if (i==N+1) cout << dp << endl;
  }

  return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cassert>
#include<ctime>
using namespace std;

#define mind(a,b) (a>b?b:a)
#define maxd(a,b) (a>b?a:b)
#define absd(x) (x<0?-(x):x)
#define pow2(x) ((x)*(x))
#define rep(i,n) for(int i=0; i<n; ++i)
#define repr(i,n) for(int i=n-1; i>=0; --i)
#define repl(i,s,n) for(int i=s; i<=n; ++i)
#define replr(i,s,n) for(int i=n; i>=s; --i)
#define repf(i,s,n,j) for(int i=s; i<=n; i+=j)
#define repe(e,obj) for(auto e : obj)

#define SP << " " <<
#define COL << " : " <<
#define COM << ", " <<
#define ARR << " -> " <<
#define PNT(STR) cout << STR << endl
#define POS(X,Y) "(" << X << ", " << Y << ")"
#define DEB(A) " (" << #A << ") " << A
#define DEBREP(i,n,val) for(int i=0; i<n; ++i) cout << val << " "; cout << endl
#define ALL(V) (V).begin(), (V).end()
#define INF 1000000007
#define INFLL 1000000000000000007LL
#define EPS 1e-9

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define P_TYPE int
typedef pair<P_TYPE, P_TYPE> P;
typedef pair<P, P_TYPE> PI;
typedef pair<P_TYPE, P> IP;
typedef pair<P, P> PP;
typedef priority_queue<P, vector<P>, greater<P> > pvqueue;

#define N 200007
#define LV 20

class SegmentTree {
  const static ll inf = (1LL << 31) - 1;

  int n0, n;
  ll *data, *lazy;
  int ids[2*LV], cur = 0;

  void update_ids(int l, int r) {
    int l0 = (l + n0), r0 = (r + n0);
    int lb = (l0 & -l0) >> 1, rb = (r0 & -r0) >> 1;
    l0 >>= 1; r0 >>= 1;
    cur = 0;
    while(l0 > 0 && l0 < r0) {
      if(!rb) ids[cur++] = r0;
      if(!lb) ids[cur++] = l0;
      lb >>= 1; rb >>= 1;
      l0 >>= 1; r0 >>= 1;
    }
    while(l0 > 0) {
      ids[cur++] = l0;
      l0 >>= 1;
    }
  }

  void propagates() {
    repr(i, cur) {
      int k = ids[i];

      ll v = lazy[k-1];
      if(v == 0) continue;

      lazy[2*k-1] += v; data[2*k-1] += v;
      lazy[2*k] += v; data[2*k] += v;
      lazy[k-1] = 0;
    }
  }

public:

  SegmentTree(int n) : n(n) {
    n0 = 1;
    while(n0 < n) n0 <<= 1;
    data = new ll[2*n0];
    lazy = new ll[2*n0];
    rep(i, 2*n0) data[i] = 0, lazy[i] = 0;
  }

  void update(int l, int r, ll x) {
    update_ids(l, r);
    propagates();

    int l0 = l + n0, r0 = r + n0;
    while(l0 < r0) {
      if(r0 & 1) {
        --r0;
        lazy[r0-1] += x; data[r0-1] += x;
      }
      if(l0 & 1) {
        lazy[l0-1] += x; data[l0-1] += x;
        ++l0;
      }
      l0 >>= 1; r0 >>= 1;
    }

    rep(i, cur) {
      int k = ids[i];
      data[k-1] = max(data[2*k-1], data[2*k]);
    }

  }

  ll query(int l, int r) {
    update_ids(l, r);
    propagates();

    int l0 = l + n0, r0 = r + n0;

    ll s = -inf;
    while(l0 < r0) {
      if(r0 & 1) {
        --r0;
        s = max(s, data[r0-1]);
      }
      if(l0 & 1) {
        s = max(s, data[l0-1]);
        ++l0;
      }
      l0 >>= 1; r0 >>= 1;
    }
    return s;
  }
};

int n, m;
vector<PI> v;
vector<P> s[N];

int main() {
  scanf("%d %d", &n, &m);
  rep(i, m) {
    int l, r, a; scanf("%d %d %d", &l, &r, &a); --l; --r;
    v.push_back(PI(P(l, r), a));
  }
  sort(ALL(v));
  SegmentTree st(n+1);
  int j = 0;
  ll d = 0;
  rep(i, n) {
    while(j < v.size() && v[j].first.first == i) {
      P &p = v[j].first; int a = v[j].second;
      st.update(p.first+1, p.second+1, -a);
      s[p.second+1].push_back(P(p.first, a));
      d += a;
      ++j;
    }

    ll v = st.query(0, i+1);
    st.update(i+1, i+2, d + v);

    repe(&p, s[i+1]) {
      int l = p.first, a = p.second;
      st.update(l+1, i+1, a);
      d -= a;
    }
  }
  cout << st.query(0, n+1) << endl;
  return 0;
}
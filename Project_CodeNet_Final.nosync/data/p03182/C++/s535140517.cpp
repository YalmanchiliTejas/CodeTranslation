#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
struct LazySegmentTree {
  ll identity = -1e18;

  ll merge(const ll& lhs, const ll& rhs) {
    return max(lhs, rhs);
  }

  int N;
  vector<ll> node, span;
  vector<bool> pend;

  LazySegmentTree() {}
  LazySegmentTree(int n) { init(vector<ll>(n, 0)); }
  LazySegmentTree(const vector<ll>& vec) { init(vec); }

  void init(const vector<ll>& vec) {
    int sz = vec.size();
    N = 1;
    while(N < sz) N *= 2;
    node.assign(2*N-1, identity);
    span.assign(2*N-1, 0);
    pend.assign(2*N-1, false);
    for(int i = 0; i < sz; i++) node[i+N-1] = vec[i];
    for(int i = N-2; i >= 0; i--) node[i] = merge(node[2*i+1], node[2*i+2]);
  }

  void propagate(int k, int l, int r) {
    if(!pend[k]) return;
    node[k] += span[k] / (r-l);
    if(r-l>1) {
      pend[2*k+1] = pend[2*k+2] = true;
      span[2*k+1] += span[k] / 2;
      span[2*k+2] += span[k] / 2;
    }
    pend[k] = false;
    span[k] = 0;
  }

  void update(int s, int t, ll x) {
    rec_update(s, t, x, 0, 0, N);
  }

  void rec_update(int s, int t, ll x, int k, int l, int r) {
    propagate(k, l, r);
    if(r <= s || t <= l) return;
    if(s <= l && r <= t) {
      pend[k] = true;
      span[k] += (r - l) * x;
      propagate(k, l, r);
      return;
    }
    rec_update(s, t, x, 2*k+1, l, (l+r)/2);
    rec_update(s, t, x, 2*k+2, (l+r)/2, r);
    node[k] = merge(node[2*k+1], node[2*k+2]);
  }

  ll query(int s, int t) {
    return rec_query(s, t, 0, 0, N);
  }

  ll rec_query(int s, int t, int k, int l, int r) {
    if(r <= s || t <= l) return identity;
    propagate(k, l, r);
    if(s <= l && r <= t) return node[k];
    ll lhs = rec_query(s, t, 2*k+1, l, (l+r)/2);
    ll rhs = rec_query(s, t, 2*k+2, (l+r)/2, r);
    return merge(lhs, rhs);
  }
};

void answer() {
  ll n, m; cin >> n >> m;
  struct Q {
    ll l, r, a;
    Q(ll l_, ll r_, ll a_) : l(l_), r(r_), a(a_) {}
    bool operator<(const Q& rhs) const { return r < rhs.r; }
  };
  vector<Q> qs;
  rep(i,m) {
    ll l, r, a; cin >> l >> r >> a;
    qs.emplace_back(Q(l, r, a));
  }
  sort(ALL(qs));
  LazySegmentTree st(n+1);
  auto itr = qs.begin();
  REPC(i,1,n) {
    st.update(i, i+1, st.query(0, i));
    while(itr != qs.end() && itr->r == i) {
      st.update(itr->l, itr->r+1, itr->a);
      itr++;
    }
  }
  cout << st.query(0, n+1) << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}
// https://atcoder.jp/contests/dp/tasks/dp_w

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ITR(c,it)  for(auto it = c.begin(); it != c.end(); it++)

//------------------------------------------------------------------------------
#define LC(k)   (k * 2 + 1)
#define RC(k)   (k * 2 + 2)
#define M(l,r)  ((l + r) / 2)

template<typename T> class SegTree2 {
public:
  int n;
  int sz;
  T def;
  vector<T> sm;
  vector<T> sx;

  void init(int _n, T _def) {
    n = _n;
    def = _def;
    sz = 1; while (sz < n) sz <<= 1;
    sz = sz * 2 - 1;
    sm.resize(sz, 0);
    sx.resize(sz, 0);
  }

  void add(int a, int b, T x, int k, int l, int r) {
    if (r <= a || b <= l) return;
    if (a <= l && r <= b) {
      sm[k] += x;
      sx[k] += x;
      return;
    }
    add(a, b, x, LC(k), l, M(l, r));
    add(a, b, x, RC(k), M(l, r), r);
    sx[k] = sm[k] + max(sx[LC(k)], sx[RC(k)]);
  }

  void add(int a, int b, T x) {
    add(a, b, x, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return def;
    if (a <= l && r <= b) return sx[k];
    T vl = query(a, b, LC(k), l, M(l, r));
    T vr = query(a, b, RC(k), M(l, r), r);
    return sm[k] + max(vl, vr);
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  void dump() {
    REP(i, sz) printf("%d%c", sm[i], i + 1 == sz ? '\n' : ' ');
    REP(i, sz) printf("%d%c", sx[i], i + 1 == sz ? '\n' : ' ');
  }
};

//------------------------------------------------------------------------------
const int N_MAX = 2*1e5;
const int M_MAX = 2*1e5;
const int A_I_MAX = 1e9;
const ll INF = 1e18;

int N, M;
int l[M_MAX];
int r[M_MAX];
int a[M_MAX];

SegTree2<ll> st;
vector<int> add[N_MAX + 1];
vector<pair<int, int>> del[N_MAX + 1];

void solve() {
  REP(i, M) {
    add[l[i]].push_back(a[i]);
    del[r[i]].push_back({l[i], a[i]});
  }
  st.init(N + 1, -INF);
  ll ans = 0;
  FOR(i, 1, N) {
    ITR(add[i], it) st.add(0, i, *it);
    ll dp = st.query(0, i);
    ans = max(ans, dp);
    st.add(i, i + 1, dp);
    ITR(del[i], it) st.add(0, it->first, -it->second);
  }
  printf("%lld\n", ans);
}

void input() {
  scanf("%d%d", &N, &M);
  REP(i, M) scanf("%d%d%d", l + i, r + i, a + i);
}

int main() {
  input();
  solve();
  return 0;
}

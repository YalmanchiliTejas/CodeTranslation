#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;
const ll DINF = 1000000000000000000LL;

#ifndef STNODE
#define STNODE
struct node {
  int l, r;
  ll x, lazy;
  node() {}
  node(int _l, int _r) : l(_l), r(_r), x(0), lazy(0) { }
  node(int _l, int _r, int _x) : node(_l,_r) { x = _x; }
  node(node a, node b) : node(a.l,b.r) { x = max(a.x, b.x); }
  void update(ll v) { x += v; }
  void range_update(ll v) { lazy = v; }
  void apply() { x += lazy; lazy = 0; }
  void push(node &u) { u.lazy += lazy; } };
#endif

struct segment_tree {
  int n;
  vector<node> arr;
  segment_tree() { }
  segment_tree(const vector<ll> &a) : n(a.size()), arr(4*n) {
    mk(a,0,0,n-1); }
  node mk(const vector<ll> &a, int i, int l, int r) {
    int m = (l+r)/2;
    return arr[i] = l > r ? node(l,r) :
      l == r ? node(l,r,a[l]) :
      node(mk(a,2*i+1,l,m),mk(a,2*i+2,m+1,r)); }
  node update(int at, ll v, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (at < hl || hr < at) return arr[i];
    if (hl == at && at == hr) {
      arr[i].update(v); return arr[i]; }
    return arr[i] =
      node(update(at,v,2*i+1),update(at,v,2*i+2)); }
  node query(int l, int r, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return node(hl,hr);
    if (l <= hl && hr <= r) return arr[i];
    return node(query(l,r,2*i+1),query(l,r,2*i+2)); }
  node range_update(int l, int r, ll v, int i=0) {
    propagate(i);
    int hl = arr[i].l, hr = arr[i].r;
    if (r < hl || hr < l) return arr[i];
    if (l <= hl && hr <= r)
      return arr[i].range_update(v), propagate(i), arr[i];
    return arr[i] = node(range_update(l,r,v,2*i+1),
                         range_update(l,r,v,2*i+2)); }
  void propagate(int i) {
    if (arr[i].l < arr[i].r)
      arr[i].push(arr[2*i+1]), arr[i].push(arr[2*i+2]);
    arr[i].apply(); } };

int main() {
    int n, m;
    cin >> n >> m;

    segment_tree st(vector<ll>(n,0));

    vector<ll> sm(n);

    vector<vector<pair<int,int> > > arr(n);
    rep(i,0,m) {
        int l, r, a;
        cin >> l >> r >> a;
        l--, r--;

        sm[l] += a;
        if (r + 1 < n) {
            sm[r+1] -= a;
        }

        st.range_update(l, r, -a);
        arr[l].push_back({r,a});
    }

    rep(i,1,n) {
        sm[i] += sm[i-1];
    }

    ll best = 0;
    for (int i = n-1; i >= 0; i--) {
        ll dp = sm[i] + st.query(i+1,n-1).x;
        best = max(best, dp);
        st.update(i, dp);

        iter(it,arr[i]) {
            st.range_update(i, it->first, it->second);
        }
    }

    cout << best << endl;

    return 0;
}


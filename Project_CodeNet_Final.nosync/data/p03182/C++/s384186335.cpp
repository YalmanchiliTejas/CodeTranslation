#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ALL(a) begin(a), end(a)
#define SZ(a) ((int)(a).size())

#define REP(a, b) for (int a = 0; a < (b); a++)
#define FOR(a, b, c) for (int a = (b); a <= (c); a++)
#define REPD(a, b) for (int a = (b) - 1; a >= 0; a--)
#define FORD(a, b, c) for (int a = (b); a >= (c); a--)

#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))

#ifdef __DEBUG
#define debug if (true)
#else
#define debug if (false)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T> using V = vector<T>;
template <typename T> using VV = vector<V<T>>;
template <typename T> using VVV = vector<VV<T>>;

template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2> &p) {
  return is >> p.fi >> p.se;
}

const int N = 2e5 + 5;

const ll INF = LLONG_MAX / 2;

struct Node {
  ll mx, lazy;
};

Node tree[4 * N];

void push(int x, int l, int r) {
  if (tree[x].lazy == 0) {
    return;
  }
  tree[x].mx += tree[x].lazy;
  if (l != r) {
    tree[2 * x].lazy += tree[x].lazy;
    tree[2 * x + 1].lazy += tree[x].lazy;
  }
  tree[x].lazy = 0;
}

void update(int x, int l, int r, int ql, int qr, int delta) {
  push(x, l, r);
  if (l > qr || r < ql) return;
  if (l >= ql && r <= qr) {
    tree[x].lazy += delta;
    push(x, l, r);
    return;
  }
  int mid = (l + r) / 2;
  update(2 * x, l, mid, ql, qr, delta);
  update(2 * x + 1, mid + 1, r, ql, qr, delta);
  tree[x].mx = max(tree[2 * x].mx, tree[2 * x + 1].mx);
}

void update2(int x, int l, int r, int qp, ll value) {
  push(x, l, r);
  if (l > qp || r < qp) return;
  if (l == r) {
    debug assert(tree[x].lazy == 0);
    tree[x].mx = value;
    return;
  }
  int mid = (l + r) / 2;
  update2(2 * x, l, mid, qp, value);
  update2(2 * x + 1, mid + 1, r, qp, value);
  tree[x].mx = max(tree[2 * x].mx, tree[2 * x + 1].mx);
}

ll query(int x, int l, int r, int ql, int qr) {
  if (l > qr || r < ql) return -INF;
  push(x, l, r);
  if (l >= ql && r <= qr) return tree[x].mx;
  int mid = (l + r) / 2;
  return max(query(2 * x, l, mid, ql, qr),
             query(2 * x + 1, mid + 1, r, ql, qr));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  V<pair<pii, int>> intervals(m);
  VV<int> start(n), finish(n);
  REP(i, m) {
    cin >> intervals[i];
    intervals[i].fi.fi--;
    intervals[i].fi.se--;
    start[intervals[i].fi.fi].pb(i);
    finish[intervals[i].fi.se].pb(i);
  }
  ll cur = 0;
  ll ans = 0;
  REP(i, n) {
    for (int j : start[i]) {
      cur += intervals[j].se;
    }
    ll q = max(0LL, query(1, 0, n - 1, 0, i));
    debug printf("%d: %lld\n", i, cur + q);
    MAX(ans, cur + q);
    update2(1, 0, n - 1, i, q);
    for (int j : finish[i]) {
      cur -= intervals[j].se;
      update(1, 0, n - 1, intervals[j].fi.fi, intervals[j].fi.se, intervals[j].se);
    }
  }
  assert(cur == 0);
  cout << ans << endl;
}

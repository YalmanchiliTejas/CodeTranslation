#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
const int MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 1 << 18;

ll t[2*N], lazy[2*N];
void push(int i) {
  if (lazy[i]) {
    lazy[2*i] += lazy[i];
    lazy[2*i+1] += lazy[i];
    t[2*i] += lazy[i];
    t[2*i+1] += lazy[i];
    lazy[i] = 0;
  }
}

void pull(int i) {
  t[i] = max(t[2*i], t[2*i+1]);
}

void update(int x, int y, ll v, int i=1, int l=0, int r=N-1) {
  if (r < x || y < l) return;
  if (x <= l && r <= y) {
    t[i] += v;
    lazy[i] += v;
    return;
  }
  push(i);
  int m = (l+r)/2;
  update(x, y, v, 2*i, l, m);
  update(x, y, v, 2*i+1, m+1, r);
  pull(i);
}

ll query(int x, int y, int i=1, int l=0, int r=N-1) {
  if (r < x || y < l) return -INF;
  if (x <= l && r <= y) return t[i];
  push(i);
  int m = (l+r)/2;
  return max(query(x, y, 2*i, l, m), query(x, y, 2*i+1, m+1, r));
}

int n, m;
struct qry {
  int x, d;
};
vector<qry> open[N], close[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r, d; cin >> l >> r >> d;
    open[l].push_back({l, d});
    close[r].push_back({l, d});
  }
  // dp[i] = max score of [0..i] with a 1 at i
  //       = max_{j<i} (dp[j] + sum_k d_k where i in k, j not in k)
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (const qry& q : open[i]) {
      update(0, q.x-1, q.d);
    }
    ll dp = query(0, i-1);
    //cerr << i << " " << dp << nl;
    update(i, i, dp);
    ans = max(ans, dp);
    for (const qry& q : close[i]) {
      update(0, q.x-1, -q.d);
    }
  }
  cout << ans << nl;
  return 0;
}

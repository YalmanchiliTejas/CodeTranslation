#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-12, PI = acos(-1);
const int N = 2e5 + 9, M = 5e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18;

vector<pair<int, int>> st[N];
vector<pair<int, int>> en[N];
ll f[N], tree[4*N], lazy[4*N];

void propagate(int node, int start, int end) {
  if(!lazy[node])
    return;
  tree[node] += lazy[node];
  if(start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}

ll query(int node, int start, int end, int l, int r) {
  propagate(node, start, end);
  if(start > r || end < l)
    return -inf;
  if(start >= l && end <= r) {
    return tree[node];
  }
  int mid = (start + end) / 2;
  ll p1 = query(node * 2, start, mid, l, r);
  ll p2 = query(node * 2 + 1, mid + 1, end, l, r);
  return max(p1, p2);
}

void update(int node, int start, int end, int l, int r, ll val) {
  propagate(node, start, end);
  if(start > r || end < l)
    return;
  if(start >= l && end <= r) {
    lazy[node] += val;
    propagate(node, start, end);
    return;
  }
  int mid = (start + end) / 2;
  update(node * 2, start, mid, l, r, val);
  update(node * 2 + 1,mid + 1, end, l, r, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
  fastIO;
#ifdef LOCAL
  freopen("input.in", "rt", stdin);
#endif
  int n, m, l, r, val;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r >> val;
    st[l].push_back({l - 1, val});
    en[r].push_back({l - 1, val});
  }
  for (int i = 1; i <= n; ++i) {
    for(auto it: st[i])
      update(1, 0, n, 0, it.first, it.second);
    f[i] = query(1, 0, n, 0, i - 1);
    update(1, 0, n, i, i, f[i]);
    for(auto it: en[i])
      update(1, 0, n, 0, it.first, -it.second);
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define fi first
#define se second
#define DEBUG(x) cerr << (#x) << ": " << (x) << '\n'
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
 
template<class T> bool uin(T &a, T b) {return (a < b ? false : (a = b, true));}
template<class T> bool uax(T &a, T b) {return (a > b ? false : (a = b, true));}
 
//~ ifstream f(".in");
//~ ofstream g(".out");
 
struct SegmentTree {
  int n;
  static const ll INF = 1e18L;
  struct Interval {
    ll minn, lazy;
  };
  vector<Interval> tree;
  SegmentTree(int _n) : n(_n) {
    tree.resize(4 * n + 5, {0, 0});
  }
  void recalc(int node) {
    tree[node].minn = min(tree[2 * node + 1].minn, tree[2 * node + 2].minn);
  }
  void propagate(int node, int left, int right) {
    if (tree[node].lazy == 0 || left >= right) {
      return;
    }
    for (int son : {2 * node + 1, 2 * node + 2}) {
      assert(son < (int)tree.size());
      tree[son].lazy += tree[node].lazy;
      tree[son].minn += tree[node].lazy;
    }
    tree[node].lazy = 0;
  }
  void update(int node, int left, int right, int x, int y, ll val) {
    assert(node < (int)tree.size());
    propagate(node, left, right);
    if (x <= left && right <= y) {
      tree[node].lazy += val;
      tree[node].minn += val;
      return;
    }
    int mid = left + (right - left) / 2;
    if (x <= mid) {
      update(2 * node + 1, left, mid, x, y, val);
    }
    if (mid < y) {
      update(2 * node + 2, mid + 1, right, x, y, val);
    }
    recalc(node);
  }
  ll query(int node, int left, int right, int x, int y) {
    assert(node < (int)tree.size());
    propagate(node, left, right);
    if (y < left || x > right) {
      return INF;
    }
    if (x <= left && right <= y) {
      return tree[node].minn;
    }
    int mid = left + (right - left) / 2;
    return min(query(2 * node + 1, left, mid, x, y),
               query(2 * node + 2, mid + 1, right, x, y));
  }
  
  ll getMin(int left, int right) {
    return query(0, 0, n, left, right);
  }
  void updateVal(int pos, ll val) {
    update(0, 0, n, pos, pos, val);
  }
  void addOnInterval(int left, int right, ll val) {
    update(0, 0, n, left, right, val);
  }
};
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef LOCAL_DEFINE
  freopen(".in", "r", stdin);
#endif
 
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> intervals(n + 2);
  ll total_val = 0;
  for (int i = 1; i <= m; ++i) {
    int l, r, a;
    cin >> l >> r >> a;
    intervals[r].push_back({l, a});
    total_val += a;
  }
  // O(n * (n + m))
/*
  ll ans = 0;
  vector<ll> dp(n + 2);
  for (int i = 0; i <= n; ++i) {
    uax(ans, total_val - dp[i]);
    ll lost_val = dp[i];
    for (int j = i + 1; j <= n + 1; ++j) {
      uin(dp[j], lost_val);
      for (pair<int, int> &p : intervals[j]) {
        if (p.first > i) {
          lost_val += p.second;
        }
      }
    }
  }
*/
  
  ll ans = 0;
  SegmentTree tree = SegmentTree(n + 1);
  for (int i = 1; i <= n + 1; ++i) {
    ll curr_dp = tree.getMin(0, i - 1);
    uax(ans, total_val - curr_dp);
    tree.updateVal(i, curr_dp);
    for (pair<int, int> &p : intervals[i]) {
      tree.addOnInterval(0, p.first - 1, p.second);
    }
  }
 
  cout << ans << '\n';
 
#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}

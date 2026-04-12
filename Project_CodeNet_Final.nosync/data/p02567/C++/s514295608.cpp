#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

#define INF 1001001001
#define MAX 1e18

int op(int a, int b) { return max(a,b); }
int e() { return -1; }
int target;
bool f(int x) { return target > x; }

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> ans;
  segtree<int, op, e> st(a);
  while (q--) {
    int t; cin >> t;
    if (t==1) {
      int x, v; cin >> x >> v;
      st.set(--x,v);
    } else if (t==2) {
      int l, r; cin >> l >> r;
      ans.push_back(st.prod(--l,r));
    } else {
      int x; cin >> x >> target;
      ans.push_back(st.max_right<f>(--x)+1);
    }
  }
  for (auto a : ans) cout << a << endl;

  return 0;
}

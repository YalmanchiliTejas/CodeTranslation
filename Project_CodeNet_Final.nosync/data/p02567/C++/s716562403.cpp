// -----------------------------------
// author   : MatsuTaku
// country  : Japan
// created  : 09/08/20 03:55:25
// -----------------------------------

#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>

using namespace std;
using ll = long long;

int op(int a, int b) {return max(a,b);}
int e() {return -1;}
using Rmq = atcoder::segtree<int, op, e>;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int n,q; cin>>n>>q;
  vector<int> A(n); for (auto& a:A) cin>>a;
  Rmq rmq(A);
  while (q--) {
    int t; cin>>t;
    if (t == 1) {
      int x,v; cin>>x>>v; x--;
      rmq.set(x, v);
    } else if (t == 2) {
      int l,r; cin>>l>>r; l--;
      cout << rmq.prod(l, r) << endl;
    } else {
      int x,v; cin>>x>>v; x--;
      auto res = rmq.max_right(x, [v](int a) {
        return a < v;
      });
      cout << res + 1 << endl;
    }
  }

  return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
const int inf = 1e9+5;
int op(int a,int b){
  return max(a,b);
}
int e(){
  return -inf;
}
int val;
bool f(int x){
  return x < val;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q;
  cin >> n >> q;
  vector<int> a(n+1,-inf);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  segtree<int,op,e> seg(a);
  while(q--){
    int t,l,r,pos;
    cin >> t;
    if(t == 1){
      cin >> pos >> val;
      seg.set(pos,val);
    }
    else if(t == 2){
      cin >> l >> r;
      cout << seg.prod(l,r+1) << '\n';
    }
    else{
      cin >> pos >> val;
      int ans = seg.max_right<f>(pos);
      cout << ans << '\n';
    }
  }
  return 0;
}
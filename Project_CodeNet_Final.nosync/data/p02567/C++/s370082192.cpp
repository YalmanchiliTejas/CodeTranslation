#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

#define rep(i,n) for(ll i=0;(i)<(ll)n;(i)++)

int op(int a, int b){
  return max(a,b);
}
int e(){
  return -1;
}

int main(){
  int n,q; cin >> n >> q;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }
  segtree<int,op,e> seg(a);
  rep(i,q){
    int t; cin >> t;
    if(t == 1){
      int x,v; cin >> x >> v;
      seg.set(x-1,v);
    }else if(t == 2){
      int l,r; cin >> l >> r;
      cout << seg.prod(l-1,r) << endl;
    }else if(t == 3){
      int x,v; cin >> x >> v;
      cout << 1 + seg.max_right(x - 1, [&](int y){ return (v > y);}) << endl;
    }
  }
  
}

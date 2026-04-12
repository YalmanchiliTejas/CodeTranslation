#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
using ll = long long;

#define rep(i,n) for(ll i=0;(i)<(ll)n;(i)++)
const long long INF = 100000000000;

int op(int a, int b){
  return max(a,b);
}
int e(){
  return -1;
}

int target;
bool f(int x){
  return x < target;
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
      x--;
      seg.set(x,v);
    }else if(t == 2){
      int l,r; cin >> l >> r;
      l--;
      cout << seg.prod(l,r) << endl;
    }else{
      int x; cin >> x >> target;
      x--;
      cout << seg.max_right<f>(x) + 1 << endl;
    }
  }
  
}

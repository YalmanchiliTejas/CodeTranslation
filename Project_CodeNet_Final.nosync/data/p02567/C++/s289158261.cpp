#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int f(int a, int b) {
  return max(a,b);
}

int e() {
  return (int)-1e9;
}

int target;

bool g(int v) {
  return v < target;
}

int main(){
  int n, q;
  cin >> n >> q;
  int a[n];
  segtree<int,f,e> seg(n); 
  rep(i,n) {
    cin >> a[i];
    seg.set(i,a[i]);
  }
  while(q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if(t == 1) seg.set(--x,y);
    else if(t == 2) cout << seg.prod(--x,y) << endl;
    else {
      target = y;
      cout << seg.max_right<g>(--x) + 1 << endl;
    }
  }
  return 0;
}

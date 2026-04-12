#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int op(int a,int b){
  return max(a,b);
}

int e(){
  return -1;
}

int v;

bool f(int k){
  return k < v;
}

int main(){
  int n,q;
  cin >> n >> q;
  vector<int> A(n);
  for(int i=0;i<n;i++){
    cin >> A[i];
  }
  segtree<int,op,e> seg(A);
  for(int i=0;i<q;i++){
    int t;
    cin >> t;
    if(t == 1){
      int x;
      cin >> x >> v;
      x--;
      seg.set(x,v);
    }
    else if(t == 2){
      int l,r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l,r) << endl;
    }
    else if(t == 3){
      int x;
      cin >> x >> v;
      x--;
      cout << seg.max_right<f>(x)+1 << endl;
    }
  }
  return 0;
}
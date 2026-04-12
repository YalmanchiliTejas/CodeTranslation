#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int v;
int op(int a, int b){
  return max(a,b);
}
int e(){
  return -1;
}
bool f(int x){
  if(x<v) return true;
  else return false;
}

int main(){
  int N,Q;
  cin >> N >> Q;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A[i];
  segtree<int,op,e> S(A);
  
  for(int i=0;i<Q;i++){
    int t,x,y;
    cin >> t >> x >> y;
    
    if(t==1){
      S.set(x-1,y);
    }
    if(t==2){
      cout << S.prod(x-1,y) << endl;
    }
    if(t==3){
      v = y;
      cout << S.max_right<f>(x-1) + 1 << endl;
    }
  }
  return 0;
}

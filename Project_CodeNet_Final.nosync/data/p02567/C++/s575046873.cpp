#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <atcoder/all>
#include <cstdio>
#include <vector>
using namespace std;
using namespace atcoder;

int m;

int op(int a, int b) {
    return max(a, b);
}

int e() {
    return (int)-1;
}

bool f(int a){
  return a<m;
}

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  
  vector<int> A(n);
  rep(i,n) scanf("%d",&A[i]);
  
  segtree<int, op, e> seg(n);
  rep(i,n) seg.set(i,A[i]);
  
  rep(i,q){
    int t;
    scanf("%d",&t);
    if(t==1){
      int x,v;
      scanf("%d%d",&x,&v);
      seg.set(x-1,v);
    }
    else if(t==2){
      int l,r;
      scanf("%d%d",&l,&r);
      printf("%d\n",seg.prod(l-1,r));
    }
    else{
      int x;
      scanf("%d%d",&x,&m);
      printf("%d\n",seg.max_right<f>(x-1)+1);
    }
  }
   
  return 0;
}
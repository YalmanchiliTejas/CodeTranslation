#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define REP(i,m,n) for(int i=(m);i<(n);++i)
#define rep(i,n) REP(i,0,n)

int op(int a, int b){
  return max(a,b);
}

int e(){
  return -1;
}

int target;

bool f(int v){
  return v<target;
}

int main(){
  int N,Q;
  scanf("%d%d",&N,&Q);
  
  vector<int> a(N);
  rep(i,N){
    scanf("%d",&(a[i]));
  }
  
  segtree<int,op,e> st(a);
  
  rep(i,Q){
    int t;
    scanf("%d",&t);
    if(t==1){
      int x,v;
      scanf("%d%d",&x,&v);
      x-=1;
      st.set(x,v);
    }
    else if(t==2){
      int l,r;
      scanf("%d%d",&l,&r);
      l-=1;
      printf("%d\n",st.prod(l,r));
    }
    else if(t==3){
      int p;
      scanf("%d%d",&p,&target);
      p-=1;
      printf("%d\n",st.max_right<f>(p)+1);
    }
  }
  
  return 0;
}
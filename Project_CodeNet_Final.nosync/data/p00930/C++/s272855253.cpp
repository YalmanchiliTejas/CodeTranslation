#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)
  
struct segtree{
  vector<int> t,u;
  int n;
  
  void init(int _n){
    n=1;
    while(n<_n)n*=2;
    t.clear();
    u.clear();
    t.resize(2*n);
    u.resize(2*n);
    for(int i=0;i<2*n;i++)
      t[i]=u[i]=0;
  }
  
  void delay(int k,int l,int r){
    if(r-l==1)return;
    
    t[k*2+1]+=u[k];
    u[k*2+1]+=u[k];
    
    t[k*2+2]+=u[k];
    u[k*2+2]+=u[k];
    
    u[k]=0;
  }
  
  void add(int a,int b,int x,int k,int l,int r){
    if(b<=l || r<=a)return;
    delay(k,l,r);
    if(a<=l && r<=b){
      t[k]+=x;
      u[k]+=x;
    }else{
      int m=(l+r)/2;
      add(a,b,x,k*2+1,l,m);
      add(a,b,x,k*2+2,m,r);
      t[k]=min(t[k*2+1],t[k*2+2]);
    }
  }
  
  int query(int a,int b,int k,int l,int r){
    if(b<=l || r<=a)return INF;
    delay(k,l,r);
    if(a<=l && r<=b){
      return t[k];
    }else{
      int m=(l+r)/2;
      int lc=query(a,b,k*2+1,l,m);
      int rc=query(a,b,k*2+2,m,r);
      return min(lc,rc);
    }
  }
  
  void add(int a,int b,int x) {
    add(a,b,x,0,0,n);
  }
  
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
  
segtree T;
int N,Q;
char str[300005];
set< int > U;
  
int main(){
  scanf("%d %d",&N,&Q);
  scanf("%s",str);
  T.init(N+2);
  
  
  for(int i=0;i<N;i++){
    if(str[i]=='('){
      T.add(i,N,1);
    }else{
      T.add(i,N,-1);
      U.insert(i);
    }
  }
  
  
  set<int> :: iterator it;
  int p,a;
  while(Q--){
  
  
    scanf("%d",&p);
    p--;
    if(str[p]=='('){
      U.insert(p);
      str[p]=')';
      T.add(p,N,-2);
  
      it=U.begin();
      a= *it;
      printf("%d\n",a+1);
      U.erase(it);
      str[a]='(';
      T.add(a,N,2);
    }else if(str[p]==')'){
      it=U.find(p);
      U.erase(it);
      str[p]='(';
      T.add(p,N,2);
  
  
  
        
      int l=0,r=N-1,m,k;
      while(l<r){
        m=(l+r)/2;
        k=T.query(m,N);
          
        if(k<2){
          l=m+1;
        }else{
          r=m;
        }
      }
      printf("%d\n",l+1);
      str[l]=')';
      T.add(l,N,-2);
      U.insert(l);
    }
  }
  return 0;
}
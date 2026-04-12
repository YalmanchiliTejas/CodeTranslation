#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)
 
struct segtree{
  vector<int> datasum;
  vector<int> delay;
   
  int n;
   
  void init(int _n){
    n = 1;
    while( n < _n ) n *= 2;
    datasum.resize( 2 * n );
    delay.resize( 2 * n );
  }
 
  void delaycalc(int k){
    datasum[k] = datasum[k] + delay[k];
    if( k + 1 < n ){
      for(int i=1;i<=2;i++){
        delay[2 * k + i] = delay[ 2 * k + i] + delay[k];
      }
    }
    delay[k] = 0;
  }
 
  void add(int a,int b,int x,int k,int l,int r){
    delaycalc(k);
    if( r <= a || b <= l ) return;
    else if( a<= l && r <= b ) {
      delay[k] = x;
      delaycalc(k);
    } else {
      add( a, b, x, 2*k + 1, l, (l+r)/2 );
      add( a, b, x, 2*k + 2, (l+r)/2, r );
      datasum[k] = min(datasum[ 2 * k + 1] , datasum[ 2 * k + 2]);
    }
  }
 
  int query(int a,int b,int k,int l,int r){
    delaycalc(k);
    if( r <= a || b <= l ) return INF;
    if( a <= l && r <= b ) {
      return datasum[k] + delay[k];
    } else {
      int vl = query( a, b, 2*k+1, l, (l+r)/2 );
      int vr = query( a, b, 2*k+2, (l+r)/2, r );
      return min( vl , vr );
    }
  }
 
  void add( int a,int b,int x) {//[a,b) add x
    add( a, b, x, 0,0, n );
  }
  int query(int a,int b){//[a,b) 's sum
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
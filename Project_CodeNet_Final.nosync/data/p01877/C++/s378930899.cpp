#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segtree{
  vector<ll> datamax;
  vector<ll> datamin;
  vector<ll> delay;
  

  int n;

  void init(int _n){
    n = 1;
    while( n < _n ) n *= 2;
    datamax.resize( 2 * n );
    datamin.resize( 2 * n );
    delay.resize( 2 * n );
    
  }

  void delaycalc(int k){
    datamax[k] = datamax[k] + delay[k];
    datamin[k] = datamin[k] + delay[k];
    if( k + 1 < n ) 
      for(int i=1;i<=2;i++)
	delay[2*k+i] = delay[2*k+i] + delay[k];
    delay[k] = 0;
  }

  void add(int a,int b,ll x,int k,int l,int r){
    delaycalc(k);
    if( r <= a || b <= l ) return;
    else if( a <= l && r <= b ){
      delay[k] = x;
      delaycalc(k);      
    } else {
      add( a, b, x, 2*k + 1, l, (l+r)/2 );
      add( a, b, x, 2*k + 2, (l+r)/2, r );
      datamax[k] = max( datamax[2*k+1], datamax[2*k+2] );
      datamin[k] = min( datamin[2*k+1], datamin[2*k+2] );
    }				
  }
  

  ll qmax(int a,int b,int k,int l,int r){
    delaycalc(k);
    if( r <= a || b <= l ) return 0;
    if( a <= l && r <= b ) {
      return datamax[k] + delay[k];
    } else {
      ll vl = qmax( a, b, 2*k+1, l, (l+r)/2 );
      ll vr = qmax( a, b, 2*k+2, (l+r)/2, r );
      return max(vl,vr);
    }
  }
  
   ll qmin(int a,int b,int k,int l,int r){
    delaycalc(k);
    if( r <= a || b <= l ) return 0;
    if( a <= l && r <= b ) {
      return datamin[k] + delay[k];
    } else {
      ll vl = qmin( a, b, 2*k+1, l, (l+r)/2 );
      ll vr = qmin( a, b, 2*k+2, (l+r)/2, r );
      return min(vl,vr);
    }
  }
 
  
  void add(int a,int b,ll x){
    add( a, b, x, 0,0, n );
  }
  ll qmin(int a,int b){
    return qmin( a,b, 0,0,n);
  }  
  ll qmax(int a,int b){
    return qmax( a,b, 0,0,n);
  }  
};

segtree S;
int N,Q;
int R[300000];
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    int s; cin >> s;
    if( i<N/2 ) {
      R[i] = s;
    } else {
      R[N-i-1] -= s;
    }
  }
  S.init( N/2 );
  for(int i=0;i<N/2;i++){
    S.add( i,i+1,R[i] );
  }
  cin >> Q;

  for(int i=0;i<Q;i++){
    int l,r,x; cin >> l  >> r >> x;
    --l; --r;
    if( r < N/2 ){
      S.add( l,r+1, x );
    } else if( l >= N/2 ){
      S.add( N-r-1, N-l, -x );
    } else {
      S.add( l, N/2, x );
      S.add( N-r-1, N/2, -x );
    }
    if( S.qmax( 0, N/2 ) == 0 && S.qmin( 0,N/2 ) == 0 )
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }
  
}
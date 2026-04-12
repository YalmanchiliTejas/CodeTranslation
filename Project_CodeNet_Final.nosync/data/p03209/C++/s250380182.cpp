#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll rec(ll L, ll x){
  //レベルLハンバーガを下からx層だけ食べた時のパティの枚
  if( L == 0){ return 1;}
  
   else{
  
  ll hight = (1LL << (L+1)) -3; ll p = ( 1LL << L )-1;
  
  if( x == 1|| x == 0){ return 0;}
  else if( x <= 1+hight){ return rec(L-1,x-1);}
  else if( x == 2+hight){ return p+1;}
  else if( x <= 2+2*hight){ return 1 + p + rec( L-1,x-2-hight);}
  else if( x >= 3+2*hight){ return 2*p+1;} }
}

int main(){
 ll N,X; cin >> N >> X;
  cout << rec(N,X) << endl; return 0;}
 
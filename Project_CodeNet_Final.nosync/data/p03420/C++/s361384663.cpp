#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll N,K; cin >> N >> K;
  ll cnt = 0;
  
  for(ll b = 1; b <= N; b++){
    if( K >= b){ continue;} 
    ll m = (N+1)/b; cnt += (b-K)*m;
    ll r = N-m*b; if(K<=r && r <= b-1){ cnt += r-K+1;}
    if(K==0){cnt--;}

  }

  cout << cnt << endl; return 0;}
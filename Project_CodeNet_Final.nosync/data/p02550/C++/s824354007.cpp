#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main(){
  
  ll n,x,m; cin>>n>>x>>m;
  
  vector<ll> a(m,-1);
  ll cnt{1};
  ll y = x;
  ll start,end;
  a.at(y) = 0;
  while(1){
    y *= y;
    y %= m;
    if(a.at(y)==-1) {
      a.at(y) = cnt;
      cnt++;
    }
    else{
      start = a.at(y);
      end = cnt-1;
      break;
    }
    
  }
  //cout << start <<' '<<end<< endl;
  y = x;
  ll ans{}, l;
  for(ll i=0; i<start; i++){
    ans += y;
    y *= y;
    y %= m;
  }
  for(ll i=start; i<=end; i++){
    l += y;
    y *= y;
    y %= m;
  }
  n -= start;
  ans += l * ( n/(end-start+1) );
  n %= (end-start+1);
  for(ll i=0; i<n; i++){
    ans += y;
    y *= y;
    y %= m; 
  }
  cout<<ans<<endl;
  
  
  
  
}

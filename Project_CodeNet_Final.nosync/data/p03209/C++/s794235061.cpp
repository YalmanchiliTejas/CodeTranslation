#include <bits/stdc++.h>
using namespace std;
using ll=long long;
map<pair<ll,ll>,ll> mp;
ll f(ll i,ll x) {
  if(mp.count({i,x})) return mp[{i,x}];
  if(x--==0) return 0;
  if(i--==0) return 1;
  ll a=(1LL<<i+2)-3;
  ll res;
  if(!x) res=0;
  else if(x<a+1) res=f(i,x);
  else res=f(i,a)+f(i,x-a-1)+1;
  mp[{i+1,x+1}]=res;
  return res;
}
int main(){
  ll n,x;
  cin>>n>>x;
  cout<<f(n,x)<<endl;
}

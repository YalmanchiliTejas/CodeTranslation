#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],total,psum;
ll m(ll x, ll y){
  ll res=0;
  x%=1000000007;
  while(y){
    if(y%2) res=(res+x)%1000000007;
    x=(x*2)%1000000007;
    y/=2;
  }
  return res;
}
int main(){
  cin>>n;
  for(ll i=1;i<=n;i++){
    cin>>a[i];
    total+=m(psum,a[i]);
    total%=1000000007;
    psum+=a[i];
    psum%=1000000007;
  }
  cout<<total;
  return 0;
}
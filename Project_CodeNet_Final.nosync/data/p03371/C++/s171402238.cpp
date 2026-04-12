#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

ll digitcal(ll x){
  ll n=0;
  while(x>0){
    x/=10;
    n++;
  }
  return n;
}

int main() {
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll ans=1e18;
  if(x<y){
    swap(x,y);swap(a,b);
  }
  for(int i=0;i<=x;i++){
    ll temp=0;
    temp+=i*a;
    temp+=(x-i)*2*c;
    temp+=max((ll)0,y-(x-i))*b;
    ans=min(ans,temp);
  }
  cout<<ans<<endl;
  return 0;
}

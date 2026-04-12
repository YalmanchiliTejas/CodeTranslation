#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  ll n,x,m;
  cin>>n>>x>>m;
  vector<ll>modulo(m+2);
  modulo[1]=x;
  vector<ll>b(m+2);
  rep(i,m+2)
    b[i]=0;
  b[x]=1;
  ll bound;
  ll cir;
  for(ll i=2;i<=m+1;i++){
    x=(x*x)%m;
    if(b[x]==0){
      modulo[i]=x;
      b[x]=i;
    }
    else{
      modulo[i]=x;
      bound=b[x];
      cir=i-bound;
      break;
    }
  }
  ll ans=0;
  for(ll i=1;i<=bound;i++)
    ans+=modulo[i];
  n-=bound;
  ll z=n/cir;
  ll y=n%cir;
  for(ll i=1;i<=cir;i++){
    if(i<=y)
      ans+=modulo[bound+i]*(z+1);
    else
      ans+=modulo[bound+i]*z;
  }
  cout<<ans<<endl;
}
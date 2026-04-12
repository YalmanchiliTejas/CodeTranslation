#include <bits/stdc++.h>
#include <stdlib.h>
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

int main() {
  int k,n;
  cin>>n>>k;
  ll ans=0;
  for(int i=k+1;i<=n;i++){
    if(n%i>=k) ans+=((n/i)*(i-k)+(n%i)-k+1);
    else ans+=((n/i)*(i-k));
  }
  if(k==0){
    ans-=n;
  }
  cout<<ans<<endl;
  return 0;
}


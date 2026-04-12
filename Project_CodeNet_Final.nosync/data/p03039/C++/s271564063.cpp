#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll power(ll x,ll n){
    if(n==0) return 1;
    ll res=power(x*x%mod,n/2);
    if(n&1) res=res*x%mod;
    return res;
}

int main() {
  ll n,m,k;
  cin>>n>>m>>k;
  ll a[n*m+1];
  a[0]=1;
  rep(i,1,n*m+1) a[i]=a[i-1]*i%mod;
  ll b[n*m+1];
  b[0]=1;
  rep(i,1,n*m+1) b[i]=power(a[i],1e9+5);
  ll ans=((n-1)*n*(n+1)/6)%mod*m%mod*m%mod+((m-1)*m*(m+1)/6)%mod*n%mod*n%mod;
  ans%=mod;
  ans=ans*(a[n*m-2]*b[k-2]%mod*b[n*m-k]%mod)%mod;
  cout<<ans<<endl;
}

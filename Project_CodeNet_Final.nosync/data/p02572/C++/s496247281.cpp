#include"bits/stdc++.h"
using ll=long long; 
using ld=long double; 
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod=1e9+7; 
int main()
{
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  #endif
  int n; cin>>n; vector<int>a(n); for(int i=0;i<=n-1;i++) cin>>a[i]; 
  vector<ll>p(n); p[n-1]=(a[n-1])%mod; for(int i=n-2;i>=0;i--) p[i]=(p[i+1]+a[i])%mod;  
  ll ans=0; 
  for(int i=0;i<=n-2;i++)
  { 
    ans=(ans+a[i]*1ll*p[i+1])%mod; 
  }
  cout<<ans<<"\n"; 
  return 0; 
}
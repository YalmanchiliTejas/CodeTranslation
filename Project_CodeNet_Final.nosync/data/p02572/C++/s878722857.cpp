#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;
ll a[200100];
ll s[200100]={};
int main(void){
  ll n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i!=0) s[i]=s[i-1];
    s[i]+=a[i];
    s[i]%=mod;
  }
  ll ans=0;
  for(int i=0;i<n-1;i++){
    ll sum=(s[n-1]-s[i]+mod)%mod;
    ans+=sum*a[i];
    ans%=mod;
  }
  cout<<ans<<endl;
}
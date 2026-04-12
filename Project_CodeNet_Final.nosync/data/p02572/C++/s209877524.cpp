#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

const int MOD=1e9+7;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  vector<ll> ra(n+1);
  ra[0]=0;
  rep(i,n){
    ra[i+1]=ra[i]+a[i];
  }
  ll ans=0;
  for(int i=0; i<n-1; i++){
    ans+=a[i]*((ra[n]-ra[i+1])%MOD)%MOD;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
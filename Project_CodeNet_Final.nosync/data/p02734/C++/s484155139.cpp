#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
//const ll mod=1e9+7;
const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n,s;
  cin >> n >> s;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  mat dp(n+1,vec(3001));
  for(ll i=0;i<=n;i++) {
    dp[i][0]=i+1;
  }
  for(ll i=0;i<n;i++) {
    for(ll j=3000;j>0;j--) {
      dp[i+1][j]=dp[i][j];
      if(j-a[i]>-1) {
        dp[i+1][j]=(dp[i+1][j]+dp[i][j-a[i]])%mod;
      }
    }
  }
  ll ans=0;
  for(ll i=1;i<=n;i++) {
    ans=(ans+dp[i][s])%mod;
  }
  cout << ans << endl;
}
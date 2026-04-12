#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;
 
int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  mat dp(n+1,vec(n+1,0));
  for(ll i=0;i<n;i++) dp[i][i]=0;
  for(ll len=1;len<=n;len++) {
    for(ll i=0;i+len<=n;i++) {
      ll j=i+len;
      if((n-len)%2==0) {
        dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j-1]);
      }
      else {
        dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j-1]);
      }
    }
  }
  cout << dp[0][n] << endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll check=1;
  check+=n%2;
  mat dp(n+1,vec(check+1,-inf));
  dp[0][0]=0;
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<=check;j++) {
      if(j!=check) {
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
      }
      ll cur=dp[i][j];
      if((i+j)%2==0) cur+=a[i];
      dp[i+1][j]=max(dp[i+1][j],cur);
    }
  }
  cout << dp[n][check] << endl;
}
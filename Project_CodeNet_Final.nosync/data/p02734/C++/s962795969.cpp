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
  for(ll i=0;i<n;i++) cin >> a[i];
  vector<mat> dp(n+1,mat(s+1,vec(3)));
  dp[0][0][0]=1;
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<=s;j++) {
      for(ll k=0;k<3;k++) {
        (dp[i+1][j][k]+=dp[i][j][k])%=mod;
        if(k==0) {
          if(j+a[i]<s) {
            (dp[i+1][j+a[i]][k+1]+=dp[i][j][k]*(i+1))%=mod;
          }
          if(j+a[i]==s) {
            (dp[i+1][j+a[i]][k+2]+=dp[i][j][k]*(i+1)*(n-i))%=mod;
          }
        }
        else if(k==1) {
          if(j+a[i]<s) {
            (dp[i+1][j+a[i]][k]+=dp[i][j][k])%=mod;
          }
          if(j+a[i]==s) {
            (dp[i+1][j+a[i]][k+1]+=dp[i][j][k]*(n-i))%=mod;
          }
        }
      }
    }
  }
  cout << dp[n][s][2] << endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

ll inf=1e10;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> dp(n,inf);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  reverse(a.begin(),a.end());
  for(ll i=0;i<n;i++) {
    *upper_bound(dp.begin(),dp.end(),a[i])=a[i];
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(dp[i]!=inf) {
      ans=i+1;
    }
  }
  cout << ans << endl;
}
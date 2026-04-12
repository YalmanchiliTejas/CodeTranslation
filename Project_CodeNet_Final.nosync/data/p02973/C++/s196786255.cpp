#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,m,n) for(int i=m;i<n;i++)


int main() {
  int n;
  cin>>n;
  ll a[n];
  rep(i,0,n) cin>>a[n-1-i];
  ll dp[n];
  rep(i,0,n) dp[i]=2e9;
  rep(i,0,n) *upper_bound(dp,dp+n,a[i])=a[i];
  cout<<lower_bound(dp,dp+n,2e9)-dp<<endl;
}

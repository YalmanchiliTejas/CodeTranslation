#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 ll n;
 cin>>n;
 vector<ll> a(n);
 for(ll i=0;i<n;i++) cin>>a[i];
 vector<vector<ll>> dp(n,vector<ll>(n));
 for(ll i=0;i<n;i++) dp[i][i]=a[i];
 for(ll i=n-1;i>=0;i--){
  for(ll j=i+1;j<n;j++){
   dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
  }
 }
 cout<<dp[0][n-1]<<endl;
 return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 ll n;
 cin>>n;
 ll a[n];
 for(ll i=0;i<n;i++) cin>>a[i];
 ll sum[n+1];
 sum[0]=0;
 for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+a[i-1];
 ll dp[n][n];
 for(ll i=0;i<n;i++) dp[i][i]=a[i];
 for(ll i=n-1;i>=0;i--){
  for(ll j=i+1;j<n;j++){
   ll ans1=a[j]+sum[j]-sum[i]-dp[i][j-1];
   ll ans2=a[i]+sum[j+1]-sum[i+1]-dp[i+1][j];
   dp[i][j]=max(ans1,ans2);
  }
 }
 ll ans1=dp[0][n-1];
 ll ans2=sum[n]-sum[0]-ans1;
 cout<<ans1-ans2<<endl;
 return 0;
}
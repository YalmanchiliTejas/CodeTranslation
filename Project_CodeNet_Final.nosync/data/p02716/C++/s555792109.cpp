#include<bits/stdc++.h>
#define pb push_back
#define mod int(1e9+7)
#define N int(2e5+100)
#define ll long long int
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define si second
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   ll n;
   cin>>n;
   ll a[n];
   for(ll i=0;i<n;i++)
      cin>>a[i];
   ll dp[n][2];
   dp[0][0]=0ll;
   dp[0][1]=a[0];
   dp[1][0]=dp[1][1]=max(a[0],a[1]);
   for(ll i=2;i<n;i++){
      if(i%2){
         dp[i][0]=dp[i][1]=max(dp[i-2][0]+a[i],dp[i-1][1]);
      }else{
         dp[i][1]=dp[i-2][1]+a[i];
         dp[i][0]=max(dp[i-1][0],dp[i-2][0]+a[i]);
      }
   }
   cout<<dp[n-1][0]<<'\n';
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(ll i=0;i<n;i++)
#define ll long long
int main(){
	ll n,k;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
	// memset(dp,1,sizeof dp)    ;
	//keeps track of winners
// cout<<dp[1]<<endl;
// =1;
	for(ll len =1;len<=n;len++){
		for(ll i=0;i<n-len+1;i++){
			ll j=len+i-1;
			if(i==j)dp[i][j]=a[i];
			dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		}
	}
	// f(i,n){
	// 	f(j,n)cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	cout<<dp[0][n-1]<<endl;
	return 0;
}

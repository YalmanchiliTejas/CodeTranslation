#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;cin>>n;
	ll i,j;
	ll v[n];
	vector<vector<ll>> dp(n,vector<ll>(2,0));
	for(i=0;i<n;i++) cin>>v[i];
		//dp[0]={v[0],v[0],1};
		dp[0][0]=0;
		dp[0][1]=0;
		dp[1][0]=v[0];
	dp[1][1]=v[1];

		for(i=2;i<n;i++)
		{	if(i%2==0){
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=max(dp[i-2][0],dp[i-2][1])+v[i];
		}
			else {dp[i][0]=dp[i-2][0]+v[i-1];
				dp[i][1]=(dp[i-1][0])+v[i];
			}

		}
		cout<<max(dp[n-1][0],dp[n-1][1]);
	return 0;
} 
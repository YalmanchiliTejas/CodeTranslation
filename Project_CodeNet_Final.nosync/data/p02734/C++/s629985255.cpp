#include <bits/stdc++.h>
using namespace std;
// #define int long long
int dp[3000+10][3000+10];
int dps[3000+10][3000+10];
const int mod=998244353;
int32_t main()
{
    // cout<<"fafaf"<<endl;
	int n,s;
	cin>>n>>s;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1][a[1]]=1;
	dps[1][a[1]]=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int sum=a[i]+1;sum<=3000;sum++)
		{
            dp[i][sum]=dps[i-1][sum-a[i]];
		}
		dp[i][a[i]]=i;
		dp[i][a[i]]%=mod;		
		for(int sum=0;sum<=3000;sum++){
		    dps[i][sum]=dps[i-1][sum];
		    dps[i][sum]+=dp[i][sum];
		    dps[i][sum]%=mod;
		}


	}	
	for(int i=1;i<=n;i++) ans+=(1ll*(n-i+1)*dp[i][s])%mod,ans%=mod;
	cout<<ans;	

	
	return 0;
}

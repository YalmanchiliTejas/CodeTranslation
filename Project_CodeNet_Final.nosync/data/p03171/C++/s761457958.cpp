#include<bits/stdc++.h>
using namespace std;
int n;
long long a[3005];
long long dp[3005][3005];
long long k[2];

int main(){
	scanf("%d",&n);
	k[0]=-1,k[1]=1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) dp[i][i]+=k[n&1]*a[i];
	for(int len=2;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if((n-len+1)&1) dp[l][r]=max(dp[l+1][r]+a[l],dp[l][r-1]+a[r]);
			else dp[l][r]=min(dp[l+1][r]-a[l],dp[l][r-1]-a[r]);
		}
	}
	printf("%lld\n",dp[1][n]);
	
	return 0;
}   
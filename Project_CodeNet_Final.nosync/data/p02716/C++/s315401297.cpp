#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	static lint dp[200002][3];
	rep(i,n+2) rep(j,3) dp[i][j]=-INF;
	dp[0][0]=0;
	rep(i,n){
		dp[i+2][0]=dp[i][0]+a[i];
		dp[i+2][1]=dp[i][1]+a[i];
		if(i>=1) dp[i+2][1]=max(dp[i+2][1],dp[i-1][0]+a[i]);
		dp[i+2][2]=dp[i][2]+a[i];
		if(i>=1) dp[i+2][2]=max(dp[i+2][2],dp[i-1][1]+a[i]);
		if(i>=2) dp[i+2][2]=max(dp[i+2][2],dp[i-2][0]+a[i]);
	}

	lint ans;
	if(n%2==0) ans=max(dp[n][0],dp[n+1][1]);
	else       ans=max({dp[n-1][0],dp[n][1],dp[n+1][2]});
	printf("%lld\n",ans);

	return 0;
}

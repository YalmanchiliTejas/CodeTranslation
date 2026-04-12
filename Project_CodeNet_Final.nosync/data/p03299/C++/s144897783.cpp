#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,dp[105][105],ans;
int h[105],H[105],hi[105],cnt,r[105];

int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod,y/=2;
	}
	return res;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]),hi[i]=h[i];
	sort(hi+1,hi+n+1);
	for(int i=1;i<=n;i++) if(hi[i]!=hi[i-1]) H[++cnt]=hi[i];
	for(int i=1;i<=n;i++) r[i]=lower_bound(H+1,H+cnt+1,h[i])-H;
	for(int j=0;j<r[1];j++){
		int i=1;
		if(j) dp[i][j]=2ll*(ksm(2,H[j+1]-H[j])-1)*ksm(2,h[1]-H[j+1])%mod;
		else dp[i][j]=1ll*(ksm(2,H[j+1]-H[j])-2)*ksm(2,h[1]-H[j+1])%mod;
	}
	dp[1][r[1]]=2;
	for(int i=2;i<=n;i++){
		if(h[i]<=h[i-1]){
			for(int j=0;j<r[i];j++) dp[i][j]=dp[i-1][j];
			for(int j=r[i];j<=r[i-1];j++) (dp[i][r[i]]+=2ll*dp[i-1][j]%mod)%=mod;
		}
		else{
			for(int j=0;j<r[i-1];j++) dp[i][j]=1ll*dp[i-1][j]*ksm(2,h[i]-h[i-1])%mod;
			int S=2ll*dp[i-1][r[i-1]]%mod;
			for(int j=r[i-1];j<r[i];j++) dp[i][j]=1ll*S*(ksm(2,H[j+1]-H[j])-1)%mod*ksm(2,h[i]-H[j+1])%mod;
			dp[i][r[i]]=S;
		}
	}
	for(int i=0;i<=r[n];i++) (ans+=dp[n][i])%=mod;
	printf("%d\n",ans);
	
	return 0;
}
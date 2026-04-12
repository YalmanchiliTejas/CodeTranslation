#include<bits/stdc++.h>
using namespace std;
long long md;
long long dp[3010][3010];
long long C[3010][3010];
long long g[3010][3010];
long long powd(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1) res=res*x%md;
		x=x*x%md;
		y>>=1;
	}
	return res;
}
long long powd(long long x,long long y,long long p){
	long long res=1;
	while(y){
		if(y&1) res=res*x%p;
		x=x*x%p;
		y>>=1;
	}
	return res;
}
void Add(long long &x,long long y){
	(x+=y)%=md;
}
int n;
long long solve(int x){
	long long res=0;
	for(int i=0;i<=n;i++)
		Add(res,dp[x][i]*g[n-x][i]%md);
	res=res*C[n][x]%md*powd(2,powd(2,n-x,md-1))%md;
	return res;
}
int main(){
	scanf("%d%lld",&n,&md);
	C[0][0]=C[1][0]=C[1][1]=1;
	for(int i=2;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=n;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%md;
	}
	for(int i=0;i<=n;i++){
		g[i][0]=1,g[i][1]=powd(2,i);
		for(int j=2;j<=n;j++)
			g[i][j]=g[i][j-1]*g[i][1]%md;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j>0) Add(dp[i][j],dp[i-1][j-1]);
			Add(dp[i][j],dp[i-1][j]*(j+1));
		}
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		if(i&1)
			Add(ans,md-solve(i));
		else
			Add(ans,solve(i));
	}
	printf("%lld\n",ans);
	return 0;
}

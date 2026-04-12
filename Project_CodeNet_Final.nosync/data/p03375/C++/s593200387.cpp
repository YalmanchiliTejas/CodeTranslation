#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3005;
int n,M,dp[N][N],fac2[N],val[N],ans,fac[N],inv[N];
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
int C(int x,int y){
	if (x<y)return 0;
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
signed main(){
	scanf("%lld%lld",&n,&M);
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++)
			dp[i][j]=((j==0?0:dp[i-1][j-1])+dp[i-1][j]*j+dp[i-1][j])%M;
	fac[0]=fac2[0]=inv[0]=1;
	for (int i=1;i<=n;i++)fac2[i]=fac2[i-1]*2%(M-1),fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	for (int i=0;i<=n;i++)val[i]=ksm(2,fac2[n-i]);
	for (int i=0;i<=n;i++){
		for (int k=0;k<=i;k++)
			if (!(i&1))(ans+=val[i]*dp[i][k]%M*C(n,i)%M*ksm(2,(n-i)*k))%=M;
			else (ans+=M-val[i]*dp[i][k]%M*C(n,i)%M*ksm(2,(n-i)*k)%M)%=M;
	}
	printf("%lld\n",ans);
}

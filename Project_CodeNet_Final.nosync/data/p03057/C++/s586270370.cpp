#include<cstdio>
using namespace std;
#define mod 1000000007
#define N 200050
int n,m,dp[N][2][2],fg,mx,fg2,dp2[N],su[N],as;
char s[N];
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=2;i<=m;i++)if(s[i]!=s[i-1])fg=1;
	if(!fg)
	{
		dp[1][1][1]=dp[1][0][0]=1;
		for(int i=2;i<=n;i++)
		dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][1][0])%mod,
		dp[i][0][1]=(dp[i-1][0][1]+dp[i-1][1][1])%mod,
		dp[i][1][0]=dp[i-1][0][0],
		dp[i][1][1]=dp[i-1][0][1];
		printf("%lld\n",(1ll*dp[n][0][0]+dp[n][0][1]+dp[n][1][0])%mod);
		return 0;
	}
	int su1=0;
	for(int i=1;i<=m;i++)
	if(s[i]==s[1])su1++;
	else
	{
		if((su1&1)&&mx>su1)mx=su1;
		if(!fg2)mx=su1+1;
		fg2=1;su1=0;
	}
	if(mx>n)mx=n;
	if(~mx&1)mx--;
	dp2[1]=1;su[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(i-mx>3)dp2[i]=(su[i-2]-su[i-mx-3]+mod)%mod;
		else dp2[i]=su[i-2];
		su[i]=(su[i-2]+dp2[i])%mod;
	}
	for(int i=1;i<=mx;i+=2)as=(as+1ll*dp2[n-i]*(i+1))%mod;
	printf("%d\n",as);
}//
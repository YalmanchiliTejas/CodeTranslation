#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 10001
#define MO 998244353
int fac[MAXN],inv[MAXN],x,y,n,dp[MAXN][MAXN];
char a[MAXN],b[MAXN];
int C(int n,int m)
{
	return 1LL*fac[n]*inv[m]%MO*inv[n-m]%MO;
}
void Pre()
{
	fac[0]=inv[1]=inv[0]=1;
	for(int i=1;i<MAXN;i++)
		fac[i]=1LL*fac[i-1]*i%MO;
	for(int i=2;i<MAXN;i++)
		inv[i]=1LL*(MO-MO/i)*inv[MO%i]%MO;
	for(int i=1;i<MAXN;i++)
		inv[i]=1LL*inv[i]*inv[i-1]%MO;
}
int main()
{
	Pre();
	scanf("%s%s",a,b);
	n=strlen(a);
	for(int i=0;i<n;i++)
		if(a[i]=='1'||b[i]=='1')
		{
			if(a[i]=='1'&&b[i]=='1') x++;
			else y++;
		}
	y/=2;
	dp[0][0]=1;
	for(int i=1;i<=y;i++) dp[0][i]=1LL*fac[i]*fac[i]%MO;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			dp[i][j]=1LL*(1LL*dp[i-1][j]*i%MO+1LL*dp[i][j-1]*j%MO)*j%MO;
	int ans=0;
	for(int i=0;i<=x;i++)
		(ans+=1LL*dp[x-i][y]*fac[i]%MO*fac[i]%MO*C(x,i)%MO*C(x+y,i)%MO)%=MO;
	printf("%d\n",ans);
}
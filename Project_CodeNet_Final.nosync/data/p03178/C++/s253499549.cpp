#include<bits/stdc++.h>
using namespace std;
 
const int maxn=(int)1e4+10;
const int maxd=100+10;
const int mod=(int)1e9+7;
char s[maxn];
long long dp[maxn][maxd];
long long dp2[maxn][maxd];
int n,d;
  
long long modu(long long a, long long b, long long m){ return (a+b+10*m)%m; }

int main()
{
	scanf("%s",s+1);
	scanf("%d",&d);
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	dp[0][0]=1;
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<d;j++)
			for(long long k=0;k<=9;k++)
				dp[i][j]=modu(dp[i][j],dp[i-1][modu(j,-k,d)],mod);
	dp2[0][0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<d;j++)
		{
			for(long long k=0;k<(s[i]-'0');k++)
				dp2[i][j]=modu(dp2[i][j],dp[i-1][modu(j,-k,d)],mod);
			dp2[i][j]=modu(dp2[i][j],dp2[i-1][modu(j,-(long long)(s[i]-'0'),d)],mod);
		}
	}
	printf("%lld",modu(dp2[n][0],mod-1,mod));
}
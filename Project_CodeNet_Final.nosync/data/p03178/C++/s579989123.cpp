#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const long long MOD=1e9+7;
int n,m,a[N];
long long dp[N][105];
char str[N];

long long dfs(int x,int s,int limit)
{
	if(x==n+1)
	{
		dp[x][s]=(s==0);
		return dp[x][s];
	}
	if(!limit&&dp[x][s]>-1) return dp[x][s];
	int rb;
	long long res=0;
	if(limit) rb=a[x]; else rb=9;
	for(int i=0;i<=rb;i++)
	{
		res=(res+dfs(x+1,(s+i)%m,(limit&&(i==rb))))%MOD;
	}
	if(!limit) dp[x][s]=res;
	return res;
}

int main()
{
	scanf("%s%d",str,&m),n=strlen(str);
	for(int i=1;i<=n;i++) a[i]=str[i-1]-'0';
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",(dfs(1,0,1)+MOD-1)%MOD);
}
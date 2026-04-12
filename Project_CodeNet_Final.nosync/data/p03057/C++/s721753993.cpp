#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m;
char s[200005];
ll f[200005][2],sum[200005];
ll DP(int n,int l)
{
	f[1][1]=1;
	for(int i=2;i<=n+1;i++)
	{
		f[i][1]=(f[i-1][1]+f[i-1][0])%MOD;
		f[i][0]=(f[i-1][1]+f[i-1][0]-(i-1>l?f[i-l-1][1]:0)+MOD)%MOD;
	}
	sum[1]=f[1][1];
	for(int i=2;i<=n+1;i++)
	  sum[i]=(sum[i-1]+f[i][1])%MOD;
	ll ans=f[n+1][1];
	for(int st=2;st<=l+1;st++)
	  ans+=sum[n-st+1]-sum[n-l-1];
	ans%=MOD;
	if(ans<0)ans+=MOD;
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	if(s[1]=='B')
	{
		for(int i=1;i<=m;i++)
		{
			if(s[i]=='B')s[i]='R';
			else s[i]='B';
		}
	}
	int l=200001;
	int i=1;
	while(s[i]=='R')i++;
	if(i>m)
	{
		printf("%lld\n",DP(n,1));
		return 0;
	}
	if(n&1)
	{
		printf("0\n");
		return 0;
	}
	if(i&1)l=min(l,i);
	else l=min(l,i-1);
	while(i<=m)
	{
		while(s[i]=='B')i++;
		int len=0;
		while(s[i]=='R')len++,i++;
		if(i>m)break;
		if(len&1)l=min(l,len);
	}
	printf("%lld\n",DP(n/2,l/2)*2%MOD);
	return 0;
}
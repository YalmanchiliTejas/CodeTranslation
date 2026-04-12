#include<bits/stdc++.h>
using namespace std;
#define nn 500008
#define mod 1000000007
char str[nn];int n,m;
long long dp[nn],sum[nn];
#define err return 0*puts("0");
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str+1);
	
	int cnt=0;
	if(str[1]=='B') for(int i=1;i<=m;i++) if(str[i]=='R') str[i]='B';else str[i]='R';
	for(int i=1;i<=m;i++) if(str[i]=='B') cnt++;
	int mx=n;int flg=0;
	if(cnt)
	{
		cnt=0;
		if(n%2) err;int j=1;
		for(int i=m;i>=1;i--)
			if(str[i]=='B')  {for(int j=i;j<=m;j++) str[j]='B';break;}

		for(int i=1;i<=m;i++)
		{
			if(str[i]=='B') break;
			cnt++;j=i;
		}
		mx=min(mx,cnt/2+1);
		
		j++;
		cnt=0;str[m+1]='B';
		for(;j<=m+1;j++)
		{
			if(str[j]=='B')
			{
				if(cnt%2) mx=min(mx,cnt/2+1);
				cnt=0;
			}
			else cnt++;
		}
		flg=1;
		n/=2;
	}
	
	dp[0]=sum[0]=1;
	int ls=0;if(!flg) ls=1,sum[1]=1;
	for(int i=ls+1;i<=n;i++) 
	{
		if(i-mx-1>=0 and flg) dp[i]=(sum[i-1-ls]-sum[i-mx-1]+mod)%mod;
		else dp[i]=sum[i-1-ls];
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	long long ans=0;
	for(int i=1+ls;i<=n and i<=mx;i++)
	{
		ans+=1ll*dp[n-i]*i%mod;
		if(flg) ans+=1ll*dp[n-i]*i%mod;
		ans%=mod;
	}
	if(ls==1) ans++;
	
	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}
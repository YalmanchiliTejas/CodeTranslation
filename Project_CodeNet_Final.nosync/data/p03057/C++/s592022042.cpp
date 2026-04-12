#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

char str[SIZE];
ll dp[SIZE],rdp[SIZE];

ll solve(int n,int L)
{
	dp[1]=1;
	rdp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=rdp[i-1]-(i-L-2<=0?0:rdp[i-L-2]);
		if(dp[i]<0) dp[i]+=MOD;
		rdp[i]=rdp[i-1]+dp[i];
		if(rdp[i]>=MOD) rdp[i]-=MOD;
	}
	ll ret=0;
	for(int i=0;i<=min(n-1,L);i++)
	{
		ret+=(ll) (i+1)*dp[n-i]%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	return ret;
}
ll solve2(int n)
{
	dp[1]=1;
	rdp[1]=1;
	dp[2]=0;
	rdp[2]=1;
	for(int i=3;i<=n;i++)
	{
		dp[i]=rdp[i-2];
		rdp[i]=rdp[i-1]+dp[i];
		if(rdp[i]>=MOD) rdp[i]-=MOD;
	}
	ll ret=0;
	for(int i=1;i<=n-1;i++)
	{
		ret+=(ll) (i+1)*dp[n-i]%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	return ret;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&str);
	bool R=false,B=false;
	for(int i=0;i<m;i++)
	{
		if(str[i]=='R') R=true;
		else B=true;
	}
	if(!B||!R) printf("%lld\n",(solve2(n)+1)%MOD);
	else
	{
		if(n%2==1) puts("0");
		else
		{
			int mn=n;
			for(int i=0;i<m;)
			{
				if(str[i]!=str[0])
				{
					i++;
					continue;
				}
				int f=i;
				for(;i<m&&str[i]==str[f];i++);
				int len=i-f;
				//printf("%d\n",len);
				if(f==0)
				{
					if(len%2==0) len++;
					mn=min(mn,len);
				}
				else if(i<m&&len%2==1) mn=min(mn,len);
			}
			//printf("%d\n",mn);
			printf("%lld\n",solve(n/2,mn/2)*2LL%MOD);
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int fpow(int x,int y,int mod)
{
	if(y==0)
		return 1;
	int ret=fpow(x,y>>1,mod);
	ret=(long long)ret*ret%mod;
	if(y&1)
		ret=(long long)ret*x%mod;
	return ret;
}
int s[3030][3030];
int c[3030][3030];
int cnt[3030];
int main()
{
	int n,m,h,hh;
	scanf("%d%d",&n,&m);
	s[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		s[i][0]=1;
		for(int j=1;j<=i;j++)
			s[i][j]=((long long)s[i-1][j]*(j+1)+s[i-1][j-1])%m;
	}
	memset(c,0,sizeof(c));
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%m;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<=n;i++)
	{
		h=fpow(2,n-i,m);
		hh=1;
		for(int j=0;j<=i;j++)
		{
			cnt[i]=((long long)s[i][j]*hh+cnt[i])%m;
			hh=(long long)hh*h%m;
		}
	}
	for(int i=0;i<=n;i++)
		cnt[i]=(long long)cnt[i]*fpow(2,fpow(2,n-i,m-1),m)%m*c[n][i]%m;
	for(int i=n;i>=0;i--)
		for(int j=i+1;j<=n;j++)
			cnt[i]=(m-(long long)cnt[j]*c[j][i]%m+cnt[i])%m;
	printf("%d",cnt[0]);
	return 0;
}
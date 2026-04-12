#include<bits/stdc++.h>
using namespace std;
#define N 3005
int n,m,ans,f[N],c[N][N],s[N][N];
long long pw(long long x,int y,int mod){long long r=1;for(;y;y>>=1,x=x*x%mod)if(y&1)r=r*x%mod;return r;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)c[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%m;
	s[1][1]=1;
	for(int i=2;i<N;i++)for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j]%m)%m;
	for(int i=0;i<=n;i++)
	{
		long long a=pw(2,pw(2,n-i,m-1),m),b=pw(2,n-i,m),c=1;
		for(int j=0;j<=i;j++,c=1ll*c*b%m)(f[i]+=1ll*s[i+1][j+1]*a%m*c%m)%=m;
	}
	for(int i=0;i<=n;i++)if(i&1)(ans-=1ll*c[n][i]*f[i]%m)%=m;else (ans+=1ll*c[n][i]*f[i]%m)%=m;
	printf("%d\n",(ans+m)%m);
	return 0;
}
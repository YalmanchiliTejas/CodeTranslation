#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 3005
using namespace std;
//char nc()
//{
//	static char buf[100000],*p1=buf,*p2=buf;
//	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
char nc(){return getchar();}
int read()
{
	int x=0,y=1;
	char c=nc();
	while(!isdigit(c))
	{
		if(c=='-')y=-1;
		c=nc();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=nc();
	}
	return x*y;
}
int n;
long long mod,C[MAX][MAX],g[MAX][MAX];
long long mo(long long x)
{
	return x<mod?x:x-mod;
}
long long quick_pow(long long x,long long y,long long p)
{
	long long re=1;
	while(y)
	{
		if(y&1) re=re*x%p;
		x=x*x%p;
		y>>=1;
	}
	return re;
}
int main()
{
	n=read();mod=read();
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=mo(C[i-1][j]+C[i-1][j-1]);
	}
	for(int i=0;i<=n;i++)
	{
		g[i][0]=1;
		for(int j=1;j<=i;j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(j+1))%mod;
	}
	long long ANS=0;
	for(int i=0;i<=n;i++)
	{
		long long tp1=quick_pow(2,n-i,mod),tp2=quick_pow(2,quick_pow(2,n-i,mod-1),mod);
		long long sm=0,now=1;
		for(int j=0;j<=i;j++)
			sm=(sm+now*g[i][j])%mod,now=now*tp1%mod;
		if(!(i&1)) ANS=(ANS+C[n][i]*tp2%mod*sm)%mod;
		else ANS=mo(ANS-C[n][i]*tp2%mod*sm%mod+mod);
	}
	printf("%lld",ANS);
	return 0;
}

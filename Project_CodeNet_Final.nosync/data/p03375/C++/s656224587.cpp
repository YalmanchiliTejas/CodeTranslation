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
long long mod,inv[MAX],S2[MAX][MAX];
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
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	S2[0][0]=1;
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=i;j++)
			S2[i][j]=(S2[i-1][j-1]+S2[i-1][j]*j)%mod;
	long long ans=0,C=1;
	for(int i=0;i<=n;i++)
	{
		long long sm=0,pw2=quick_pow(2,n-i,mod),ha=quick_pow(2,quick_pow(2,n-i,mod-1),mod)*C%mod,tp=1;
		C=C*(n-i)%mod*inv[i+1]%mod;
		for(int j=0;j<=i;j++)
			sm=(sm+S2[i+1][j+1]*tp)%mod,tp=tp*pw2%mod;
		if(i&1) ans=(ans-sm*ha)%mod;
		else ans=(ans+sm*ha)%mod;
	}
	ans=(ans+mod)%mod;
	printf("%lld",ans);
	return 0;
}

#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mod 998244353
#define MAX 8005
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
namespace ntt
{
	long long mo(long long x)
	{
		return x<mod?x:x-mod;
	}
	long long quick_pow(long long x,long long y)
	{
		long long re=1;
		while(y)
		{
			if(y&1) re=re*x%mod;
			x=x*x%mod;
			y>>=1;
		}
		return re;
	}
	int rev[MAX<<3];
	long long wi[MAX<<3];
	int make(int n)
	{
		int l=log2(n)+1;n=1<<l;
		for(int i=0;i<n;i++)
			rev[i]=((rev[i>>1]>>1)|((i&1)<<(l-1)));
		return n;
	}
	void dft(long long a[],int n,long long flag)
	{
		for(int i=0;i<n;i++)
			if(rev[i]<i) swap(a[i],a[rev[i]]);
		for(int i=1;i<n;i<<=1)
		{
			long long wn=quick_pow(3,mod-1+flag*(mod-1)/(i<<1));
			wi[0]=1;
			for(int j=1;j<i;j++)
				wi[j]=wi[j-1]*wn%mod;
			for(int j=0;j<n;j+=i<<1)
				for(int k=0;k<i;k++)
				{
					long long x=a[j+k],y=a[j+k+i]*wi[k]%mod;
					a[j+k]=mo(x+y);a[j+k+i]=mo(x-y+mod);
				}
		}
		if(flag==-1)
		{
			long long inv=quick_pow(n,mod-2);
			for(int i=0;i<n;i++)
				a[i]=a[i]*inv%mod;
		}
	}
	long long ta[MAX<<3],tb[MAX<<3];
	void mul(long long a[],long long b[],int n,int ln)
	{
		for(int i=0;i<=n;i++)
			ta[i]=a[i],tb[i]=b[i];
		for(int i=n+1;i<ln;i++)
			ta[i]=0,tb[i]=0;
		dft(ta,ln,1);dft(tb,ln,1);
		for(int i=0;i<ln;i++)
			ta[i]=ta[i]*tb[i]%mod;
		dft(ta,ln,-1);
		for(int i=0;i<ln;i++)
			a[i]=ta[i];
	}
}
using namespace ntt;
int n,m;
long long fac[MAX],inv[MAX],facinv[MAX],f[205][MAX],g[MAX<<3],h[MAX<<3];
long long C(int down,int up)
{
	if(down<up) return 0;
	return fac[down]*facinv[down-up]%mod*facinv[up]%mod; 
}
int main()
{
	n=read();m=read();
	fac[0]=fac[1]=1;inv[1]=1;facinv[0]=facinv[1]=1;
	for(int i=2;i<=n+2;i++)
		fac[i]=fac[i-1]*i%mod,
		inv[i]=inv[mod%i]*(mod-mod/i)%mod,
		facinv[i]=facinv[i-1]*inv[i]%mod;
	for(int i=0;i<=n;i++)
		f[m][i]=C(n,i);
	int ln=make(n*2+2);
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<=n;j++)
			g[j]=f[i+1][j]*fac[j+2]%mod,h[j]=facinv[n-j+2];
		h[n]=0;
		mul(g,h,n,ln);
		for(int j=0;j<=n;j++)
			f[i][j]=(g[n+j]*facinv[j]+f[i+1][j]*((C(j+1,2)+1)))%mod;
	}
	printf("%lld",f[0][0]);
	return 0;
}
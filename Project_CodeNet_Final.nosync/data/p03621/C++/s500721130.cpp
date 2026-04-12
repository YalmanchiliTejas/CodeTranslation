#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5,mod=998244353;
inline LL powmod(LL a,LL b){LL c=1;while(b){if(b&1)c=c*a%mod;a=a*a%mod;b>>=1;}return c;}
inline LL inv(LL x){return powmod(x,mod-2);}
inline void transform(int n,LL*x,int type)
{
	static LL w[N];
	for(int i=0,j=0;i<n;i++)
	{
		if(i>j)swap(x[i],x[j]);
		for(int k=n>>1;(j^=k)<k;k>>=1);
	}
	for(int i=2;i<=n;i<<=1)
	{
		int m=i>>1;LL wn=powmod(3,(mod-1)/i);if(type)wn=inv(wn);
		w[0]=1;for(int j=1;j<m;j++)w[j]=w[j-1]*wn%mod;
		for(int j=0;j<n;j+=i)
			for(int k=0;k<m;k++)
			{
				LL z=x[j+k+m]*w[k]%mod;
				x[j+k+m]=(x[j+k]-z+mod)%mod;
				x[j+k]=(x[j+k]+z)%mod;
			}
	}
	if(type)
	{
		LL nn=inv(n);
		for(int i=0;i<n;i++)x[i]=x[i]*nn%mod;
	}
}
inline void FFT(int n,int m,LL*x,LL*y)
{
	int p=1;while(p<n+m-1)p<<=1;
	for(int i=n;i<p;i++)x[i]=0;
	for(int i=m;i<p;i++)y[i]=0;
	transform(p,x,0);transform(p,y,0);
	for(int i=0;i<p;i++)x[i]=x[i]*y[i]%mod;
	transform(p,x,1);transform(p,y,1);
}
inline void FFT(int n,LL*x)
{
	int p=1;while(p<n+n-1)p<<=1;
	for(int i=n;i<p;i++)x[i]=0;
	transform(p,x,0);
	for(int i=0;i<p;i++)x[i]=x[i]*x[i]%mod;
	transform(p,x,1);
}
inline void get_pow(int n,LL*f,int m)
{
	static LL ans[N];
	memset(ans,0,sizeof(ans));
	ans[0]=1;
	while(m)
	{
		if(m&1)FFT(n,n,ans,f);
		FFT(n,f);
		m>>=1;
	}
	for(int i=0;i<n;i++)f[i]=ans[i];
}
LL fac[N],caf[N],x[N];
int n,num0,num1;
char s[N],t[N];
inline LL C(int n,int m){return fac[n]*caf[m]%mod*caf[n-m]%mod;}
inline LL update(LL&x,LL y){x=(x+y)%mod;}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1'&&t[i]=='1')num0++;
		else if(s[i]=='1'&&t[i]=='0')num1++;
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	caf[n]=inv(fac[n]);for(int i=n-1;i>=0;i--)caf[i]=caf[i+1]*(i+1)%mod;
	for(int i=0;i<=num0;i++)x[i]=caf[i+1]%mod;
	int p=1;while(p<=num0)p<<=1;
	get_pow(p,x,num1);
	for(int i=0;i<=num0;i++)x[i]=x[i]*fac[num0]%mod*caf[num0-i]%mod;
	LL ans=0;
	for(int i=0;i<=num0;i++)update(ans,x[i]*fac[num0-i]%mod);
	printf("%lld\n",ans*fac[num0+num1]%mod*fac[num1]%mod);
	return 0;
}
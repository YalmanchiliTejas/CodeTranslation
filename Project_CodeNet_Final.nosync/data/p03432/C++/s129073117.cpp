#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define Mod 998244353
using namespace std;
long long fpow(long long a,long long b)
{
	long long ans=1,t=a;
	while(b)
	{
		if(b&1)ans=ans*t%Mod;
		t=t*t%Mod;
		b>>=1;
	}
	return ans;
}
int rev[40010];
void getrev(int bit)
{
	for(int i=0;i<(1<<bit);i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	return ;
}
void ntt(long long* a,int n,int dft)
{
	for(int i=0;i<n;i++)
		if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int step=1;step<n;step<<=1)
	{
		long long wn=fpow(3,(Mod-1)/(step<<1));
		if(dft==-1)wn=fpow(wn,Mod-2);
		for(int i=0;i<n;i+=step<<1)
		{
			long long wnk=1;
			for(int j=i;j<i+step;j++)
			{
				long long x=a[j],y=a[j+step]*wnk%Mod;
				a[j]=x+y;if(a[j]>=Mod)a[j]-=Mod;
				a[j+step]=x-y;if(a[j+step]<0)a[j+step]+=Mod;
				wnk=wnk*wn%Mod;
			}
		}
	}
	if(dft==-1){
		long long invn=fpow(n,Mod-2);
		for(int i=0;i<n;i++)
			a[i]=a[i]*invn%Mod;
	}
	return ;
}
long long tmp[40010];
long long g[40010];
long long f[210][8010];
long long fac[8010],inv[8010];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n+2;i++)
	{
		fac[i]=fac[i-1]*i%Mod;
		inv[i]=fpow(fac[i],Mod-2);
	}
	int s=1,bit=0;
	while(s<=(n<<1))s<<=1,bit++;
	getrev(bit);
	for(int i=1;i<=n;i++)
		g[i]=inv[i+2]%Mod;
	ntt(g,s,1);
	f[0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<s;j++)
			if(j<=n)tmp[j]=f[i-1][j]*inv[j]%Mod;
			else tmp[j]=0;
		ntt(tmp,s,1);
		for(int j=0;j<s;j++)
			tmp[j]=tmp[j]*g[j]%Mod;
		ntt(tmp,s,-1);
		for(int j=0;j<=n;j++)
			f[i][j]=((j*(j+1)/2+1)*f[i-1][j]+tmp[j]*fac[j+2])%Mod;
	}
	long long ans=0;
	for(int i=0;i<=n;i++)
		ans=(ans+fac[n]*inv[i]%Mod*inv[n-i]%Mod*f[m][i])%Mod;
	printf("%lld\n",ans);
	return 0;
}
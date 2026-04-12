#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline int qpow(int bas,int pw)
{
	int ret=1; for(;pw;pw>>=1,bas=1ll*bas*bas%mod)
	if(pw&1) ret=1ll*ret*bas%mod; return ret;
}
inline void Add(int &x,int y)
{
	x+=y; if(x>=mod) x-=mod;
	if(x<0) x+=mod;
}
int n,a,b,c,d,fac[2010],inv[2010],F[2010],G[2010],Ans;
int main()
{
	n=read(); a=read(); b=read(); c=read(); d=read();
	fac[0]=1; for(int i=1;i<=1000;i++) fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=0;i<=1000;i++) inv[i]=qpow(fac[i],mod-2);
	F[0]=1; for(int i=a;i<=b;i++)
	{
		memset(G,0,sizeof G);
		for(int j=c;j<=d;j++) if(j*i<=n)
		{
			for(int k=n;k>=j*i;k--)
				Add(G[k],1ll*F[k-j*i]*qpow(inv[i],j)%mod*inv[j]%mod);
		}
		for(int j=1;j<=n;j++) Add(F[j],G[j]);
	}
	cout << 1ll*fac[n]*F[n]%mod << endl;
	return 0;
}
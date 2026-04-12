#include<iostream>
#include<cstdio>
#define MN 3000
#define MX 32000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,mod,p[MN+5],inv[MN+5],S[MN+5][MN+5],pw[MX+5],PW[MX+5],ans,ppw[MX+5],PPW[MX+5];
inline int C(int n,int m){return 1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
inline int pw2(int n){return 1LL*PW[n/MX]*pw[n%MX]%mod;}
inline int ppw2(int n){return 1LL*PPW[n/MX]*ppw[n%MX]%(mod-1);}
int main()
{
	n=read();mod=read();p[0]=inv[0]=p[1]=inv[1]=S[0][0]=pw[0]=PW[0]=ppw[0]=PPW[0]=1;
	for(int i=2;i<=n+1;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n+1;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n+1;++i) for(int j=1;j<=i;++j)
		S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j)%mod;
	for(int i=1;i<=MX;++i) pw[i]=2*pw[i-1]%mod,ppw[i]=2*ppw[i-1]%(mod-1);
	for(int i=1;i<=MX;++i) PW[i]=1LL*PW[i-1]*pw[MX]%mod,PPW[i]=1LL*PPW[i-1]*ppw[MX]%(mod-1);
	for(int i=0;i<=n;++i)
	{
		int res=0;
		for(int k=0;k<=i;++k)
			res=(res+1LL*S[i+1][k+1]*pw2(k*(n-i)))%mod;
		ans=(ans+1LL*res*C(n,i)%mod*((i&1)?mod-1:1)%mod*pw2(ppw2(n-i)))%mod;
	}
	cout<<ans;
	return 0;
}


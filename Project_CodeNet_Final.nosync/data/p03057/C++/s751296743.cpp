#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005,mod=1e9+7;
int n,m,c[N],k,lst,f[N],pfx[N],ans; char s[N];
inline int sum(CI x,CI y)
{
	int t=x+y; return t>=mod?t-mod:t;
}
namespace SP //one char solver
{
	int f[N][2][2];
	inline int solve(void)
	{
		f[1][0][0]=f[1][1][1]=1; for (RI i=2;i<=n;++i)
		f[i][0][0]=sum(f[i-1][0][0],f[i-1][0][1]),f[i][0][1]=f[i-1][0][0],
		f[i][1][0]=sum(f[i-1][1][0],f[i-1][1][1]),f[i][1][1]=f[i-1][1][0];
		return sum(f[n][0][0],sum(f[n][0][1],f[n][1][0]));
	}
};
int main()
{
	RI i; for (scanf("%d%d%s",&n,&m,s+1),lst=1,i=2;i<=m;++i)
	if (s[i]!=s[i-1]) c[++k]=i-lst,lst=i; c[++k]=n-lst+1;
	if (k==1) return printf("%d",SP::solve()),0; if (n&1) return puts("0"),0;
	if (k&1) --k; int lim=c[1]+!(c[1]&1); for (i=3;i<=k;i+=2) if (c[i]&1) lim=min(lim,c[i]);
	for (n>>=1,lim=lim+1>>1,f[0]=pfx[0]=i=1;i<=n;++i)
	f[i]=sum(pfx[i-1],mod-(i-1-lim>=0?pfx[i-1-lim]:0)),
	pfx[i]=sum(pfx[i-1],f[i]); for (i=1;i<=min(n,lim);++i)
	ans=sum(ans,2LL*f[n-i]*i%mod); return printf("%d",ans),0;
}
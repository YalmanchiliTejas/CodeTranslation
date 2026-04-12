#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,m,f[200010],sum[200010],la,mi,ans,jc[200010],inv[200010];
char s[200010];
bool bo;

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int calc(int n)
{
	int ans=0;
	for (int i=0; n-i-1>=i; i++)
		ans=(ans+1ll*jc[n-i-1]*inv[i]%mod*inv[n-2*i-1])%mod;
	return ans;
}

int main()
{
	scanf("%d%d",&n,&m),scanf("%s",s),bo=1;
	if (s[0]=='B') {for (int i=0; i<m; i++) s[i]=(s[i]=='B'?'R':'B');}
	for (int i=0; i<m; i++) if (s[i]=='B') {bo=0; break;}
	if (bo)
	{
		jc[0]=1;
		for (int i=1; i<=n; i++) jc[i]=1ll*jc[i-1]*i%mod;
		inv[n]=quickmi(jc[n],mod-2);
		for (int i=n; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
		ans=(calc(n)+2ll*calc(n-1))%mod;
		return printf("%d\n",ans),0;
	}
	la=-1,mi=1000000000,ans=0;
	for (int i=0; i<m; i++)
		if (s[i]=='B') 
		{
			if ((i-la-1)&1) mi=min(mi,i-la-1);
			else if (la==-1) mi=min(mi,i-la);
			la=i;
		}
	f[0]=sum[0]=1,f[1]=sum[1]=0;
	for (int i=2; i<=n; i++) 
	{
		f[i]=sum[i-2]-(i-mi-3<0?0:sum[i-mi-3]);
		if (f[i]<0) f[i]+=mod;
		sum[i]=(sum[i-2]+f[i]>=mod?sum[i-2]+f[i]-mod:sum[i-2]+f[i]);
	}
	for (int i=0,nw1,nw2; i<=mi&&i<n; i++)
	{
		nw1=(n-i-1-((i&1)^1)>=0?sum[n-i-1-((i&1)^1)]:0);
		nw2=(n-i-3-(mi-i)>=0?sum[n-i-3-(mi-i)]:0);
		ans+=(nw1<nw2?nw1-nw2+mod:nw1-nw2);
		if (ans>=mod) ans-=mod;
	}
	printf("%d\n",ans);
	return 0;
}
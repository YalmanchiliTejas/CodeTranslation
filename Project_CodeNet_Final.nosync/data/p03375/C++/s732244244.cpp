#include<bits/stdc++.h>
using namespace std;

int n,mod,s[3010][3010],jc[3010],inv[3010],ans;

int quickmi(int a,int b,int m=mod)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%m)
		if (b&1) t=1ll*t*a%m;
	return t;
}

int main()
{
	scanf("%d%d",&n,&mod),s[0][0]=1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j])%mod;
	jc[0]=1;
	for (int i=1; i<=n; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[n]=quickmi(jc[n],mod-2);
	for (int i=n; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	for (int i=1; i<=n; i++)
		for (int j=2; j<=i; j++) s[i][j]=1ll*s[i][j]*jc[j]%mod;
	for (int i=1; i<=n; i++)
	{
		int nw=0;
		for (int j=0,ww=quickmi(2,n-i),w=1; j<=i; j++,w=1ll*w*ww%mod)
			nw=(nw+1ll*(s[i][j+1]+s[i][j])*w%mod*inv[j])%mod;
		nw=1ll*nw*inv[i]%mod*inv[n-i]%mod*jc[n]%mod*quickmi(2,quickmi(2,n-i,mod-1))%mod;
		ans=(ans+1ll*((i&1)?1:(mod-1))*nw)%mod;
	}
	ans=quickmi(2,quickmi(2,n,mod-1))-ans;
	return printf("%d\n",(ans+mod)%mod),0;
}
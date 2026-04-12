#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,N=20010;
int jc[N],inv[N],n,c01,c11,f[N],c[N],mi[5010][10010];
char s[N],t[N];

int C(int a,int b)
{
	if (a<b||b<0) return 0;
	return 1ll*jc[a]*inv[b]%mod*inv[a-b]%mod;
}

int quickmi(int a,int b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int main()
{
	jc[0]=1;
	for (int i=1; i<N; i++) jc[i]=1ll*jc[i-1]*i%mod;
	inv[N-1]=quickmi(jc[N-1],mod-2);
	for (int i=N-1; i; i--) inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%s%s",s,t),n=strlen(s),c01=c11=0;
	for (int i=0; i<n; i++) if (s[i]=='1')
		{if (t[i]=='1') c11++; else c01++;}
	for (int i=0; i<=c01; i++)
	{
		mi[i][0]=1;
		for (int j=1; j<=c01+c11; j++) mi[i][j]=1ll*mi[i][j-1]*i%mod;
	}
	for (int j=0; j<=c01; j++) c[j]=1ll*C(c01,j)*(((c01-j)&1)?(mod-1):1)%mod;
	int ans=0,nw;
	for (int m=0; m<=c11; m++)
	{
		nw=0;
		for (int j=0; j<=c01; j++) nw=(nw+1ll*c[j]*mi[j][c01+c11-m])%mod;
		ans=(ans+1ll*nw*jc[c11-m]%mod*C(c01+c11,m)%mod*C(c11,m)%mod*jc[m]%mod*jc[m]%mod*jc[c01])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
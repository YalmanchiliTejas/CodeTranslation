#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;
int n,h[110],f[110],mi[110][110];
long long cnt[110][110];

int quickmi(int a,long long b)
{
	int t=1;
	for (; b; b>>=1,a=1ll*a*a%mod)
		if (b&1) t=1ll*t*a%mod;
	return t;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&h[i]);
	for (int i=1; i<=n; i++)
	{
		mi[i][i]=h[i];
		for (int j=i+1; j<=n; j++) mi[i][j]=min(mi[i][j-1],h[j]);
	}
	for (int i=1; i<=n; i++)
	{
		cnt[i][i]=h[i];
		for (int j=i+1; j<=n; j++) cnt[i][j]=cnt[i][j-1]+max(h[j]-h[j-1],0);
	}
	for (int i=1; i<n; i++)
	{
		int H=min(h[i],h[i+1]);
		f[i]=quickmi(2,cnt[1][i]-H);
		for (int j=1; j<i; j++)
			if (h[j]<h[j+1]) f[i]=(f[i]+1ll*f[j]*quickmi(2,cnt[j][i]-h[j]-H+mi[j][i+1]))%mod;
			else f[i]=(f[i]+1ll*f[j]*quickmi(2,cnt[j+1][i]-h[j+1]-H+mi[j+1][i+1]))%mod;
	}
	f[n]=quickmi(2,cnt[1][n]);
	for (int j=1; j<n; j++)
		if (h[j]<h[j+1]) f[n]=(f[n]+1ll*f[j]*quickmi(2,cnt[j][n]-h[j]+1))%mod;
		else f[n]=(f[n]+1ll*f[j]*quickmi(2,cnt[j+1][n]-h[j+1]+1))%mod;
	return printf("%d\n",f[n]),0;
}
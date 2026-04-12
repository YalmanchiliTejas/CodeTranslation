#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 10005;
const int mod = 998244353;

int x,y,n;char a[maxn],b[maxn];
int fac[maxn],inc[maxn];
int dp[maxn][maxn],ans;

LL comb(int n,int m) {
	return (LL)fac[n]*inc[m]%mod*(LL)inc[n-m]%mod;
}
LL fpm(LL p,LL k) {
	LL res=1ll;
	while (k) {
		if (k&1) (res*=p)%=mod;
		(p*=p)%=mod;k>>=1;
	}
	return res;
}

int main()
{
	#ifdef Amberframe
		freopen("agc019e.in","r",stdin);
		freopen("agc019e.out","w",stdout);
	#endif
	scanf("%s %s",a+1,b+1);n=strlen(a+1);
	for (int i=1;i<=n;i++)
		x+=(a[i]=='1'&&b[i]=='1'),
		y+=(a[i]=='0'&&b[i]=='1');
	
	fac[0]=inc[0]=1;
	for (int i=1;i<=n;i++) fac[i]=(LL)fac[i-1]*i%mod;
	inc[n]=fpm(fac[n],mod-2);
	for (int i=n;i>=2;i--) inc[i-1]=(LL)inc[i]*i%mod;
	dp[0][0]=1;
	
	for (int j=1;j<=n;j++) dp[0][j]=(LL)fac[j]*fac[j]%mod;
	for (int i=1;i<=x;i++)
	for (int j=1;j<=y;j++)
		dp[i][j]=((LL)dp[i-1][j]*i+(LL)dp[i][j-1]*j)*j%mod;
	for (int t=0;t<=x;t++)
		ans=(ans+(LL)dp[x-t][y]*dp[0][t]%mod*comb(x,t)%mod*comb(x+y,t))%mod;
	printf("%d",ans);
	return 0;
}
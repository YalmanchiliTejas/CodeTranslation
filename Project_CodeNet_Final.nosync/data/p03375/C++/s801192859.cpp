#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 3010

int n;
ll mod,pw[N],S[N][N],C[N][N],ans;

ll power(ll x,ll y,ll mo) {
	ll ret=1;
	for (;y;y>>=1,x=x*x%mo)
		if (y&1) ret=ret*x%mo;
	return ret;
}

int main()
{
	scanf("%d%lld",&n,&mod);
	pw[0]=1; for (int i=1;i<=n;i++) pw[i]=pw[i-1]*2%mod;
	for (int i=0;i<=n;i++) {
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	S[1][1]=1;
	for (int i=2;i<=n+1;i++)
		for (int j=1;j<=i;j++)
			S[i][j]=(S[i-1][j]*j+S[i-1][j-1])%mod;
	for (int i=0;i<=n;i++) {
		ll sum=0;
		for (int j=0;j<=i;j++) sum=(sum+power(pw[n-i],j,mod)*S[i+1][j+1])%mod;
		if (i&1) ans=(ans-sum*C[n][i]%mod*power(2,power(2,n-i,mod-1),mod)%mod+mod)%mod;
		else ans=(ans+sum*C[n][i]%mod*power(2,power(2,n-i,mod-1),mod)%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
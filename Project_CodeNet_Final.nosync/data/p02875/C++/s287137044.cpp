#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=10000050;
int F[N],I[N],po2[N],po3[N];
int binom(int n, int k){ return (ll)F[n]*I[k]%mod*I[n-k]%mod;}
int main()
{
	int n;
	scanf("%i",&n);
	F[0]=1;for(int i=1;i<=n;i++) F[i]=(ll)F[i-1]*i%mod;
	I[0]=I[1]=1;for(int i=2;i<=n;i++) I[i]=mod-(ll)(mod/i)*I[mod%i]%mod;
	for(int i=1;i<=n;i++) I[i]=(ll)I[i]*I[i-1]%mod;
	po2[0]=po3[0]=1;for(int i=1;i<=n;i++) po2[i]=(ll)po2[i-1]*2%mod,po3[i]=(ll)po3[i-1]*3%mod;
	int ans=po3[n];
	for(int i=n/2+1;i<=n;i++)
	{
		int tmp=(ll)binom(n,i)*po2[n-i]%mod;
		ans-=tmp*2%mod;
		if(ans<0) ans+=mod;
	}
	printf("%i\n",ans);
	return 0;
}
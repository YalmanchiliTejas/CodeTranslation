#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,m,k,fact[200005],inv[200005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
ll C(int n,int m)
{
	if(n<m)return 0;
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	fact[0]=1;
	for(int i=1;i<=n*m;i++)fact[i]=fact[i-1]*i%MOD;
	inv[n*m]=quick_pow(fact[n*m],MOD-2);
	for(int i=n*m;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	ll ans=0;
	for(int i=1;i<n;i++)
		ans+=C(n*m-2,k-2)*i*m%MOD*(n-i)*m%MOD;
	swap(n,m);
	for(int i=1;i<n;i++)
		ans+=C(n*m-2,k-2)*i*m%MOD*(n-i)*m%MOD;
	printf("%lld\n",ans%MOD);
	return 0;
}
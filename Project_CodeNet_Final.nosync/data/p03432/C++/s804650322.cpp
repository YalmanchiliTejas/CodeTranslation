#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m;
ll f[8005],fact[8005],inv[8005];
ll A[20005],B[20005];
int limit,l,r[20005];
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
void NTT(ll*A,int type)
{
	for(int i=0;i<limit;i++)
	  if(i<r[i])swap(A[i],A[r[i]]);
	for(int mid=1;mid<limit;mid<<=1)
	{
		ll Wn=quick_pow(3,(MOD-1)/(mid<<1));
		for(int j=0,R=mid<<1;j<limit;j+=R)
		{
			ll w=1;
			for(int k=0;k<mid;k++,w=w*Wn%MOD)
			{
				ll x=A[j+k],y=A[j+mid+k]*w;
				A[j+k]=(x+y)%MOD;
				A[j+mid+k]=(x-y)%MOD;
			}
		}
	}
	if(type==-1)
	{
		ll inv=quick_pow(limit,MOD-2);
		for(int i=0;i<limit;i++)A[i]=A[i]*inv%MOD;
		for(int i=1;i<(limit>>1);i++)swap(A[i],A[limit-i]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	fact[0]=1;
	for(int i=1;i<=n+2;i++)fact[i]=fact[i-1]*i%MOD;
	inv[n+2]=quick_pow(fact[n+2],MOD-2);
	for(int i=n+2;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	f[0]=1;
	limit=1,l=0;
	while(limit<16384)limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=3;i<=n+2;i++)B[i]=inv[i];
	NTT(B,1);
	for(int t=1;t<=m;t++)
	{
		for(int i=0;i<n;i++)A[i]=f[i];
		for(int i=n;i<limit;i++)A[i]=0;
		NTT(A,1);
		for(int i=0;i<limit;i++)A[i]=A[i]*B[i]%MOD;
		NTT(A,-1);
		for(int i=0;i<=n;i++)f[i]=(f[i]*(i*(i+1)/2+1)+A[i+2]*(i+1)*(i+2))%MOD;
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
	  ans=(ans+f[i]*fact[n]%MOD*inv[n-i])%MOD;
	if(ans<0)ans+=MOD;
	printf("%lld\n",ans);
	return 0;
}
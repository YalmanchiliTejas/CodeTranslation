#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3010
using namespace std;
typedef long long ll;
ll n;
ll mod;
ll C[maxn][maxn],s[maxn][maxn];
ll qp(ll x,ll p,ll m)
{
	ll an=1;
	ll po=x;
	while(p)
	{
		if(p%2)   an=(an*po)%m;
		po=(po*po)%m;
		p/=2;
	}
	return an;
}
int main()
{
	scanf("%lld%lld",&n,&mod);
	C[0][0]=1;
	C[1][0]=1;C[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=n;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	s[0][0]=1;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=i;j++)
		{
			s[i][j]=(s[i-1][j-1]+(s[i-1][j]*(ll)j)%mod)%mod;
		}
	}
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		ll sum=1;
		sum=(sum*qp(2,qp(2,n-i,mod-1),mod))%mod;
		//cout<<sum<<endl;
		sum=(sum*C[n][i])%mod;
		ll x=0;
		for(int j=0;j<=i;j++)
		{
			x=(x+((qp(2,(ll)(n-i)*j%(mod-1),mod))*s[i+1][j+1])%mod)%mod;
		}
		sum=(sum*x)%mod;
		int k;
		if(i%2==0)  k=1;
		else        k=-1;
		sum=((sum*k)%mod+mod)%mod;
		ans=(ans+sum)%mod;
	}
	//cout<<ans<<endl;
	//ll tmp=qp((ll)n,mod-2,mod);
	//cout<<tmp<<endl;
	printf("%d\n",ans);
	return 0;
}
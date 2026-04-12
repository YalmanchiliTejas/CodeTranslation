#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const ll mod=998244353;

ll n;
ll jc[10000010];

ll power(ll a,ll b)
{
	ll res=1ll;
	while(b)
	{
		if(b&1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}

void init()
{
	jc[0]=1ll;
	for(ll i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
	}
}

ll C(ll x,ll y)
{
	return jc[x]*power(jc[x-y],mod-2)%mod*power(jc[y],mod-2)%mod;
}

int main()
{
	scanf("%lld",&n);
	init();
	ll ans=power(3ll,n);
	ll tot=0;
	for(ll i=n/2+1;i<=n;i++)
	{
//		cout<<"qaq"<<endl;
		tot=(tot+C(n,i)*power(2ll,n-i)%mod+mod)%mod;
	}
	printf("%lld",((ans-2*tot)%mod+mod)%mod);
	return 0;
}










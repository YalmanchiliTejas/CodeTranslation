#include<bits/stdc++.h>
using namespace std;

#define mx 200005
#define ll long long 
#define mod 1000000007

void IO()
{
     #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}

int ar[mx];
char ch[mx];

int m,n,k,ii;

ll bigmod(ll e,ll x)
{
    if(!x)return 1;
    ll p=bigmod(e,x/2);
    p=(p*p)%mod;
    if(x%2)p=(p*e)%mod;
    return p;
}


void solve()
{
	scanf("%d",&n);
	ll sum=0;
	ll sq=0;
	for(int i=1;i<=n;i++)
	{
		ll x;
		scanf("%lld",&x);
		sum+=x;
		sq+=(x*x)%mod;
		sq%=mod;
		sum%=mod;
	}
	sum*=sum;
	sum%=mod;
	sum-=sq;
	//cout<<sum<<endl;
	sum%=mod;
	sum+=mod;
	sum%=mod;
	//cout<<sum<<endl;
	printf("%lld\n",((bigmod(2,mod-2)%mod)*sum)%mod );
}

int main()
{
	IO();

	int t=1;
	while(t--)
	{
		solve();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%lld",&n)
#define pr(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define nl printf("\n")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
ll pow1(ll a, ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a;
		}
		a=a*a;
		b=b>>1;
	}
	return ans;
}
map<ll,ll> ma;
ll pcnt[55];
ll solve(ll n)
{
	if(n == 1)
	{
		string tmp = "BPPPB";
		ma[1] = 3;
		pcnt[1] = 3;
		return tmp.size();
	}
	ma[n] = 2ll*solve(n-1)+3;
	pcnt[n] = 2ll*pcnt[n-1]+1;
	// if(ma[n]!="")
	// 	return ma[n];
	// ma[n] = "B"+solve(n-1)+"P"+ma[n-1]+"B";
	// cout<<ma[n]<<endl;
	return ma[n];
}
ll ans(ll n,ll x)
{
	if(n==0 && x>0)
		return 1;
	if(n==0 && x<=0)
		return 0;
	if(x-1<=ma[n-1])
		return ans(n-1,x-1);
	return pcnt[n-1]+1+ans(n-1,x-2-ma[n-1]);
}
int main()
{
	ll n,i,j,x;
	string s;
	cin>>n>>x;
	pcnt[0] = 1;
	ma[0] = 1;
	for(i=1;i<=n;i++)
	{
		ma[i] = 2ll*ma[i-1]+3;
		pcnt[i] = 2ll*pcnt[i-1]+1;
	}
	// ll l = solve(n);
	// cout<<l<<endl;
	// ll cnt = pcnt[n];
	// ll k = 0;
	// for(i=1;i<=n;i++)
	// 	cout<<ma[i]<<" "<<pcnt[i]<<endl;
	// for(i=n;i>0;i--)
	// {
	// 	if(ma[i]>=x && x>=ma[i-1])
	// 	{
	// 		cout<<(x-pcnt[i-1])<<endl;
	// 		return 0;
	// 	}
	// }
	cout<<ans(n,x)<<endl;
	return 0;
}
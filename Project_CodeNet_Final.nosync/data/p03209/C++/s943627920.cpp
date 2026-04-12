#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

const int INF = 1e9 ;
const int maxN = 200 + 5;
ll n,k;
ll h[maxN];
ll t[maxN];
ll solve(ll n,ll x)
{
	if(n == 0)
		return 1;
	ll mid = (h[n]+1)/2;
	if(x == h[n])
		return t[n];
	else if (x==1)
		return 0;
	else if(x<mid)
	{
		return solve(n-1,x-1);
	}
	else if(x == mid)
	{
		return solve(n-1,x-2) + 1;
	}
	else if(x>mid)
	{
		return t[n-1] + 1 + solve(n-1,x-mid);
	}
}

int main()
{
	scanf("%lld%lld",&n,&k);
	h[0] = 1;
	t[0] = 1;
	for(int i=1;i<=n;i++)
	{
		h[i] = 3 + 2*h[i-1];
		t[i] = 2 * t[i-1] + 1;
	}
	ll ans = solve(n,k);
	printf("%lld\n",ans);
	return 0;
} 
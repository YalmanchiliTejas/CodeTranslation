#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll lev[100010], vis[100010], dis[100010], st=-1, en=-1, n, m, x;

void dfs(ll src, ll d)
{
	lev[d]=src;
	vis[src]=1;
	dis[src]=d;
	ll a=(src*src)%m;
	if(vis[a]==1)
	{
		st=dis[a];
		en=d;
		return;
	}
	dfs(a, d+1);
}

int main()
{
	ll i, j;

	scanf("%lld %lld %lld", &n, &x, &m);

	dfs(x, 1);

	if(n<=en)
	{
		ll res=0;
		for(i=1; i<=n; i++) res+=lev[i];
		printf("%lld\n", res);
		return 0;
	}

	ll res=0;

	for(i=1; i<st; i++) res+=lev[i];

	n-=(st-1);

	ll unit=en-st+1, per=0;
	
	for(i=st; i<=en; i++) per+=lev[i];

	res+=per*(n/unit);
	
	n=n%unit;

	for(i=st; i<st+n; i++) res+=lev[i];

	printf("%lld\n", res);




	return 0;
}
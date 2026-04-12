#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define mk make_pair
#define pb push_back
#define eps 1e-12
#define sd(x) scanf("%d",&x)
#define sdl(x) scanf("%lld",&x)
#define pd(x) printf("%d\n",x)
#define pdl(x) printf("%lld\n",x)
#define MAXN 200009
using namespace std;
int fans[MAXN];
vector<pii> v;
int main()
{
	int n;
	sd(n);
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.pb(mk(x,i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<(n/2);i++)
	{
		fans[v[i].second]=v[n/2].first;
	}
	for(int i=(n/2);i<v.size();i++)
	{
		fans[v[i].second]=v[(n/2)-1].first;
	}
	for(int i=0;i<n;i++)
	{
		pd(fans[i]);
	}
	return 0;
}
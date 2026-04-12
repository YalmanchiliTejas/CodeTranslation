#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define mk make_pair
#define pb push_back
#define eps 1e-12
#define MAXN 200009
using namespace std;
struct pree
{
	int x,y,cost;
};
inline bool compare(pree uu,pree vv)
{
	return uu.cost<vv.cost;
}
pree edge[MAXN];
int par[MAXN];
inline int parent(int pos)
{
	if(par[pos]!=pos)
	{
		par[pos]=parent(par[pos]);
	}
	return par[pos];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	pll a[n+1];
	vector<pli> v,v1;
	ll x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		v.pb(mk(x,i));
		v1.pb(mk(y,i));
	}
	sort(v.begin(),v.end());
	sort(v1.begin(),v1.end());
	int sz=0;
	for(int i=0;i<v.size()-1;i++)
	{
		edge[sz].x=v[i].second;
		edge[sz].y=v[i+1].second;
		edge[sz].cost=abs(v[i].first-v[i+1].first);
		sz++;
	}
	for(int i=0;i<v1.size()-1;i++)
	{
		edge[sz].x=v1[i].second;
		edge[sz].y=v1[i+1].second;
		edge[sz].cost=abs(v1[i].first-v1[i+1].first);
		sz++;
	}
	sort(edge,edge+sz,compare);
	ll ans=0;
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
	}
	for(int i=0;i<sz;i++)
	{
		pree p=edge[i];
		int p1=parent(p.x);
		int p2=parent(p.y);
		//cout<<p.x<<" "<<p.y<<" "<<p.cost<<"\n";
		if(p1!=p2)
		{
			par[max(p1,p2)]=min(p1,p2);
			ans=ans+p.cost;
		}
	}
	cout<<ans<<"\n";
}
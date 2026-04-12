#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)

ll n,x[N],y[N],par[N],ans;
vector <pair<ll,ll> > vx,vy;
set <pair<ll,pair<ll,ll> > > s;

ll root(ll x){if(par[x]==-1)return x;return par[x]=root(par[x]);}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
		vx.push_back({x[i],i});
		vy.push_back({y[i],i});
		par[i]=-1;
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	for(int i=1;i<vx.size();i++)
	{
		s.insert({vx[i].first-vx[i-1].first,{vx[i].second,vx[i-1].second}});
		s.insert({vy[i].first-vy[i-1].first,{vy[i].second,vy[i-1].second}});
	}
	while(s.size())
	{
		ll val=s.begin()->first;
		ll v=s.begin()->second.first,u=s.begin()->second.second;
		s.erase(s.begin());
		v=root(v);u=root(u);
		if(v==u)continue;
		ans+=val;
		par[v]=u;
	}
	cout<<ans<<"\n";
	return 0;
}
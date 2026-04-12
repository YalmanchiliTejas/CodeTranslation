#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,p[200010];
pair<ll,ll> v[200010],u[200010];
vector<pair<ll,pair<ll,ll> > > vec;

inline ll Find(ll x)
{
	return p[x]==x?x:p[x]=Find(p[x]);
}

inline ll unite(ll x,ll y)
{
	ll fx=Find(x),fy=Find(y);
	if(fx==fy) return true;
	else{p[fx]=fy;return false;}
}

int main()
{
	cin>>n;
	for(ll i=1;i<=n;i++) scanf("%I64d%I64d",&v[i].first,&u[i].first);
	for(ll i=1;i<=n;i++) v[i].second=i,u[i].second=i;
	sort(v+1,v+n+1);
	sort(u+1,u+n+1);
	for(ll i=2;i<=n;i++){
		ll vcost=v[i].first-v[i-1].first;
		ll ucost=u[i].first-u[i-1].first;
		vec.push_back(make_pair(vcost,make_pair(v[i].second,v[i-1].second)));
		vec.push_back(make_pair(ucost,make_pair(u[i].second,u[i-1].second)));
	}
	for(ll i=1;i<=n;i++) p[i]=i;
	ll road=0,sum=0;
	sort(vec.begin(),vec.end());
	for(ll i=0;i<vec.size()&&road<n-1;i++){
		if(unite(vec[i].second.first,vec[i].second.second)) continue;
		sum+=vec[i].first;
		road++;
	}
	cout<<sum<<endl;
	return 0;
}
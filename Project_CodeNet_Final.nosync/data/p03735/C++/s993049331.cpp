#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

ii a[200001];

bool cmp(const ii &a, const ii &b)
{
	if(max(a.fi,a.se)!=max(b.fi,b.se)) return max(a.fi,a.se)<max(b.fi,b.se);
	return a.fi<b.fi;
}

bool cmp2(const ii &a, const ii &b)
{
	if(min(a.fi,a.se)!=min(b.fi,b.se)) return min(a.fi,a.se)<min(b.fi,b.se);
	return a.fi<b.fi;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<ll> x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].fi>>a[i].se;
		if(a[i].fi<a[i].se) swap(a[i].fi,a[i].se);
		x.pb(a[i].fi); x.pb(a[i].se);
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	ll ans = ll(2e18);
	deque<ii> vec(n);
	ll tmp = 0;
	for(int i=0;i<n;i++)
	{
		vec[i]=a[i];
		tmp=max(tmp,min(vec[i].fi,vec[i].se));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i = 1; i < x.size(); i++)
	{
		ll bmin = x[0]; ll rrange = x.back() - x[i];
		if(max(vec.front().fi,vec.front().se)<x[i])
		{
			break;
		}
		ans=min(ans,rrange*(tmp-bmin));
	}
	ll mm = max(vec.front().fi,vec.front().se);
	ll rrange = x.back()-x[0];
	sort(vec.begin(),vec.end(),cmp2);
	for(int i=0;i<x.size();i++)
	{
		if(x[i]>mm) break;
		ll bmin=x[i];
		while(!vec.empty()&&min(vec.front().fi,vec.front().se)<x[i])
		{
			tmp=max(tmp,max(vec.front().fi,vec.front().se));
			vec.pop_front();
		}
		ans=min(ans,(tmp-bmin)*rrange);
	}
	cout<<ans<<'\n';
}

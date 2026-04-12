/*
problem's name:
statue:
writer:Patrick_y
*/
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#include <cctype>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include <time.h>
#define mp make_pair
typedef long long ll;
using namespace std;
const ll INF=20050208;
/*------------main part------------*/
pair<ll,ll> sx[100005];
pair<ll,ll> sy[100005];
ll px[100005];
ll py[100005];
set<pair<ll,pair<ll,ll > > > st;
ll par[100005];
ll find(ll x)
{
	return x==par[x]?x:par[x]=find(par[x]);
}
ll dis(ll a,ll b)
{
	return min(abs(px[a]-px[b]),abs(py[a]-py[b]));
}
ll un(ll x,ll y)
{
	x=find(x);
	y=find(y);
	if(x==y)
	{
		return 0;
	}
	par[x]=y;
	return 1;
}
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		ll x,y;
		cin>>x>>y;
		par[i]=i;
		sx[i]=(mp(x,i));
		sy[i]=(mp(y,i));
		px[i]=x;
		py[i]=y;
	}
	sort(sx,sx+n);
	sort(sy,sy+n);
	for(ll i=0;i<n-1;i++)
	{
		st.insert(mp(dis(sx[i].second,sx[i+1].second),mp(sx[i].second,sx[i+1].second)));
		st.insert(mp(dis(sy[i].second,sy[i+1].second),mp(sy[i].second,sy[i+1].second)));
	}
	ll ans=0;
	while((int)st.size())
	{
		pair<ll,pair<ll,ll > > cur=*(st.begin());
		st.erase(cur);
		ll a=cur.second.first;
		ll b=cur.second.second;
		ans+=un(a,b)*dis(a,b);
	}
	cout<<ans;
	return 0;
}
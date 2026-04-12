#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%lld",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define mod 1000000007
#define bitcount __builtin_popcountll
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define pii pair<pi,ll>
#define mp make_pair
vector<pii>edges;
vector<ll>v[100005],v2[100005];
ll dist1[100005],dist2[100005],ways1[100005],ways2[100005];
struct compare
{
	bool operator()(pii x, pii y)
	{
		return x.first.first>y.first.first;
	}
};
int main()
{
	ll i,j,k;
	ll n,m,s,t;
	sd(n);
	sd(m);
	sd(s);
	sd(t);
	while(m--)
	{
		sd(i);
		sd(j);
		sd(k);
		v[i].pb(j);
		v[j].pb(i);
		v2[i].pb(k);
		v2[j].pb(k);
		edges.pb(mp(mp(i,j),k));
	}
	for(i=1;i<=n;i++)
	{
		dist1[i]=dist2[i]=1e18;
	}
	priority_queue<pii,vector<pii>,compare>pq;
	pq.push(mp(mp(0,s),0));
	ways1[0]=ways2[0]=1;
	while(!pq.empty())
	{
		pii x=pq.top();
		pq.pop();
		if(dist1[x.first.second]==x.first.first)
		{
			ways1[x.first.second]+=ways1[x.second];
			if(ways1[x.first.second]>=mod)
				ways1[x.first.second]-=mod;
			continue;
		}
		if(dist1[x.first.second]!=1e18)
			continue;
		dist1[x.first.second]=x.first.first;
		ways1[x.first.second]+=ways1[x.second];
		if(ways1[x.first.second]>=mod)
			ways1[x.first.second]-=mod;
		for(i=0;i<v[x.first.second].size();i++)
		{
			if(dist1[v[x.first.second][i]]==1e18)
			{
				pq.push(mp(mp(dist1[x.first.second]+v2[x.first.second][i],v[x.first.second][i]),x.first.second));
			}
		}
	}
	pq.push(mp(mp(0,t),0));
	while(!pq.empty())
	{
		pii x=pq.top();
		pq.pop();
		if(dist2[x.first.second]==x.first.first)
		{
			ways2[x.first.second]+=ways2[x.second];
			if(ways2[x.first.second]>=mod)
				ways2[x.first.second]-=mod;
			continue;
		}
		if(dist2[x.first.second]!=1e18)
			continue;
		dist2[x.first.second]=x.first.first;
		ways2[x.first.second]+=ways2[x.second];
		if(ways2[x.first.second]>=mod)
			ways2[x.first.second]-=mod;
		for(i=0;i<v[x.first.second].size();i++)
		{
			if(dist2[v[x.first.second][i]]==1e18)
			{
				pq.push(mp(mp(dist2[x.first.second]+v2[x.first.second][i],v[x.first.second][i]),x.first.second));
			}
		}
	}
	ll cnt=0;
	for(i=1;i<=n;i++)
	{
		if(dist1[i]==dist2[i]&&dist1[t]==2*dist1[i])
		{
			int temp=(1ll*ways1[i]*ways2[i])%mod;
			cnt+=(1ll*temp*temp)%mod;
			if(cnt>=mod)
				cnt-=mod;
		}
	}
	// printf("%lld\n",cnt );
	for(i=0;i<edges.size();i++)
	{
		ll x=edges[i].first.first;
		ll y=edges[i].first.second;
		// printf("here2\n");
		if(dist1[x]<dist1[y]&&dist1[x]+dist2[y]+edges[i].second==dist1[t]&&2*dist1[x]<dist1[t]&&2*dist2[y]<dist2[s])
		{
			int temp=(1ll*ways1[x]*ways2[y])%mod;
			cnt+=(1ll*temp*temp)%mod;
			if(cnt>=mod)
				cnt-=mod;
		}
		else if(dist1[y]<dist1[x]&&dist1[y]+dist2[x]+edges[i].second==dist1[t]&&2*dist1[y]<dist1[t]&&2*dist2[x]<dist2[s])
		{
			int temp=(1ll*ways1[y]*ways2[x])%mod;
			cnt+=(1ll*temp*temp)%mod;
			if(cnt>=mod)
				cnt-=mod;
		}
	}
	ll temp=(ways1[t]*ways1[t])%mod;
	temp-=cnt;
	temp+=mod;
	if(temp>=mod)
		temp-=mod;
	printf("%lld\n",temp );
	return 0;
}
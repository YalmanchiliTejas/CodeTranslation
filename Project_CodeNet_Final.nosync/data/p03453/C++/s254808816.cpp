#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=2e5+10,inf=1e18+10,mod=1e9+7,M2=1e6+10,M3=3e3+10;
int dp[M],d[M],d2[M],dp2[M];
bool mark[M];
vector<int>adj[M],edg[M];
set<pii>dij;
main()
{
	int n,m,s,e,a,b,w;
	cin>>n>>m;
	cin>>s>>e;
	for(int i=1;i<=m;i++)cin>>a>>b>>w,adj[a].pb(b),adj[b].pb(a),edg[a].pb(w),edg[b].pb(w);
	dij.insert(mp(0,s));
	for(int i=1;i<=n;i++)d[i]=inf;
	d[s]=0;
	dp[s]=1;
	while(dij.size())
	{
		pii now=*dij.begin();
		int v=now.S;
		//cout<<v<<"*****";
		mark[v]=1;
		dij.erase(now);
		for(int i=0;i<adj[v].size();i++)
		{
			int u=adj[v][i];
			if(mark[u])continue;
			dij.erase(mp(d[u],u));
			if(d[u]>d[v]+edg[v][i])dp[u]=dp[v],d[u]=d[v]+edg[v][i];
			else if(d[u]==d[v]+edg[v][i])dp[u]+=dp[v],dp[u]%=mod;
			dij.insert(mp(d[u],u));
		}
	}
	dij.clear();
	dij.insert(mp(0,e));
	for(int i=1;i<=n;i++)d2[i]=inf,mark[i]=0;
	d2[e]=0;
	dp2[e]=1;
	while(dij.size())
	{
		pii now=*dij.begin();
		int v=now.S;
		mark[v]=1;
		dij.erase(now);
		for(int i=0;i<adj[v].size();i++)
		{
			int u=adj[v][i];
			if(mark[u])continue;
			dij.erase(mp(d2[u],u));
			if(d2[u]>d2[v]+edg[v][i])dp2[u]=dp2[v],d2[u]=d2[v]+edg[v][i];
			else if(d2[u]==d2[v]+edg[v][i])dp2[u]+=dp2[v],dp2[u]%=mod;
			dij.insert(mp(d2[u],u));
		}
	}
	int ans=dp[e]*dp2[s];
	//cout<<dp[e]<<" "<<dp2[s]<<" ";
	ans%=mod;
	//cout<<ans<<" ";
	for(int i=1;i<=n;i++)
	{
		int v=i;
		if(d[i]+d2[i]==d[e] && d[i]==d2[i]){
			int tmp=dp[i]*dp2[i];
			//cout<<i<<" ";
			tmp%=mod;
			tmp*=tmp;
			tmp%=mod;
			ans-=tmp;
			ans+=mod;
			ans%=mod;
			continue;
		}
		//cout<<d[e]<<endl;
		for(int j=0;j<adj[i].size();j++)
		{
			int u=adj[i][j];
			w=edg[i][j];
			if(d[v]>d[u])continue;
			if(abs(d[v]-d2[u])<w && d[v]+d2[u]+w==d[e])
			{
				//cout<<v<<" ";
				int tmp=dp[v]*dp2[u];
				tmp%=mod;
				tmp*=tmp;
				tmp%=mod;
				ans-=tmp;
				ans+=mod;
				ans%=mod;
			}
		}
	}
	cout<<ans;
}
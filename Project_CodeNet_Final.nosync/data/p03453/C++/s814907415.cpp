#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
vector<pair<int,long long> > nei[100005];
int n,m,s,t;
long long dis1[100005],dis2[100005];
void dij()
{
	priority_queue<pair<long long,int> > q1;
	q1.push(make_pair(0,s));
	
	memset(dis1,-1,sizeof(dis1));dis1[s]=0;
	while(!q1.empty())
	{
		long long d=q1.top().first;
		int x=q1.top().second;
		q1.pop();
		for(int i=0;i<nei[x].size();i++)
		{
			if(dis1[nei[x][i].first]<=-d+nei[x][i].second&&dis1[nei[x][i].first]!=-1) continue;
			dis1[nei[x][i].first]=-d+nei[x][i].second;
			q1.push(make_pair(d-nei[x][i].second,nei[x][i].first));
		}
	}
	
	
	priority_queue<pair<long long,int> > q2;
	q2.push(make_pair(0,t));
	memset(dis2,-1,sizeof(dis2));dis2[t]=0;
	while(!q2.empty())
	{
		long long d=q2.top().first;
		int x=q2.top().second;
		q2.pop();
		for(int i=0;i<nei[x].size();i++)
		{
			if(dis2[nei[x][i].first]<=-d+nei[x][i].second&&dis2[nei[x][i].first]!=-1) continue;
			dis2[nei[x][i].first]=-d+nei[x][i].second;
			q2.push(make_pair(d-nei[x][i].second,nei[x][i].first));
		}
	}
}
long long dp1[100005],dp2[100005];
long long dfs1(int v)
{
	if(dp1[v]!=-1) return dp1[v];
	dp1[v]=0;
	for(int i=0;i<nei[v].size();i++)
	{
		if(dis1[v]+nei[v][i].second==dis1[nei[v][i].first])
		{
			dp1[v]+=dfs1(nei[v][i].first);
			dp1[v]%=1000000007;
		}
	}
	return dp1[v];
}
vector<pair<int,int> >res;
long long dfs2(int v)
{
	if(dp2[v]!=-1) return dp2[v];
	dp2[v]=0;
	for(int i=0;i<nei[v].size();i++)
	{
		if(dis2[v]+nei[v][i].second==dis2[nei[v][i].first])
		{
			dp2[v]+=dfs2(nei[v][i].first);
			if(dis2[v]<dis1[v]&&dis2[nei[v][i].first]>dis1[nei[v][i].first]) res.push_back(make_pair(v,nei[v][i].first));
		//	if(dis2[v]*2==dis) res.push_back(make_pair(v,v));
			dp2[v]%=1000000007;
		}
	}
	return dp2[v];
}
long long mul(long long x)
{
	return x*x%1000000007;
}
int main()
{
	cin>>n>>m>>s>>t;
	s--,t--;
	for(int i=0;i<m;i++)
	{
		int u,v;
		long long d;
		cin>>u>>v>>d;
		u--,v--;
		nei[u].push_back(make_pair(v,d));
		nei[v].push_back(make_pair(u,d));
	}
	dij();
	memset(dp1,-1,sizeof(dp1));
	memset(dp2,-1,sizeof(dp2));
	dp1[t]=1;
	dp2[s]=1;
	dfs1(s);
	dfs2(t);
	for(int i=0;i<n;i++)if(dis1[i]*2==dis1[t]) res.push_back(make_pair(i,i));
	long long ans=mul(dp1[s]);
	for(int i=0;i<res.size();i++)
	{
		ans=ans-mul((1ll*dp1[res[i].first]*dp2[res[i].second])%1000000007);
		ans%=1000000007;
		if(ans<0) ans+=1000000007;
	}
	cout<<ans;
}
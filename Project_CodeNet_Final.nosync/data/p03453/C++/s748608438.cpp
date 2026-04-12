#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007LL;

void dijk(int s, vector<vector<pair<int,int>>> &E, vector<long long> &D, vector<long long> &cnt)
{
    int N=D.size(),vis[N+10];
    for (int i = 0; i < N; ++i)
    {
        D[i]=10000000000000000LL;
    }
    for (int i = 0; i < N; ++i)
    {
        vis[i]=0;
    }
 	for (int i = 0; i < N; ++i)
 	{
 		cnt[i]=0;
 	}

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;
 
    D[s] = 0LL;
    cnt[s] = 1LL;
    que.push({ 0, s });
 
    while (!que.empty()) 
    {
        auto q = que.top(); que.pop();
 
        long long cst = q.first;
        int cu = q.second;
 
        if (vis[cu]) continue;
        vis[cu] = 1;
 
        for(auto &p:E[cu]) 
        {
            int to = p.first;
 
           	if (vis[to]==0)
           	{
           		if (D[cu]+p.second<D[to])
           		{
           			D[to]=D[cu]+p.second;
           			cnt[to]=cnt[cu];
           			que.push({D[to],to});
           		}
           		else if (D[cu]+p.second==D[to])
           		{
           			cnt[to]+=cnt[cu];
           			cnt[to]%=mod;
           		}
           	}
        }
    }
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;--s;--t;
	int u,v,d;
    vector<vector<pair<int,int>>> edge(n);
	for (int i = 0; i < m; ++i)
	{
		cin>>u>>v>>d;--u;--v;
		edge[u].push_back({v,d});
		edge[v].push_back({u,d});
	}
    vector<long long> ds(n),dt(n),cs(n),ct(n);
    dijk(s,edge,ds,cs);
    dijk(t,edge,dt,ct);
    long long ans=cs[t]*cs[t]%mod;
    for (int i = 0; i < n; ++i)
    {
    	if (ds[i]+dt[i]==ds[t]&&ds[i]*2LL==ds[t])
    	{
    		long long tmp=cs[i]*ct[i]%mod;
    		ans-=tmp*tmp%mod;
    		ans%=mod;
    	}
    }
    for (int i = 0; i < n; ++i)
    {
    	for (auto v:edge[i])
    	{
    		long long l=(long long)v.second;
    		if (ds[i]+l+dt[v.first]==ds[t]&&ds[i]*2LL<ds[t]&&dt[v.first]*2LL<ds[t])
    		{
    			long long tmp=cs[i]*ct[v.first]%mod;
    			ans-=tmp*tmp%mod;
    			ans%=mod;
    		}
    	}
    }
    ans%=mod;
    if (ans<0)
    {
    	ans+=mod;
    }
    cout<<ans<<endl;
    return 0;
}


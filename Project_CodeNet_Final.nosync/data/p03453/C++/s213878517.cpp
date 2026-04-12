#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#include<vector>
#include<queue>
#include<limits>
template<typename T>
vector<T>dijkstra(int s,const vector<vector<pair<int,T> > >&G,T INF=numeric_limits<T>::max())
{
	int n=G.size();
	vector<T>d(n,INF);
	vector<int>parent(n,-1);
	priority_queue<pair<T,int>,vector<pair<T,int> >,greater<pair<T,int> > >P;
	d[s]=0;
	P.push(make_pair(d[s],s));
	while(!P.empty())
	{
		pair<T,int>p=P.top();P.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(const pair<int,T>&e:G[v])
		{
			int u=e.first;
			T cost=d[v]+e.second;
			if(d[u]>cost)
			{
				d[u]=cost;
				parent[u]=v;
				P.push(make_pair(d[u],u));
			}
		}
	}
	return d;
}
int N,M,S,T;
long mod=1e9+7;
vector<pair<pair<int,int>,int> >edge;
main()
{
	cin>>N>>M>>S>>T;
	S--,T--;
	vector<vector<pair<int,long> > >G(N);
	for(int i=0;i<M;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		a--,b--;
		edge.push_back({{a,b},c});
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	vector<long>d1=dijkstra(S,G);
	vector<long>d2=dijkstra(T,G);
	vector<long>dp1(N,0),dp2(N,0);
	vector<bool>u1(N,false),u2(N,false);
	dp1[S]=1;
	u1[S]=1;
	priority_queue<pair<long,int> >P;
	P.push({0,S});
	while(!P.empty())
	{
		int u=P.top().second;P.pop();
		for(int i=0;i<G[u].size();i++)
		{
			if(d1[G[u][i].first]!=d1[u]+G[u][i].second)continue;
			int v=G[u][i].first;
			long d=G[u][i].second;
			(dp1[v]+=dp1[u])%=mod;
			if(!u1[v])
			{
				P.push({-d1[v],v});
				u1[v]=1;
			}
		}
	}
	dp2[T]=1;
	u2[T]=1;
	P.push({0,T});
	while(!P.empty())
	{
		int u=P.top().second;P.pop();
		for(int i=0;i<G[u].size();i++)
		{
			if(d2[G[u][i].first]!=d2[u]+G[u][i].second)continue;
			int v=G[u][i].first;
			long d=G[u][i].second;
			(dp2[v]+=dp2[u])%=mod;
			if(!u2[v])
			{
				P.push({-d2[v],v});
				u2[v]=1;
			}
		}
	}
	vector<pair<long,long> >E;
	long sa=0,sb=0;
	vector<bool>pu(N,false);
	long ans=dp1[T]*dp1[T]%mod;
	for(int i=0;i<N;i++)
	{
		if(d1[i]==d2[i]&&d1[i]+d2[i]==d1[T])
		{
			pu[i]=1;
			ans=(ans-dp1[i]*dp2[i]%mod*dp1[i]%mod*dp2[i]%mod+mod)%mod;
		}
	}
	for(int i=0;i<edge.size();i++)
	{
		int u=edge[i].first.first,v=edge[i].first.second;
		if(d1[u]>d1[v])swap(u,v);
		if(d1[u]+d2[v]+edge[i].second!=d1[T])continue;
		if(pu[u]||pu[v])continue;
		if(abs(d1[u]-d1[v])<=edge[i].second)
		{
			if(d1[u]<d2[u]&&d1[v]>d2[v])
			{
				ans=(ans-dp1[u]*dp2[v]%mod*dp1[u]%mod*dp2[v]%mod+mod)%mod;
			}
		}
	}
	cout<<ans<<endl;
}

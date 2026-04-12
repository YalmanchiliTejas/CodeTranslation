#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct UF{
	int n;
	vector<int>parent,rank;
	UF(int n_=0):n(n_),parent(n_),rank(n_,1)
	{
		for(int i=0;i<n_;i++)parent[i]=i;
	}
	int find(int a){return parent[a]!=a?parent[a]=find(parent[a]):a;}
	bool same(int a,int b){return find(a)==find(b);}
	bool unite(int a,int b)
	{
		a=find(a),b=find(b);
		if(a==b)return false;
		if(rank[a]<rank[b])
		{
			parent[a]=b;
			rank[b]+=rank[a];
		}
		else
		{
			parent[b]=a;
			rank[a]+=rank[b];
		}
		return true;
	}
};
int N,M,Q;
vector<pair<int,pair<int,int> > >E;
vector<pair<int,int> >G[4001];
int T[4001][4001];
void dfs(int u,int p,int now,int f)
{
	T[f][u]=now;
	for(pair<int,int>q:G[u])if(q.first!=p)dfs(q.first,u,max(now,q.second),f);
}
main()
{
	cin>>N>>M;
	for(int i=0;i<M;i++)
	{
		int a,b,c;cin>>a>>b>>c;
		E.push_back({c,{a,b}});
	}
	sort(E.begin(),E.end());
	UF uf(N+1);
	long sum=0;
	for(pair<int,pair<int,int> >p:E)
	{
		int u=p.second.first,v=p.second.second;
		if(uf.unite(u,v))
		{
			sum+=p.first;
			G[u].push_back({v,p.first});
			G[v].push_back({u,p.first});
		}
	}
	for(int i=0;i++<N;)dfs(i,0,0,i);
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		int a,b;cin>>a>>b;
		cout<<sum-T[a][b]<<endl;
	}
}
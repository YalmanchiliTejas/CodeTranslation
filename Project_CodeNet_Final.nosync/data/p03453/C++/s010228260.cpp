#include<iostream>
#include<queue>
using namespace std;
int N,M,S,T,u,v,D;
vector<pair<int,int>>G[1<<17];
long mod=1e9+7,a[1<<17],b[1<<17],c[1<<17],d[1<<17];
priority_queue<pair<long,int>>P;
void calc(int S,long*d,long*w)
{
	for(int i=w[S]=1;i<=N;)d[i++]=-1e18;
	P.push({d[S]=0,S});
	while(P.size())
	{
		long c=P.top().first,u=P.top().second;
		P.pop();
		if(d[u]==c)for(pair<int,int>p:G[u])
		{
			long v=p.first,nxt=c-p.second;
			if(d[v]<nxt)w[v]=w[u],P.push({d[v]=nxt,v});
			else if(d[v]==nxt)(w[v]+=w[u])%=mod;
		}
	}
}
main()
{
	cin>>N>>M>>S>>T;
	for(;cin>>u>>v>>D;G[v].push_back({u,D}))G[u].push_back({v,D});
	calc(S,a,b);calc(T,c,d);
	long ans=b[T]*b[T],t=a[T];
	for(u=0;u++<N;)
	{
		if(2*a[u]==t)ans-=b[u]*b[u]%mod*d[u]%mod*d[u]%mod;
		for(pair<int,int>p:G[u])if(2*a[u]>t&&2*a[v=p.first]<t&&a[u]+c[v]-p.second==t)ans-=b[u]*b[u]%mod*d[v]%mod*d[v]%mod;
	}
	cout<<(ans+mod)%mod;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,M,S,T;
vector<pair<int,int> >G[1<<17];
long mod=1e9+7,a[1<<17],b[1<<17],c[1<<17],d[1<<17];
priority_queue<pair<long,int> >P;
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
	for(int i=0;i<M;i++)
	{
		int u,v,d;cin>>u>>v>>d;
		G[u].push_back({v,d});
		G[v].push_back({u,d});
	}
	calc(S,a,b);
	calc(T,c,d);
	long ans=b[T]*b[T],dt=a[T];;
	for(int i=0;i++<N;)
	{
		if(2*a[i]==dt)ans-=b[i]*b[i]%mod*d[i]%mod*d[i]%mod;
		for(pair<int,int>p:G[i])
		{
			int v=p.first;
			if(2*a[i]>dt&&2*a[v]<dt&&a[i]+c[v]-p.second==dt)ans-=b[i]*b[i]%mod*d[v]%mod*d[v]%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
}

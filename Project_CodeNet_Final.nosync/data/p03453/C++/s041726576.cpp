#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long mod=1e9+7;
int N,M,S,T;
vector<pair<int,int> >G[1<<17];
long a[1<<17],b[1<<17],c[1<<17],d[1<<17];
void calc(int S,long*d,long*w)
{
	for(int i=0;i++<N;)d[i]=-1e18;
	priority_queue<pair<long,int> >P;
	w[S]=1;
	P.emplace(d[S]=0,S);
	while(!P.empty())
	{
		long c=P.top().first;
		int u=P.top().second;
		P.pop();
		if(d[u]>c)continue;
		for(pair<int,int>p:G[u])
		{
			int v=p.first;
			long nxt=c-p.second;
			if(d[v]<nxt)
			{
				w[v]=w[u];
				P.emplace(d[v]=nxt,v);
			}
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
		G[u].push_back(make_pair(v,d));
		G[v].push_back(make_pair(u,d));
	}
	calc(S,a,b);
	calc(T,c,d);
	long ans=b[T]*b[T];
	for(int i=0;i++<N;)
	{
		if(2*a[i]==a[T])ans-=b[i]*b[i]%mod*d[i]%mod*d[i]%mod;
		for(pair<int,int>p:G[i])
		{
			int v=p.first;
			if(2*a[i]>a[T]&&2*a[v]<a[T]&&a[i]+c[v]-p.second==a[T])
				ans-=b[i]*b[i]%mod*d[v]%mod*d[v]%mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
}

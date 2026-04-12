#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long mod=1e9+7;
int N,M,S,T;
vector<pair<int,int> >G[1<<17];
long d[2][1<<17],w[2][1<<17];
void calc(int S,long*d,long*w)
{
	for(int i=0;i++<N;)d[i]=1e18;
	priority_queue<pair<long,int> >P;
	d[S]=0;
	w[S]=1;
	P.push(make_pair(0,S));
	while(!P.empty())
	{
		long c=-P.top().first;
		int u=P.top().second;
		P.pop();
		if(d[u]<c)continue;
		for(pair<int,int>p:G[u])
		{
			int v=p.first;
			long nxt=c+p.second;
			if(d[v]>nxt)
			{
				d[v]=nxt;
				w[v]=w[u];
				P.push(make_pair(-d[v],v));
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
	calc(S,d[0],w[0]);
	calc(T,d[1],w[1]);
	long ans=w[0][T]*w[0][T]%mod;
	for(int i=0;i++<N;)
	{
		if(2*d[0][i]==d[0][T])
			(ans-=w[0][i]*w[0][i]%mod*w[1][i]%mod*w[1][i])%=mod;
		for(pair<int,int>p:G[i])
		{
			int v=p.first;
			if(2*d[0][i]<d[0][T]&&2*d[0][v]>d[0][T]&&d[0][i]+d[1][v]+p.second==d[0][T])
				(ans-=w[0][i]*w[0][i]%mod*w[1][v]%mod*w[1][v])%=mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
long mod=1e9+7;
int N,M,S[2];
vector<pair<int,int> >G[1<<17];
int U[2<<17],V[2<<17],D[2<<17];
long d[2][1<<17],w[2][1<<17];
main()
{
	cin>>N>>M>>S[0]>>S[1];
	for(int i=0;i<M;i++)
	{
		cin>>U[i]>>V[i]>>D[i];
		G[U[i]].push_back(make_pair(V[i],D[i]));
		G[V[i]].push_back(make_pair(U[i],D[i]));
	}
	for(int _=0;_<2;_++)
	{
		for(int i=0;i++<N;)d[_][i]=1e18;
		priority_queue<pair<long,int> >P;
		d[_][S[_]]=0;
		w[_][S[_]]=1;
		P.push(make_pair(0,S[_]));
		while(!P.empty())
		{
			long c=-P.top().first;
			int u=P.top().second;
			P.pop();
			if(d[_][u]<c)continue;
			for(pair<int,int>p:G[u])
			{
				int v=p.first;
				long nxt=c+p.second;
				if(d[_][v]>nxt)
				{
					d[_][v]=nxt;
					w[_][v]=w[_][u];
					P.push(make_pair(-d[_][v],v));
				}
				else if(d[_][v]==nxt)(w[_][v]+=w[_][u])%=mod;
			}
		}
	}
	int T=S[1];
	long ans=w[0][T]*w[0][T]%mod;
	for(int i=0;i++<N;)
	{
		if(2*d[0][i]==d[0][T])
		{
			(ans-=w[0][i]*w[0][i]%mod*w[1][i]%mod*w[1][i])%=mod;
		}
	}
	for(int i=0;i<M;i++)
	{
		int u=U[i],v=V[i];
		if(2*d[0][u]<d[0][T]&&2*d[0][v]>d[0][T]&&d[0][u]+D[i]+d[1][v]==d[0][T])
		{
			(ans-=w[0][u]*w[0][u]%mod*w[1][v]%mod*w[1][v])%=mod;
		}
		if(2*d[0][v]<d[0][T]&&2*d[0][u]>d[0][T]&&d[0][v]+D[i]+d[1][u]==d[0][T])
		{
			(ans-=w[0][v]*w[0][v]%mod*w[1][u]%mod*w[1][u])%=mod;
		}
	}
	cout<<(ans+mod)%mod<<endl;
}
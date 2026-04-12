#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

vector<pair<int,long long > >graph[100005];

long long d1[100005];
long long d2[100005];
long long dp1[100005];
long long dp2[100005];
void dijkstra(int st, long long d[], long long w[])
{
	multiset<pair<long long, int> >q;
	q.insert({0,st});
	w[st] = 1;
	d[st] = 0;
	while(q.size())
	{
		long long c = q.begin()->first;
		long long at = q.begin()->second;
		
		q.erase(q.begin());
		if(c > d[at])
			continue;
		for(int i = 0; i < graph[at].size(); i++)
		{
			int v = graph[at][i].first;
			long long c = graph[at][i].second;
			if(d[v] > d[at] + c)
			{
				d[v] = d[at] + c;
				w[v] = w[at];	
				q.insert({d[v],v});
			}
			else if(d[v] == d[at] + c)
			{
				w[v] = (w[v] + w[at]) % mod;	
			}
		}
	}
}
int main()
{
	memset(d1,0x3f3f3f3f,sizeof(d1));
	memset(d2,0x3f3f3f3f,sizeof(d2));
	int n,m;
	int s,t;
	scanf("%d %d",&n,&m);
	scanf("%d %d", &s,&t);
	for(int i = 0 ; i < m ; i++)
	{
		int u,v;
		long long c;
		scanf("%d %d %lld",&u,&v,&c);
		graph[u].push_back({v,c});
		graph[v].push_back({u,c});
	}
	dijkstra(s,d1,dp1);
	dijkstra(t,d2,dp2);
	long long mdis = d1[t];
	long long ans1 = (dp1[t] * dp2[s]) % mod;
	long long ans = 0;
	for(int i = 1; i <= n ; i++)
	{
		if(d1[i] == d2[i] && (d1[i] + d2[i] == mdis))
		{
			ans = (ans + ((dp1[i]*dp2[i]%mod) * (dp1[i]*dp2[i] %mod))%mod) %mod;
		}
		for(int j = 0; j < graph[i].size(); j++)
		{
			int v = graph[i][j].first;
			long long c = graph[i][j].second;
			if(2LL*d1[i] < mdis && 2LL*d2[v] < mdis && (d1[i] + d2[v] + c == mdis) )
			{
				ans = (ans + ((dp1[i]*dp2[v]%mod) * (dp1[i]*dp2[v] %mod))%mod) %mod;
			}
		}
	}
	ans = (ans1 - ans + mod) % mod;
	printf("%lld\n",ans);

	return 0;
}

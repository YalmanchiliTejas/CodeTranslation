#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define eb emplace_back
#define ii pair<int, int> 
#define vii vector<pair<int, int> >
#define fi first
#define se second
const int MOD = (int) 1e9+7;
map<int, vi> dist, cnt;
int n, m;
vector<pair<ii, int> > q;
vii G[200005];
void djk(int s, vi& dist, vi& cnt)
{
	dist.assign(n+5, LLONG_MAX/100000LL);
	cnt.assign(n+5, 0);
	priority_queue<ii, vii, greater<ii> > q;
	q.push({0, s}); dist[s]=0, cnt[s]=1;
	while(!q.empty())
	{
		int d=q.top().fi, u=q.top().se; q.pop();
		if(dist[u]!=d) continue;
		for(auto v: G[u])
		{
			if(dist[u]<LLONG_MAX and dist[v.fi]>dist[u]+v.se)
			{
				cnt[v.fi]=cnt[u];
				dist[v.fi]=dist[u]+v.se;
				q.push({dist[v.fi], v.fi});
			}
			else if(dist[v.fi]==dist[u]+v.se)
			{
				cnt[v.fi]=(cnt[v.fi]+cnt[u])%MOD;
			}
		}
	}
}
signed main()
{
	int s, t;
	cin>>n>>m>>s>>t;
	while(m--)
	{
		int u, v, w;
		cin>>u>>v>>w;
//		cout<<u<<" "<<v<<endl;
		G[u].eb(v, w);
		G[v].eb(u, w);
		q.push_back({{u, v}, w});
	}
	djk(s, dist[s], cnt[s]);
	djk(t, dist[t], cnt[t]);
	int ans=cnt[s][t]*cnt[s][t]%MOD;
	for(auto e: q)
	{
		int u=e.fi.fi, v=e.fi.se, d=e.se;
		if(dist[s][u]+dist[t][v]+d==dist[s][t] and 2*dist[s][u]<dist[s][t] and 2*dist[t][v]<dist[s][t])
		{
			int k=cnt[s][u]*cnt[t][v]%MOD;
			ans = (ans-k*k)%MOD;
		}
		if(dist[s][v]+dist[t][u]+d==dist[s][t] and 2*dist[s][v]<dist[s][t] and 2*dist[t][u]<dist[s][t])
		{
			int k=cnt[s][v]*cnt[t][u]%MOD;
			ans=(ans-k*k)%MOD;
		}
	}
	for(int u=1; u<=n; u++)
	{
		if(2*dist[s][u]==dist[s][t] and 2*dist[t][u]==dist[s][t]) 
		{
			int k=cnt[s][u]*cnt[t][u]%MOD;
			ans = (ans-k*k)%MOD;
		}
	}
	while(ans<0) ans+=MOD;
	cout<<ans;
}

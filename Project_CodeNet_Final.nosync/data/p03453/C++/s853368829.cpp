#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<ll,int> pli;
typedef pair<int,int> ii;
typedef pair<int,ll> pil;
typedef vector<pil> vpil;
typedef pair<ii,ll> piil;
vector<vpil> graph;
vector<piil> edge;
int n,m;
int s,t;
vector<ll> ds,dt;
vector<ll> cnts,cntt;
const ll mod = 1e9 + 7;
void dijkstra(int start,vector<ll> &d,vector<ll> &cnt)
{
	cnt.assign(n+1,0ll);
	d.assign(n+1,-1);
	d[start] = 0ll;
	cnt[start] = 1ll;
	priority_queue<pli,vector<pli>,greater<pli> > pq;
	pq.push(pli(0ll,start));
	while(!pq.empty())
	{
		pli p = pq.top();pq.pop();
		ll x = p.first;
		int y = p.second;
		if(x==d[y])
		{
			for(int i=0;i<graph[y].size();++i)
			{
				pil q = graph[y][i];
				if(d[q.first]==-1 || d[q.first] > d[y] + q.second)
				{
					cnt[q.first] = cnt[y];
					d[q.first] = d[y] + q.second;
					pq.push(pli(d[q.first],q.first));
				}
				else if(d[q.first]==d[y]+q.second)
				{
					cnt[q.first] = (cnt[q.first] + cnt[y])%mod;
				}
			}
		}
	}
} 
int main()
{
	int i,x,y;
	ll w;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&s,&t);
	graph.assign(n+1,vpil());
	for(i=0;i<m;++i)
	{
		scanf("%d %d %lld",&x,&y,&w);
		graph[x].push_back(pil(y,w));
		graph[y].push_back(pil(x,w));
		edge.push_back(piil(ii(x,y),w));
	}
	dijkstra(s,ds,cnts);
	dijkstra(t,dt,cntt);
	ll dist = ds[t];
	ll ans = cntt[s] * cntt[s] % mod;
	for(i=0;i<m;++i)
	{
		piil k = edge[i];
		x = k.first.first;
		y = k.first.second;
		w = k.second;
		if(dt[x]*2 < dist && ds[y] *2 < dist && dt[x] + ds[y] + w == dist)
		{
			ans = (ans - cntt[x] * cntt[x] % mod * cnts[y] %mod * cnts[y] % mod + mod) % mod; 
		}
		if(dt[y]*2 < dist && ds[x] *2 < dist && dt[y] + ds[x] + w == dist)
		{
			ans = (ans - cntt[y] * cntt[y] % mod * cnts[x] %mod * cnts[x] % mod + mod) % mod; 
		}
	}
	for(i=1;i<=n;++i)
	{
		if(dt[i]*2==dist && ds[i]*2==dist)
		{
			ans = (ans - cntt[i] * cntt[i] % mod * cnts[i] %mod * cnts[i] % mod + mod) % mod;
		}
	}
	printf("%lld",ans);
}
/*
4 5
1 4
1 2 1
1 3 1
2 3 1
2 4 1
3 4 1
*/
/*
4 4
1 4
1 2 3
1 3 1
2 3 2
2 4 10
*/



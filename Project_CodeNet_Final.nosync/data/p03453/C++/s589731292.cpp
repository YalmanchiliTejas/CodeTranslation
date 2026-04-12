#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#ifndef ASSERT
#	define ASSERT(...)
#endif
#define MOD 1000000007

struct Graph
{
	struct Edge
	{
		Edge()
		{}

		Edge(int from, int to, int weight)
			: u(from)
			, v(to)
			, w(weight)
		{}

		int u, v;
		int w;
	};

	int nvert, nedge;
	vector< vector<Edge> > ve;
	vector<Edge> edges;

	vector<ll> d;
	vector<int> a;

	Graph(int n)
		: nvert(n)
		, nedge(0)
		, ve(n)
		, d(n, 1LL<<60)
		, a(n, 0)
	{}

	void add_edge(int u, int v, int w)
	{
		ASSERT(0 <= u && u < nvert);
		ASSERT(0 <= v && v < nvert);
		ASSERT(0 <= w);
		ASSERT(u != v);
		ve[u].push_back(Edge(u, v, w));
		ve[v].push_back(Edge(v, u, w));
		edges.push_back(Edge(u, v, w));
		edges.push_back(Edge(v, u, w));
		++nedge;
	}

	ll dijkstra(int io, int i1)
	{
		d[io] = 0;
		a[io] = 1;

		priority_queue< pair<ll,int> > q;
		q.push( make_pair(0,io) );

		vector<bool> processed(nvert, false);
		int step = 0;
		while(!q.empty())
		{
			int u = q.top().second;
			if(u == i1)
				break;
			ll du = q.top().first;
			q.pop();
			if(d[u] < du)
				continue;
			
			if(processed[u])
				continue;
			processed[u] = true;
			
			++step;

			for(int i=0; i<ve[u].size(); ++i)
			{
				Edge &e = ve[u][i];
				int v = (u == e.v ? e.u : e.v);
				ASSERT(v != u);

				if(d[u] + e.w  <= d[v])
				{
					if(d[u] + e.w  < d[v])
					{
						a[v] = 0;
					}
					
					a[v] = (a[v] + a[u]) % MOD;
					d[v] = d[u] + e.w;
					q.push( make_pair(-d[v], v) );
				}
			}
		}

		return d[i1];
	}
};


int main()
{
	ios::sync_with_stdio(false);

	int n, m, s, t;
	//cin >> n >> m >> s >> t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	Graph graph(n+1);
	for(int i=0; i<m; ++i)
	{
		int u, v, w;
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);
		graph.add_edge(u, v, w);
	}
	Graph graph2(graph);

	ll len = graph.dijkstra(s, t);
	graph2.dijkstra(t, s);

	vector<ll> q1(n+1, 0);
	vector<ll> q2(n+1, 0);
	
	ll ans = graph.a[t]*1LL*graph.a[t] % MOD;
	for(int i=0; i<graph.edges.size(); i+=1)
	{
		int u = graph.edges[i].u;
		int v = graph.edges[i].v;
		if(graph.d[u] + graph.edges[i].w + graph2.d[v] == len)
		{
			ll t1 = graph.d[u], t2 = graph.d[v];
			if(t1*2 < len && len < t2*2)
			{
				ans = (ans + MOD - graph.a[u]*1LL*graph.a[u]%MOD * graph2.a[v]%MOD *graph2.a[v]%MOD) % MOD;
			}
			else if(t1*2 == len)
			{
				q1[u] = graph.a[u];
			}
			else if(t2*2 == len)
			{
				q2[v] = graph2.a[v];
			}
		}
	}
	
	for(int i=1; i<=n; ++i)
		ans = (ans + MOD - q1[i]*q1[i]%MOD*q2[i]%MOD*q2[i]%MOD) % MOD;

	cout << ans << "\n";

	return 0;
}

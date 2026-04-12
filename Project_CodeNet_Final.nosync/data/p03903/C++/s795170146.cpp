#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

struct DSU
{
	int S;
	
	struct node
	{
		int p; ll sum;
	};
	vector<node> dsu;
	
	DSU(int n)
	{
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	void reset(int n)
	{
		dsu.clear();
		S = n;
		for(int i = 0; i < n; i++)
		{
			node tmp;
			tmp.p = i; tmp.sum = 0;
			dsu.pb(tmp);
		}
	}
	
	int rt(int u)
	{
		if(dsu[u].p == u) return u;
		dsu[u].p = rt(dsu[u].p);
		return dsu[u].p;
	}
	
	void merge(int u, int v)
	{
		u = rt(u); v = rt(v);
		if(u == v) return ;
		if(rand()&1) swap(u, v);
		dsu[v].p = u;
		dsu[u].sum += dsu[v].sum;
	}
	
	bool sameset(int u, int v)
	{
		if(rt(u) == rt(v)) return true;
		return false;
	}
	
	ll getstat(int u)
	{
		return dsu[rt(u)].sum;
	}
};

struct Tree
{
	struct data
	{
		ll w;
	};
	
	struct node
	{
		int p; //parent
		ll w; //modify for different problems
	};
	
	struct edge
	{
		int v; data dat;
	};
	
	vector<vector<edge> > adj;
	int n;
	
	Tree(int _n)
	{
		adj.resize(_n);
		n = _n;
	}
	
	vi level;
	vi depth;
	vi h;
	vi euler;
	vi firstocc;
	vector<vi> rmqtable;
	vi subsize;
	vi start; vi en;
	vector<vector<node> > st;
	
	void addedge(int u, int v, int w)
	{
		edge tmp; tmp.v = v; tmp.dat.w = w;
		adj[u].pb(tmp);
		tmp.v = u;
		adj[v].pb(tmp);
	}
	
	void reset(int _n)
	{
		adj.clear();
		level.clear();
		depth.clear();
		euler.clear();
		rmqtable.clear();
		subsize.clear();
		start.clear();
		en.clear();
		st.clear();
		firstocc.clear();
		adj.resize(_n);
		n = _n;
	}
	
	void dfssub(int u, int p)
	{
		subsize[u] = 1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			dfssub(v, u);
			subsize[u] += subsize[v];
		}
	}
	
	void calcsub()
	{
		subsize.resize(n);
		dfssub(0, -1);
	}
	
	int timer;
	
	void dfsstartend(int u, int p)
	{
		start[u] = ++timer;
		if(p == -1) h[u] = 0;
		else h[u] = h[p] + 1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			dfsstartend(v, u);
		}
		en[u] = ++timer;
	}
	
	void calcstartend()
	{
		timer = 0;
		start.resize(n); en.resize(n); h.resize(n);
		dfsstartend(0, -1);
	}
	
	int eulercnt;
	
	void dfseuler(int u, int p)
	{
		euler[eulercnt] = u; eulercnt++;
		if(p == -1) {depth[u] = 0;}
		else {depth[u] = depth[p] + 1;}
		firstocc[u] = eulercnt-1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue ;
			dfseuler(v, u);
			euler[eulercnt] = u; eulercnt++;
		}
	}
	
	void calceuler()
	{
		eulercnt = 0;
		level.assign(2*n+1, 0);
		euler.assign(2*n+1, 0);
		depth.assign(n, 0);
		firstocc.resize(n);
		dfseuler(0, -1);
	}

	void filllevel()
	{
		int LG = 0;
		while((1<<LG) <= n*2) LG++;
		rmqtable.resize(LG);
		for(int i = 0; i < LG; i++) rmqtable[i].resize(eulercnt);
		for(int i = 0; i < eulercnt; i++)
		{
			level[i] = depth[euler[i]];
		}
		level[eulercnt] = 1000000000;
		for(int j = 0; j < LG; j++)
		{
			for(int i = 0; i < eulercnt; i++)
			{
				rmqtable[j][i] = eulercnt;
				if(i + (1<<j) - 1 < eulercnt)
				{
					if(j == 0)
					{
						rmqtable[j][i] = i;
					}
					else
					{
						if(level[rmqtable[j - 1][i]] < level[rmqtable[j-1][i + (1<<(j-1))]])
						{
							rmqtable[j][i] = rmqtable[j-1][i];
						}
						else
						{
							rmqtable[j][i] = rmqtable[j-1][i + (1<<(j-1))];
						}
					}
				}
			}
		}
	}

	int rmq(int l, int r)
	{
		int k = 31 - __builtin_clz(r-l);
		//cout << l << ' ' << r << ' ' << rmqtable[l][k] << ' ' << rmqtable[r - (1<<k) + 1][k] << endl;
		if(level[rmqtable[k][l]] < level[rmqtable[k][r - (1<<k) + 1]])
		{
			return rmqtable[k][l];
		}
		else
		{
			return rmqtable[k][r - (1<<k) + 1];
		}
	}

	int lcaeuler(int u, int v)
	{
		if(firstocc[u] > firstocc[v]) swap(u, v);
		//cerr << firstocc[u] << ' ' << firstocc[v] << ' ' << rmq(firstocc[u], firstocc[v]) << ' ' << euler[rmq(firstocc[u], firstocc[v])] << endl;
		return euler[rmq(firstocc[u], firstocc[v])];
	}
	
	bool insub(int u, int v) //is u in the subtree of v?
	{
		if(start[v] <= start[u] && en[u] <= en[v]) return true;
		return false;
	}
	
	void dfspar(int u, int p)
	{
		//cerr << u << ' ' << p << '\n';
		st[0][u].p = p;
		if(p == -1) h[u] = 0;
		else h[u] = h[p] + 1;
		if(p==-1) st[0][u].w = 0;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].v;
			if(v == p) continue;
			st[0][v].w = adj[u][i].dat.w;
			//cerr<<"DATA : "<<st[0][v].w<<'\n';
			dfspar(v, u);
		}
	}
	
	int LOG;
	
	void calcpar()
	{
		h.resize(n);
		int LG = 0; LOG = 0;
		while((1<<LG) <= n) {LG++; LOG++;}
		st.resize(LG);
		for(int i = 0; i < LG; i++)
		{
			st[i].resize(n);
		}
		dfspar(0, -1);
		//cerr << "HER" << ' ' << LG << endl;
		for(int i = 1; i < LG; i++)
		{
			for(int j = 0; j < n; j++)
			{
				st[i][j].w = max(st[i-1][j].w,st[i-1][st[i-1][j].p].w);
				if(st[i-1][j].p == -1) st[i][j].p = -1;
				else st[i][j].p = st[i-1][st[i-1][j].p].p;
			}
		}
	}
	
	int getpar(int u, ll k)
	{
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(k&(1<<i))
			{
				u = st[i][u].p;
			}
		}
		return u;
	}
	
	int lca(int u, int v)
	{
		if(h[u] > h[v]) swap(u, v);
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && h[st[i][v].p] >= h[u])
			{
				v = st[i][v].p;
			}
		}
		if(u == v) return u;
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && st[i][v].p != st[i][u].p)
			{
				u = st[i][u].p;
				v = st[i][v].p;
			}
		}
		return st[0][u].p;
	}

	int distance(int u, int v)
	{
		int lc = lca(u, v);
		return (h[u]+h[v]-2*h[lc]);
	}
	
	ll maxpath(int u, int v)
	{
		if(h[u] > h[v]) swap(u, v);
		ll ans = 0;
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && h[st[i][v].p] >= h[u])
			{
				ans = max(st[i][v].w,ans);
				v = st[i][v].p;
			}
		}
		//cerr<<"ANSWER : "<<ans<<'\n';
		if(u == v) return ans;
		for(int i = LOG - 1; i >= 0; i--)
		{
			if(st[i][v].p != -1 && st[i][v].p != st[i][u].p)
			{
				ans = max(st[i][v].w,ans);
				ans = max(st[i][u].w,ans);
				u = st[i][u].p;
				v = st[i][v].p;
			}
		}
		return max(ans,max(st[0][v].w,st[0][u].w));
	}
};

Tree t(100001);

struct Graph
{
	struct edge
	{
		int v; ll weight;
	};
	vector<vector<edge> > adj;
	int n;
	
	Graph(int _n)
	{
		adj.resize(_n);
		n = _n;
	}
	
	void addedge(int u, int v, ll c)
	{
		edge tmp;
		tmp.v = v; tmp.weight = c;
		adj[u].pb(tmp);
		tmp.v = u;
		adj[v].pb(tmp);
	}
	
	void reset()
	{
		adj.clear();
	}
	
	vi dist;
	vi par;
	
	void bfs(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		queue<int> q; q.push(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v;
				if(dist[v] >= INFI)
				{
					dist[v] = dist[u] + 1;
					par[v] = u;
					q.push(v);
				}
			}
		}
	}
	
	void bfs01(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		deque<int> q; q.pb(s);
		while(!q.empty())
		{
			int u = q.front(); q.pop_front();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v; ll w = adj[u][i].weight;
				if(dist[v] >= INFI)
				{
					if(w == 1)
					{
						dist[v] = dist[u] + 1;
						par[v] = u;
						q.push_back(v);
					}
					else
					{
						dist[v] = dist[u];
						par[v] = u;
						q.push_front(v);
					}
				}
			}
		}
	}
	
	void dijkstra(int s)
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0; par[s] = -1;
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, s));
		while(!pq.empty())
		{
			int u = pq.top().se; ll d = pq.top().fi; pq.pop();
			for(int i = 0; i < adj[u].size(); i++)
			{
				int v = adj[u][i].v; ll w = adj[u][i].weight;
				if(d + w < dist[v])
				{
					dist[v] = d + w;
					par[v] = u;
					pq.push(ii(dist[v], v));
				}
			}
		}
	}
	
	vector<vector<ll> > d;
	
	void Floyd()
	{
		ll INFIN = ll(1e18);
		d.resize(n);
		for(int i = 0; i < n; i++)
		{
			d[i].assign(n, INFIN);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < adj[i].size(); j++)
			{
				d[i][adj[i][j].v] = adj[i][j].weight;
			}
			d[i][i] = 0;
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	
	bool BellmanFord(int s) //returns true if negative weight cycle exists
	{
		ll INFI = ll(1e18);
		dist.assign(n, INFI);
		par.assign(n, -1);
		dist[s] = 0;
		for(int step = 1; step <= n; step++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < adj[i].size(); j++)
				{
					int u = i; int v = adj[i][j].v; ll w = adj[i][j].weight;
					if(dist[v] > dist[u] + w)
					{
						if(step == n)
						{
							return true;
						}
						dist[v] = dist[u] + w;
					}
				}
			}
		}
		return false;
	}
	
	ll shortest(int s, int e) //returns the distance by Dijkstra
	{
		return dist[e];
	}
	
	vector<pair<ll, ii> > edges;
	
	ll Kruskal()
	{
		DSU dsu(n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < adj[i].size(); j++)
			{
				int u = i; int v = adj[i][j].v; ll w = adj[i][j].weight;
				edges.pb(mp(w, mp(u, v)));
			}
		}
		sort(edges.begin(), edges.end());
		ll ans = 0; int cnt = 0;
		for(int i = 0; i < edges.size(); i++)
		{
			int u = edges[i].se.fi; int v = edges[i].se.se;
			if(dsu.sameset(u, v)) continue;
			dsu.merge(u, v);
			t.addedge(u,v,edges[i].fi);
			cnt++; ans += edges[i].fi;
			if(cnt >= n - 1) break;
		}
		return ans;
	}
};

vector<pair<ii,int> > edges;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin>>n>>m;
	Graph G(n);
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;
		u--; v--;
		edges.pb(mp(mp(u,v),c));
		G.addedge(u,v,c);
	}
	ll ans = G.Kruskal();
	//cerr<<ans<<'\n';
	t.calcpar();
	int q; cin>>q;
	for(int i = 0; i < q; i++)
	{
		int u, v;
		cin>>u>>v;
		u--; v--;
		cout<<ans-t.maxpath(u,v)<<'\n';
	}
}

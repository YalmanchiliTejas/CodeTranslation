#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e7 + 1;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <string> vs;
typedef vector <char> vc;
typedef list <ll> lst;

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

/*--------------------template--------------------*/



// 素集合データ構造
struct UnionFind
{
	vector<int> par;
	vector<int> sizes;

	UnionFind(int n) : par(n), sizes(n, 1)
	{
		REP(i, n) par[i] = i;
	}

	int find(int x)
	{
		if (x == par[x]) return x;
		return par[x] = find(par[x]);  
	}


	void unite(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (x == y) return;

		if (sizes[x] < sizes[y]) swap(x, y);

		par[y] = x;
		sizes[x] += sizes[y];
	}

	bool same(int x, int y)
	{
		return find(x) == find(y);
	}

	int size(int x)
	{
		return sizes[find(x)];
	}
};

struct Edge
{
	int a, b, cost;

	bool operator<(const Edge& o) const
	{
		return cost < o.cost;
	}
};

struct Graph
{
	int n;  
	vector<Edge> es; 

	int kruskal()
	{
		sort(es.begin(), es.end());

		UnionFind uf(n);
		int min_cost = 0;

		REP(ei, es.size())
		{
			Edge& e = es[ei];
			if (!uf.same(e.a, e.b)) {
				min_cost += e.cost;
				uf.unite(e.a, e.b);
			}
		}

		return min_cost;
	}
};

//Graph input_graph()
//{
//	Graph g;
//	int m;
//	cin >> g.n;
//	m = g.n;
//	vp v;
//	REP(i, g.n)
//	{
//		ll a, b;
//		cin >> a >> b;
//		v.push_back(make_pair(a, b));
//	}
//	sort(ALL(v));
//
//	REP(i, m - 1)
//	{
//		Edge e;
//		e.a = i;
//		e.b = i+1;
//		e.cost = v[i + 1].first - v[i].first;
//		g.es.push_back(e);
//	}
//
//	vp vy;
//	REP(i, m)
//	{
//		vy.push_back(make_pair(v[i].second, i));
//	}
//
//	sort(ALL(vy));
//
//	REP(i, m - 1)
//	{
//		Edge e;
//		e.a = v[i].second;
//		e.b = v[i + 1].second;
//		e.cost = (v[i + 1].first - v[i].first);
//		g.es.push_back(e);
//	}
//	return g;
//}



int main()
{
	//Graph g = input_graph();
	Graph g;
	int m;
	cin >> g.n;
	m = g.n;
	vp v;
	REP(i, g.n)
	{
		ll a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(ALL(v));

	REP(i, m - 1)
	{
		Edge e;
		e.a = i;
		e.b = i + 1;
		e.cost = v[i + 1].first - v[i].first;
		g.es.push_back(e);
	}

	vp vy;
	REP(i, m)
	{
		vy.push_back(make_pair(v[i].second, i));
	}

	sort(ALL(vy));

	REP(i, m - 1)
	{
		Edge e;
		e.a = vy[i].second;
		e.b = vy[i + 1].second;
		e.cost = (vy[i + 1].first - vy[i].first);
		g.es.push_back(e);
	}

	cout << g.kruskal() << endl;
	return 0;
}
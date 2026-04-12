#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (k); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
#define D10 fixed<<setprecision(10)
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }

/*--------------------template--------------------*/

int dx[] = { -1, 0, 0, 1 }; int dy[] = { 0, -1, 1, 0 };
//[int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; int dy[] = { 0, -1, 1, -1, 1, 0, -1, 1 };
bool valid(int x, int y, int h, int w) { return (x >= 0 && y >= 0 && x < h&&y < w); }
int place(int x, int y, int w) { return w*x + y; }


typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}

void dijkstra(Graph &g, int s, Array &d, vi& prev)
{
	d.assign(g.size(), INF);
	prev.assign(g.size(), -1);
	d[s] = 0;
	typedef pair<Weight, int> P;
	priority_queue<P, vector<P>, greater<P>> que;
	que.push(P(0, s));
	while (!que.empty())
	{
		Weight dist = que.top().first;
		int v = que.top().second;
		que.pop();
		if (d[v] < dist) continue;
		REP(i, g[v].size())
		{
			Edge e = g[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				prev[e.to] = v;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

vi build_path(const vi &prev, int t)
{
	vi path;
	for (int i = t; i >= 0; i = prev[i]) path.push_back(i);
	reverse(ALL(path));
	return path;
}

int dp[1111][2];
vi on, off, con;
int now;
vi v;

int solve(int i, int j)
{
	if (dp[i][j] < INF) return dp[i][j];
	int res;
	if (i == v.size() - 1)
	{
		if (j == 0) res = on[now] + off[now];
		else res = off[now];
	}
	else
	{
		if (j == 0) res = min(on[now] + off[now] + solve(i + 1, 0), on[now] + con[now] * (v[i + 1] - v[i]) + solve(i + 1, 1));
		else res = min(off[now] + solve(i + 1, 0), con[now] * (v[i + 1] - v[i]) + solve(i + 1, 1));
	}
	return dp[i][j] = res;
}


int main()
{
	int h, w, m;
	cin >> h >> w >> m;
	vs fld(h);
	on.resize(h*w), off.resize(h*w), con.resize(h*w);
	REP(i, h) cin >> fld[i];
	REP(i, h*w) cin >> con[i];
	REP(i, h*w) cin >> off[i];
	REP(i, h*w) cin >> on[i];
	Graph g(h*w);
	REP(i, h)REP(j, w)
	{
		if (fld[i][j] == '#') continue;
		int tmp = place(i, j, w);
		REP(k, 4)
		{
			int nx = i + dx[k], ny = j + dy[k];
			if (!valid(nx, ny, h, w) || fld[nx][ny]=='#') continue;
			int next = place(nx, ny, w);
			add_edge(g, tmp, next, 1);
		}
	}
	vector<vi> vis(h*w);
	int x, y; cin >> x >> y;
	int tmp = place(x, y, w);
	vis[tmp].push_back(0);
	int time = 1;
	REP(i, m-1)
	{
		int x, y; cin >> x >> y;
		int next = place(x, y, w);
		Array dist; vi prev;
		dijkstra(g, tmp, dist, prev);
		vi path = build_path(prev, next);
		FOR(i, 1, path.size())
		{
			int t = path[i];
			vis[t].push_back(time);
			time++;
		}
		tmp = next;
	}
	int ans = 0;
	REP(i, h*w)
	{
		if (vis[i].size() == 0) continue;
		REP(i, 1111)REP(j, 2) dp[i][j] = INF;
		v = vis[i];
		now = i;
		ans += solve(0, 0);
	}
	cout << ans << endl;
	return 0;
}
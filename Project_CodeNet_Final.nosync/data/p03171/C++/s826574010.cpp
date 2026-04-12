#include "iostream"
#include "fstream"
#include "algorithm"
#include "iomanip"
#include "stack"
#include "queue"
#include "string"
#include "vector"
#include "map"
#include "set"
#include "unordered_set"
#include "unordered_map"
#include "iterator"
#include <ctime>
#include "bitset"
#include "cmath"
#include "list"
#include "complex"
#include <cassert>
#include "deque"
#include "numeric"
#include <cstdio>

using namespace std;

//#define f(i,n) for(int i=0; i<n;i++) 
//#define rf(i, n) for(int i=n-1;i>=0;i--)
//#define forn(i, j, n) for(int i=j; i<n; i++)
//#define ff(i, j, n) f(i, n)f(j, n)
#define pb push_back
//#define mp make_pair
#define maxi(a,b) a = max(a, b);
#define mini(a,b) a = min(a, b);
#define endl '\n'
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;
//typedef long long ll;
typedef long double ld;
#define int long long
#define double ld
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vpii;
typedef vector<char> vc;

template<class T>
void show(const vector<T> &a)
{
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

const int sze = 3e5 + 50, oo = 1e18 + 500, mod = 1e9 + 7;
const double eps = 1e-9, PI = 2 * acos(0.0);
vi vertices[sze];
vc visit(sze, false);
vc used(sze, false);
vi arr(sze, 0);
int n, m, k;
int A, B;
int cnt = 0;

//struct edge
//{
//	int from, to, flow, cap;
//};
//
//vector<edge> e;
//
//void add_edge(int from, int to, int flow, int cap)
//{
//	edge e1 = { from, to, 0, 1 };
//	edge e2 = { to, from, 0, 0 };
//	vertices[from].pb(e.size());
//	e.pb(e1);
//	vertices[to].pb(e.size());
//	e.pb(e2);
//}
//
//int ptr[sze];
//int d[sze];
//int s;
//int t;
//
//bool bfs()
//{
//	queue<int> q;
//	fill(d, d+n+10, -1);
//	d[s] = 0;
//	while (!q.empty())
//	{
//		int v = q.front();
//		q.pop();
//
//		for (auto id : vertices[v])
//		{
//			int to = e[id].to;
//
//			if (d[to] = -1 && e[id].flow < e[id].cap)
//			{
//				d[to] = d[v] + 1;
//				q.push(to);
//			}
//		}
//	}
//
//	return d[t] != -1;
//}
//
//int dfs(int v, int flow)
//{
//	if (!flow || v == t)
//		return flow;
//
//	for (; ptr[v] < vertices[v].size(); ptr[v]++)
//	{
//		int id = vertices[v][ptr[v]];
//		int to = e[id].to;
//
//		if (d[to] != d[v] + 1)
//		{
//			continue;
//		}
//
//		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
//		if (pushed)
//		{
//			e[id].flow += pushed;
//			e[id ^ 1].flow -= pushed;
//			return pushed;
//		}
//	}
//	return 0;
//}
//
//int dinic()
//{
//	int flow = 0;
//	while (bfs())
//	{
//		fill(ptr, ptr + n + 10, 0);
//		while (int pushed = dfs(s, oo))
//		{
//			flow += pushed;
//		}
//	}
//
//	return flow;
//}

int dp[3010][3010];
bool did_dp[3010][3010];

int rec(int l, int r, vi &a)
{
	if (l == r)
	{
		return a[l];
	}

	if (did_dp[l][r])
	{
		return dp[l][r];
	}

	did_dp[l][r] = true;
	dp[l][r] = max(a[l] - rec(l + 1, r, a), a[r] - rec(l, r - 1, a));
	return dp[l][r];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vi a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << rec(0, n - 1, a);
	return 0;
}
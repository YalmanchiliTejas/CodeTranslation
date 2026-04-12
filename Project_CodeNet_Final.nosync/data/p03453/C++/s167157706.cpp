#include<iostream>
#include<cstring>
#include<stdio.h>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int maxm = 200005;
const ll inf = 0x3f3f3f3f3f3f;
const int mod = 1e9 + 7;
struct Edge
{
	int from, to, next;
	ll dist;
	Edge(int _f, int _t, ll _d, int _n) :from(_f), to(_t), next(_n), dist(_d) {}
	Edge() {}
};

struct HeapNode
{
	ll d;
	int u;
	HeapNode(ll _d, int _u) :d(_d), u(_u) {}
	HeapNode() {}
	bool operator<(const HeapNode &b)const
	{
		return d > b.d;
	}
};

struct Dijkstra
{
	int n;
	ll d[maxn];
	bool done[maxn];
	Edge edges[maxm<<1];
	int head[maxn];
	int tot;
	int path[maxn];
	void init(int n)
	{
		tot = 0;
		this->n = n;
		for (int i = 1;i <= n;i++)d[i] = inf;
		memset(done, 0, sizeof(done));
		memset(head, -1, sizeof(head));
	}
	void addedge(int u, int v, ll dist)
	{
		edges[tot] = Edge(u, v, dist, head[u]);
		head[u] = tot++;
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		d[s] = 0;
		path[s] = 1;
		Q.push(HeapNode(d[s], s));
		while (!Q.empty())
		{
			HeapNode x = Q.top();Q.pop();
			int u = x.u;
			if (done[u])continue;
			done[u] = 1;
			for (int i = head[u];~i;i = edges[i].next)
			{
				Edge &e = edges[i];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					path[e.to] = path[u] % mod;
					Q.push(HeapNode(d[e.to], e.to));
				}
				else if (d[e.to] == d[u] + e.dist)
				{
					(path[e.to] += path[u]) %= mod;
				}
			}
		}
	}



}d1, d2;
bool on[maxm];
int u[maxm], v[maxm];
ll d[maxm];

ll sqr(ll a)
{
	return a*a%mod;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int s, t;
	scanf("%d %d", &s, &t);
	d1.init(N);
	d2.init(N);
	for (int i = 1;i <= M;i++)
	{
		scanf("%d %d %lld", &u[i], &v[i], &d[i]);
		d1.addedge(u[i], v[i], d[i]), d1.addedge(v[i], u[i], d[i]);
		d2.addedge(u[i], v[i], d[i]), d2.addedge(v[i], u[i], d[i]);
	}

	d1.dijkstra(s);
	d2.dijkstra(t);
	ll themin = d1.d[t];
	for (int i = 1;i <= M;i++)
	{
		if (d1.d[u[i]] + d[i] + d2.d[v[i]] == themin)
			on[i] = 1;
		else if (d1.d[v[i]] + d[i] + d2.d[u[i]] == themin)
		{
			swap(u[i], v[i]);
			on[i] = 1;
		}
	}
	ll ans = sqr(d1.path[t]);
	for (int i = 1;i <= M;i++)
		if (on[i])
		{
			if (d1.d[u[i]] * 2ll < themin&&d2.d[v[i]] * 2ll < themin)
				ans = (ans - (sqr(d1.path[u[i]]) *sqr(d2.path[v[i]]) % mod)+mod) % mod;
		}
	for (int i = 1;i <= N;i++)
		if (d1.d[i] * 2ll == themin&&d1.d[i]+d2.d[i]==themin)
			ans = (ans - (sqr(d1.path[i]) * sqr(d2.path[i])) % mod+mod) % mod;
	cout << ans << endl;
}
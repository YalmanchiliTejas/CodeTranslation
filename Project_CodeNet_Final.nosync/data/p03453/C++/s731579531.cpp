#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;
const int MOD = 1e9 + 7;

struct Edge
{
	int to, next, c;
}e[MAXM * 2];
int head[MAXN], te = 1;

void addE(int u, int v, int c)
{
	e[++te] = (Edge){v, head[u], c}, head[u] = te;
}

int n, m, S, T, u, v, c;

priority_queue<pair<long long, int> > pq;
long long diss[MAXN], dist[MAXN], ds[MAXN], dt[MAXN];

void DPs()
{
	memset(ds, 0, sizeof(ds));
	memset(diss, -1, sizeof(diss));
	ds[S] = 1, diss[S] = 0;
	pq.push(make_pair(-diss[S], S));
	while (!pq.empty())
	{
		pair<long long, int> now = pq.top();
		pq.pop();
		int p = now.second;
		if (-now.first != diss[p])
			continue;
		for (int j = head[p]; j != 0; j = e[j].next)
		{
			int q = e[j].to;
			if (diss[q] == -1 || diss[q] > diss[p] + e[j].c)
			{
				diss[q] = diss[p] + e[j].c;
				ds[q] = ds[p];
				pq.push(make_pair(-diss[q], q));
			}
			else if (diss[q] == diss[p] + e[j].c)
				ds[q] += ds[p], ds[q] %= MOD;
		}
	}
}

void DPt()
{
	memset(dt, 0, sizeof(dt));
	memset(dist, -1, sizeof(dist));
	dt[T] = 1, dist[T] = 0;
	pq.push(make_pair(-dist[T], T));
	while (!pq.empty())
	{
		pair<long long, int> now = pq.top();
		pq.pop();
		int p = now.second;
		if (-now.first != dist[p])
			continue;
		for (int j = head[p]; j != 0; j = e[j].next)
		{
			int q = e[j].to;
			if (dist[q] == -1 || dist[q] > dist[p] + e[j].c)
			{
				dist[q] = dist[p] + e[j].c;
				dt[q] = dt[p];
				pq.push(make_pair(-dist[q], q));
			}
			else if (dist[q] == dist[p] + e[j].c)
				dt[q] += dt[p], dt[q] %= MOD;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> S >> T;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> c;
		addE(u, v, c);
		addE(v, u, c);
	}
	DPs();
	DPt();
	long long D = diss[T];
	long long res = ds[T] * ds[T] % MOD;
	for (int i = 1; i <= n; i++)
		if (diss[i] == D / 2 && dist[i] == D / 2)
			res = (res - (ds[i] * ds[i] % MOD) * (dt[i] * dt[i] % MOD) % MOD + MOD) % MOD;
	//cout << "res: " << res << endl;
	for (int i = 2; i <= te; i++)
	{
		int x = e[i].to, y = e[i ^ 1].to, c = e[i].c;
		if (2 * diss[x] < D && 2 * dist[y] < D && diss[x] + dist[y] + c == D)
			res = (res - (ds[x] * ds[x] % MOD) * (dt[y] * dt[y] % MOD) % MOD + MOD) % MOD;
	}
	cout << res << endl;
	return 0;
}

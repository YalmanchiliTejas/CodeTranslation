#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)

constexpr int MAX_N = 100000;

using ll = long long;
using P = std::pair<ll, int>;

struct edge
{
	ll from, to, cost;

	edge( ll from, ll to, ll cost )
	:	from(from), to(to), cost(cost)
	{}
};

struct UnionFind
{
	std::vector<int> data;

	UnionFind( int size )
	:	data(size, -1)
	{}

	bool unite(int x, int y)
	{
		x = root(x); y = root(y);

		if (x != y)
		{
			if (data[y] < data[x])
				std::swap(x, y);
			data[x] += data[y];
			data[y] = x;
		}

		return x != y;
	}
	
	bool same( int x, int y )
	{
		return root(x) == root(y);
	}

	int root(int x)
	{
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
};

int N;
ll x[MAX_N], y[MAX_N];
std::vector<P> xs, ys;
std::vector<edge> es;

int main()
{
	scanf("%d", &N);
	rep(i, N)
	{
		scanf("%lld%lld", x + i, y + i);
		xs.push_back(P(x[i], i));
		ys.push_back(P(y[i], i));
	}

	std::sort(xs.begin(), xs.end());
	std::sort(ys.begin(), ys.end());

	rep(i, N - 1)
	{
		es.push_back(edge(xs[i].second, xs[i+1].second, xs[i+1].first-xs[i].first));
		es.push_back(edge(ys[i].second, ys[i + 1].second, ys[i + 1].first - ys[i].first));
	}

	std::sort(es.begin(), es.end(), [](const edge &e1, const edge &e2) { return e1.cost < e2.cost; });

	UnionFind uf(N);

	ll ans = 0;
	for (auto &e : es)
	{
		if (uf.same(e.from, e.to))
			continue;

		uf.unite(e.from, e.to);
		ans += e.cost;
	}

	printf("%lld\n", ans);

	return 0;
}
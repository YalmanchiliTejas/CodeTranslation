#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 5;

struct Point
{
	int value, id;

	Point(int value, int id)
		:value(value), id(id)
	{
	}

	friend bool operator < (const Point &a, const Point &b)
	{
		return a.value < b.value;
	}
};

struct Edge
{
	int u, v, w;

	Edge(int u, int v, int w)
		:u(u), v(v), w(w)
	{
	}

	friend bool operator < (const Edge &a, const Edge &b)
	{
		return a.w < b.w;
	}
};

vector<Point> Xi, Yi;
vector<Edge> edges;
int N, fa[MaxN];

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int x, y;
		cin >> x >> y;
		Xi.emplace_back(Point(x, i));
		Yi.emplace_back(Point(y, i));
	}
	sort(Xi.begin(), Xi.end());
	sort(Yi.begin(), Yi.end());
	for (int i = 0; i < N - 1; i++)
	{
		edges.emplace_back(Edge(Xi[i].id, Xi[i + 1].id, Xi[i + 1].value - Xi[i].value));
		edges.emplace_back(Edge(Yi[i].id, Yi[i + 1].id, Yi[i + 1].value - Yi[i].value));
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= N; i++)
		fa[i] = i;
	int cnt = 0;
	long long ans = 0;
	for (auto e : edges)
	{
		int fx = find(e.u), fy = find(e.v);
		if (fx != fy)
		{
			fa[fy] = fx;
			cnt++;
			ans += e.w;
			if (cnt == N - 1)
				break;
		}
	}
	cout << ans << endl;
	return 0;
}
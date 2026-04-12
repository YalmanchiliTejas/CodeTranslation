#define _CRT_SECURE_NO_WARNINGS
#define TASK "C-large"
#pragma comment(linker, "/STACK:1710886400")
#include <stdio.h>
#include <iostream>
#include <iomanip> 
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <assert.h>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <complex>
using namespace std;

const int MOD = 1000000007;
const int INF = 1000000007;
const long double EPS = 1e-6;
const int HASH_POW = 29;
const long double PI = acos(-1.0);
mt19937_64 rnd(1);

double workTime()
{
	return double(clock()) / CLOCKS_PER_SEC;
}

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << workTime() << endl;
#endif
	exit(code);
}

int n, m;
struct town
{
	int x, y, id;
} p[100010];

struct edge
{
	int u, v, cost;
} q[200010];

int par[100010], sz[100010];

int find_parent(int v)
{
	if (par[v] == v)
		return v;
	return par[v] = find_parent(par[v]);
}

bool unite(int u, int v)
{
	u = find_parent(u);
	v = find_parent(v);
	if (u == v)
		return false;
	if (sz[u] < sz[v])
		swap(u, v);
	sz[u] += sz[v];
	par[v] = u;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);*/
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		p[i].id = i;
		scanf("%d %d", &p[i].x, &p[i].y);
	}

	sort(p + 1, p + n + 1, [](town a, town b) {
		return a.x < b.x || a.x == b.x && a.id < b.id;
	});
	for (int i = 2; i <= n; ++i)
	{
		q[m].u = p[i - 1].id;
		q[m].v = p[i].id;
		q[m].cost = p[i].x - p[i - 1].x;
		++m;
	}
	sort(p + 1, p + n + 1, [](town a, town b) {
		return a.y < b.y || a.y == b.y && a.id < b.id;
	});
	for (int i = 2; i <= n; ++i)
	{
		q[m].u = p[i - 1].id;
		q[m].v = p[i].id;
		q[m].cost = p[i].y - p[i - 1].y;
		++m;
	}

	sort(q, q + m, [](edge a, edge b) {
		return a.cost < b.cost;
	});
	for (int i = 1; i <= n; ++i)
	{
		par[i] = i;
		sz[i] = 1;
	}
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		if (unite(q[i].u, q[i].v))
			ans += q[i].cost;
	}
	printf("%d\n", ans);
	
	my_return(0);
}

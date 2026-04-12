#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<long long int, long long int> P;
typedef pair<P, long long int> Q;

#define INF 1000000000000

long long int parr[100010];
long long int rankk[100010];

void init(long long int n) {
	for (long long int i = 0; i < n; i++) {
		parr[i] = i;
		rankk[i] = 0;
	}
}

long long int find(long long int x) {
	if (parr[x] == x) {
		return x;
	}
	else {
		return parr[x] = find(parr[x]);
	}
}

void unite(long long int x, long long int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rankk[x] < rankk[y]) {
		parr[x] = y;
	}
	else {
		parr[y] = x;
		if (rankk[x] == rankk[y]) rankk[x]++;
	}
}

bool same(long long int x, long long int y)
{
	return find(x) == find(y);
}

long long int cost(P a, P b) {
	return min(abs(a.first-b.first), abs(a.second-b.second));
}

struct edge {
	long long int u, v, cost;
};

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}

edge es[300000];
long long int V, E;

long long int kruskal() {
	sort(es, es + E, comp);
	init(V);
	long long int res = 0;
	for (long long int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {
	long long int n;
	cin >> n;
	long long int x, y;
	vector<Q> dx(n);
	vector<Q> dy(n);
	for (long long int i = 0; i < n; i++) {
		cin >> x >> y;
		dx[i] = Q(P(x, y), i);
		dy[i] = Q(P(y, x), i);
	}
	sort(dx.begin(), dx.end());
	sort(dy.begin(), dy.end());
	V = n;
	E = 0;
	for (long long int i = 1; i < n; i++) {
		edge e;
		e.u = dx[i-1].second;
		e.v = dx[i].second;
		e.cost = cost(dx[i-1].first, dx[i].first);
		es[E] = e;
		E++;
	}
	for (long long int i = 1; i < n; i++) {
		edge e;
		e.u = dy[i - 1].second;
		e.v = dy[i].second;
		e.cost = cost(dy[i - 1].first, dy[i].first);
		es[E] = e;
		E++;
	}
	cout << kruskal() << endl;

	return 0;
}
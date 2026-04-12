#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define FORr(i, j, k) for(int i = j; i >= k; --i)
#define repr(i, j) FOR(i, j, 0)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

struct edge { int u, v, cost; };

bool comp(const edge& e1, const edge& e2) {
		return e1.cost < e2.cost;
}

int N;
vector<P> vx, vy;
vector<edge> es;
int par[100001], rk[100001];
ll res = 0;

void init(int n) {
	rep(i, n) {
		par[i] = i;
		rk[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;

	if(rk[x] < rk[y]) par[x] = y;
	else par[y] = x;
	if(rk[x] == rk[y]) ++rk[x];
}

bool same(int x, int y) {
	return find(x) == find(y);
}

void kruskal() {
	sort(es.begin(), es.end(), comp);
	init(N);
	rep(i, es.size()) {
		edge e = es[i];
		if(!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
}

int main() {
	scanf("%d", &N);
	rep(i, N) {
		int X, Y;
		scanf("%d %d", &X, &Y);
		vx.push_back(P(X, i)); vy.push_back(P(Y, i));
	}
	sort(vx.begin(), vx.end()); sort(vy.begin(), vy.end());
	FOR(i, 1, vx.size()) {
		es.push_back({vx[i - 1].second, vx[i].second, vx[i].first - vx[i - 1].first});
	}
	FOR(i, 1, vy.size()) {
		es.push_back({vy[i - 1].second, vy[i].second, vy[i].first - vy[i - 1].first});
	}
	kruskal();
	printf("%lld\n", res);
	return 0;
}
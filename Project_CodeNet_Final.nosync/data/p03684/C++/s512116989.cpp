#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())
typedef long long ll;

int n;
int par[100005], ran[100005];
struct edge {
	int u, v, cost;
};

bool comp(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
};

void init(int n) {
	FOR(i, n) {
		par[i] = i;
		ran[i] = 0;
	}
}

int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (ran[x] < ran[y]) par[x] = y;
	else {
		par[y] = x;
		if (ran[x] == ran[y]) ran[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main(int argc, char const *argv[]) {
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	vector<pair<int, int> > px(n), py(n);
	FOR(i, n) {
		int x, y;
		cin >> x >> y;
		px[i] = make_pair(x, i);
		py[i] = make_pair(y, i);
	}
	
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());

	vector<edge> es;
	FOR(i, n-1) {
		es.push_back((edge){px[i].second, px[i+1].second, px[i+1].first - px[i].first});
		es.push_back((edge){py[i].second, py[i+1].second, py[i+1].first - py[i].first});
	}

	sort(es.begin(), es.end(), comp);

	init(n);
	int ans = 0;
	FOR(i, es.size()) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			ans += e.cost;
		}
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

const int MOD = (int) 1e9 + 7;

typedef pair<int, int> P;


struct edge {
	int u, v, cost;
};

bool compc(edge &e1, edge &e2) {
	return e1.cost < e2.cost;
}


// UF
int par[100000];
int trank[100000];

int find(int x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	
	if (trank[x] < trank[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (trank[x] == trank[y]) trank[x]++;
	}
}


int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	P xpairi[N], ypairi[N];
	REP(i, N) {
		int x, y;
		cin >> x >> y;
		xpairi[i] = make_pair(x, i);
		ypairi[i] = make_pair(y, i);
		par[i] = i;
		trank[i] = 0;
	}
	
	sort(xpairi, xpairi + N);
	sort(ypairi, ypairi + N);
	
	vector<edge> elist;
	REP(i, N - 1) {
		edge e;
		e.u = xpairi[i].second;
		e.v = xpairi[i + 1].second;
		e.cost = xpairi[i + 1].first - xpairi[i].first;
		elist.push_back(e);
		e.u = ypairi[i].second;
		e.v = ypairi[i + 1].second;
		e.cost = ypairi[i + 1].first - ypairi[i].first;
		elist.push_back(e);
	}
	
	sort(ALL(elist), compc);
	
	ll ans = 0;
	REP(i, elist.size()) {
		edge e = elist[i];
		if (find(e.u) != find(e.v)) {
			ans += e.cost;
			unite(e.u, e.v);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
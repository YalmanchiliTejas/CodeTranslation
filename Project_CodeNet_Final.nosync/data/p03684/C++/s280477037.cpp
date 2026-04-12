#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define MP make_pair
#define F first
#define S second
int par[320000];
int rnk[320000];
int V, E;

struct edge { int u, v, cost; };
typedef pair<int, int>P;
vector<pair<int, pair<int, int>>> xa,ya;
edge es[334334];

bool comp(const edge&e1, const edge& e2) {
	return e1.cost < e2.cost;
}

void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}

int find(int a) {
	if (par[a] == a)return a;
	else return par[a] = find(par[a]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return;

	if (rnk[x] < rnk[y])par[x] = y;
	else {
		par[y] = x;
		if (rnk[x] == rnk[y])rnk[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int kruskal() {
	sort(es, es + E, comp);
	init(V);
	int res = 0;
	for (int i = 0; i < E; i++) {
		edge e = es[i];
		if (!same(e.u, e.v)) {
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		xa.push_back(make_pair(x, make_pair(y, i)));
		ya.push_back(MP(y, MP(x, i)));
	}

	sort(xa.begin(), xa.end());
	sort(ya.begin(), ya.end());
	for (int i = 0; i < xa.size() - 1; i++) {
		es[i] = { xa[i].S.S,xa[i + 1].S.S,abs(xa[i].F - xa[i + 1].F) };
	}
	for (int i = 0; i < ya.size() - 1; i++) {
		int x = xa.size() - 1;
		es[x + i] = { ya[i].S.S,ya[i + 1].S.S,abs(ya[i].F - ya[i + 1].F) };
	}

	/*for (int i = 0; i < n + n-2; i++) {
		cout << es[i].u << ' ' << es[i].v << ' ' << es[i].cost << endl;
	}*/
	V = n + n - 2;
	E = n + n - 2;
	cout << kruskal() << endl;
}
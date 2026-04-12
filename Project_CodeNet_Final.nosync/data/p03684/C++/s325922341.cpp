#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
struct edge {
	int from, to, cost;
	edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}
	bool operator < (const edge &other) const { return cost < other.cost; }
};
vector<edge> es;
int n, father[maxn];
pair<int, int> x[maxn], y[maxn];

int find(int x) {
	if (x == father[x]) {
		return father[x];
	} else {
		return father[x] = find(father[x]);
	}
}

int unite(int x, int y) {
	x = find(x);
	y = find(y);
	father[x] = y;
}

long long kruskal() {
	sort(es.begin(), es.end());
	long long res = 0;
	int _count = 0;
	for (int i = 0; i < es.size(); i++) {
		if (find(es[i].from) != find(es[i].to)) {
			unite(es[i].from, es[i].to);
			res += es[i].cost;
			_count++;
		}
		if (_count == n - 1) break;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i].first >> y[i].first;
		x[i].second = y[i].second = i;
	}
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	sort(x + 1, x + n + 1);
	sort(y + 1, y + n + 1);
	for (int i = 2; i <= n; i++) {
		es.push_back(edge(x[i - 1].second, x[i].second, x[i].first - x[i - 1].first));
		es.push_back(edge(y[i - 1].second, y[i].second, y[i].first - y[i - 1].first));
	}
	cout << kruskal() << endl;
	return 0;
}
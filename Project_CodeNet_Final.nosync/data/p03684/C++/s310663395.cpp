//・グラフに変換する
//・候補を絞る
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

int n;
P px[100000], py[100000];
vector<T> edges;
struct UF {
	int par[100000];
	UF() { for (int i = 0; i < 100000; i++) par[i] = i; }
	int root(int x) { if (par[x] == x) return x; return par[x] = root(par[x]); }
	void marge(int x, int y) { x = root(x); y = root(y); par[x] = y; }
	bool same(int x, int y) { return root(x) == root(y); }
}uf;

int main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		px[i] = P(x, i);
		py[i] = P(y, i);
	}
	sort(px, px + n);
	sort(py, py + n);
	
	for (i = 0; i < n - 1; i++) {
		edges.push_back(T(px[i + 1].first - px[i].first, px[i].second, px[i + 1].second));
		edges.push_back(T(py[i + 1].first - py[i].first, py[i].second, py[i + 1].second));
	}
	
	sort(edges.begin(), edges.end());
	int ans = 0;
	for (i = 0; i < edges.size(); i++) {
		int u = get<1>(edges[i]);
		int v = get<2>(edges[i]);
		if (uf.same(u, v)) continue;
		uf.marge(u, v);
		ans += get<0>(edges[i]);
	}
	cout << ans << endl;
	return 0;
}
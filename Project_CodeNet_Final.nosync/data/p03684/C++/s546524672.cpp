#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge {
	int a, b, cost;
};
bool operator<(const edge& e1, const edge& e2) {
	return e1.cost < e2.cost;
}
int N; vector<int> par;
int root(int x) {
	if (x == par[x]) return x;
	return par[x] = root(par[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	vector<int> x(N), y(N), px(N), py(N); par = vector<int>(N);
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i], px[i] = py[i] = par[i] = i;
	sort(px.begin(), px.end(), [&](int i, int j) { return x[i] < x[j]; });
	sort(py.begin(), py.end(), [&](int i, int j) { return y[i] < y[j]; });
	vector<edge> v;
	for (int i = 1; i < N; i++) {
		v.push_back(edge{ px[i - 1], px[i], x[px[i]] - x[px[i - 1]] });
		v.push_back(edge{ py[i - 1], py[i], y[py[i]] - y[py[i - 1]] });
	}
	sort(v.begin(), v.end());
	int ret = 0;
	for (int i = 0; i < 2 * N - 2; i++) {
		int ax = root(v[i].a), bx = root(v[i].b);
		if (ax != bx) par[ax] = bx, ret += v[i].cost;
	}
	cout << ret << endl;
	return 0;
}
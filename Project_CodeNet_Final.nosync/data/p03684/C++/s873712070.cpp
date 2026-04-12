#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>
#include<climits>
#include<queue>
 
using namespace std;

int find(int i, vector<int>& par) {
	if (par[i] == i) return i;
	return par[i] = find(par[i], par);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> x(n);
	vector<pair<int, int>> y(n);
	for (int i = 0; i < n; i++) {
		int xi, yi;
		cin >> xi >> yi;
		x[i]=make_pair(xi, i);
		y[i]=make_pair(yi, i);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	vector<tuple<int, int, int>> edge;
	for (int i = 1; i < n; i++) {
		edge.push_back(make_tuple(x[i].first - x[i - 1].first, x[i].second, x[i - 1].second));
		edge.push_back(make_tuple(y[i].first - y[i - 1].first, y[i].second, y[i - 1].second));
	}
	sort(edge.begin(), edge.end());
	vector<int> par(n);
	vector<int> rank(n,0);
	iota(par.begin(), par.end(), 0);
	long long ans = 0;
	for (const auto& e : edge) {
		int px = find(get<1>(e), par);
		int py = find(get<2>(e), par);
		if (px == py) continue;
		ans += get<0>(e);
		if (rank[px] < rank[py]) {
			par[px] = py;
		}
		else {
			par[py] = px;
			if (rank[px] == rank[py]) rank[px]++;
		}
	}

	cout << ans << endl;
	return 0;
}
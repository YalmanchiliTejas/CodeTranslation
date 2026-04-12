#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;
	
struct Dsu {
	int n;
	vector<int> p;
	vector<int> rank;

	int get(int v) {
		if (p[v] != v) {
			p[v] = get(p[v]);
		}
		return p[v];
	}

	int merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) {
			return 0;
		}
		if (rank[a] < rank[b]) swap(a, b);
		p[b] = a;
		if (rank[a] == rank[b]) rank[a]++;
		return 1;
	}

	Dsu(int n_) {
		n = n_;
		p.resize(n);
		iota(p.begin(), p.end(), 0);
		rank.resize(n);
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return x[i] < x[j];
	});
	vector<tuple<int, int, int>> ed;
	for (int i = 0; i + 1 < n; i++) {
		ed.push_back(make_tuple(x[ind[i + 1]] - x[ind[i]], ind[i], ind[i + 1]));
	}
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return y[i] < y[j];
	});
	for (int i = 0; i + 1 < n; i++) {
		ed.push_back(make_tuple(y[ind[i + 1]] - y[ind[i]], ind[i], ind[i + 1]));
	}
	int ans = 0;
	Dsu cur(n);
	sort(ed.begin(), ed.end());
	for (auto t : ed) {
		int u, v;
		u = get<1>(t);
		v = get<2>(t);
		if (cur.merge(u, v)) {
			ans += get<0>(t);
		}
	}
	cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using T = tuple<int, int, int>;
using P = pair<int, int>;
using ll = long long;

class UnionFind {
	vector<int> data;
	vector<int> rank;
	int root(int a) {
		return data[a] < 0 ? a : data[a] = root(data[a]);
	}
public:
	UnionFind(int n) : data(n, -1), rank(n, 1) {}
	bool Find(int a, int b) {
		return root(a) == root(b);
	}
	void Union(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) return;
		if (rank[a] < rank[b]) {
			data[a] += data[b];
			data[b] = a;
		}
		else {
			data[b] += data[a];
			data[a] = b;
			if (rank[a] == rank[b]) rank[b]++;
		}
	}
	int Size(int a) {
		return -data[root(a)];
	}
	int Rank(int a) {
		return rank[root(a)];
	}
};

int main()
{
	int N;
	cin >> N;
	vector<int> x(N), y(N);
	vector<T> xy(N), yx(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
		xy[i] = make_tuple(x[i], y[i], i);
		yx[i] = make_tuple(y[i], x[i], i);
	}
	sort(xy.begin(), xy.end());
	sort(yx.begin(), yx.end());
	vector<T> es;
	for (int i = 1; i < N; i++) {
		es.push_back(T(min(abs(x[get<2>(xy[i])] - x[get<2>(xy[i - 1])]), abs(y[get<2>(xy[i])] - y[get<2>(xy[i - 1])])), get<2>(xy[i]), get<2>(xy[i - 1])));
		es.push_back(T(min(abs(x[get<2>(yx[i])] - x[get<2>(yx[i - 1])]), abs(y[get<2>(yx[i])] - y[get<2>(yx[i - 1])])), get<2>(yx[i]), get<2>(yx[i - 1])));
	}
	sort(es.begin(), es.end());
	UnionFind uf(N);
	int res = 0;
	for (auto e : es) {
		if (!uf.Find(get<1>(e), get<2>(e))) {
			res += get<0>(e);
			uf.Union(get<1>(e), get<2>(e));
		}
	}
	cout << res << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

struct UnionFind {

	vi data;

	UnionFind(int n = 0) {
		data.assign(n, -1);
	}

	int find(int k) {
		if (data[k] < 0) return k;
		return data[k] = find(data[k]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int k) { return -data[find(k)]; }

};

int main() {

	int n;
	cin >> n;
	V<T> xy, yx;
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		xy.push_back(T(x, y, i));
		yx.push_back(T(y, x, i));
	}
	sort(all(xy));
	sort(all(yx));

	V<T> dis;

	rep(i, n - 1) {
		int v, vv, d;
		v = get<2>(xy[i]);
		vv = get<2>(xy[i + 1]);
		d = get<0>(xy[i + 1]) - get<0>(xy[i]);
		dis.push_back(tie(d, v, vv));

		v = get<2>(yx[i]);
		vv = get<2>(yx[i + 1]);
		d = get<0>(yx[i + 1]) - get<0>(yx[i]);
		dis.push_back(tie(d, v, vv));
	}

	UnionFind uf(n);

	ll ans = 0;
	sort(all(dis));

	rep(i, dis.size()) {
		int v = get<1>(dis[i]);
		int vv = get<2>(dis[i]);
		if (uf.same(v, vv))continue;
		uf.unite(v, vv);
		ans += get<0>(dis[i]);
	}
	
	cout << ans << endl;

}
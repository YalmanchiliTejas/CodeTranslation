#include <bits/stdc++.h>
using namespace std;


#define int long long 


const int N = 2e5 + 7;


vector <tuple <int, int, int> > edge;


struct DSU{
	vector <int> p, sz;
	DSU(int n) {
		p.resize(n + 1); sz.resize(n + 1, 1);
		for(int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}
	int find(int x) {
		return p[x] = (p[x] == x) ? p[x] : find(p[x]);
	}
	int merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) {
			return 0;
		}
		p[x] = y;
		sz[y] += sz[x];
		return 1;
	}
};

int32_t main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector <tuple <int, int, int> > v, w;
	for(int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;
		v.push_back(make_tuple(x, y, i));
		w.push_back(make_tuple(y, x, i));

	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());

	for(int i = 1; i < n; i++) {
		int x1, y1, z1, x2, y2, z2;
		tie(x1, y1, z1) = v[i - 1];
		tie(x2, y2, z2) = v[i];
		edge.push_back(make_tuple(x2 - x1, z1, z2));
		tie(x1, y1, z1) = w[i - 1];
		tie(x2, y2, z2) = w[i];
		edge.push_back(make_tuple(x2 - x1, z1, z2));
	}
	sort(edge.begin(), edge.end());

	DSU d(n);
	int ans = 0;
	for(auto z: edge) {
		int w, i, j; tie(w, i, j) = z;
		if(d.merge(i, j)) {
			ans += w;
		}
	}
	cout << ans << endl;
}
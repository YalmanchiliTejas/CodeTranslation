#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct p {
	int x, y;
	int indx;
};
const int N = 1e5 + 5;
p points[N];
int n;
int par[N];
int get(int n) {
	if (par[n] == n) return n;
	return par[n] = get(par[n]);
}
vector<int> g[N];
void solve() {
	for (int i = 0; i < N; i++)
		par[i] = i;
	vector<pair<int, pair<int, int> >> edg;
	for (int i = 0; i < n; i++) {
//		g[i].clear();
//		g[i].resize(n);
		for (int j = 0; j < g[i].size(); j++) {
//			g[i][j] = j;
			int v = g[i][j];
			ll c = min(abs(points[i].x - points[v].x),
					abs(points[i].y - points[v].y));
			edg.push_back(make_pair(c, make_pair(i, v)));
		}
	}
	sort(edg.begin(), edg.end());
	ll ans = 0;
	for (int i = 0; i < edg.size(); i++) {
		int u = edg[i].second.first;
		int v = edg[i].second.second;
		int r1 = get(u);
		int r2 = get(v);
		if (r1 == r2) continue;
		//cout << u << "  " << v << endl;
		ans += edg[i].first;
		par[r1] = r2;
	}
	cout << ans << endl;
}
void gen(vector<pair<int, int> > &a, vector<pair<int, int> > &b) {

	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++) {

		auto it = lower_bound(b.begin(), b.end(), make_pair(a[i].first, -1));
		if (it != b.end()) {
			g[a[i].second].push_back(it->second);
			g[it->second].push_back(a[i].second);
		}
		if (it != b.begin()) {
			it--;

			g[a[i].second].push_back(it->second);
			g[it->second].push_back(a[i].second);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, pair<int, int> > > v;
	for (int i = 0; i < n; i++) {
		cin >> points[i].x >> points[i].y;
		points[i].indx = i;
		v.push_back(make_pair(points[i].x, make_pair(points[i].y, i)));
	}
	sort(v.begin(), v.end());
	vector<pair<int, int> > last, cur;
	for (int i = 0; i < n;) {
		int X = v[i].first;
		while (i < n && v[i].first == X) {
			cur.push_back(v[i].second);
			i++;
		}
		if (last.size()) gen(last, cur);
		last = cur;
		cur.clear();
	}
	for (int i = 0; i + 1 < n; i++) {
		int u = v[i].second.second;
		int V = v[i + 1].second.second;
		g[u].push_back(V);
		g[V].push_back(u);
	}
	for (int i = 0; i < n; i++)
		swap(v[i].first, v[i].second.first);
	last.clear();
	sort(v.begin(), v.end());
	for (int i = 0; i < n;) {
		int X = v[i].first;

		while (i < n && v[i].first == X) {
			cur.push_back(v[i].second);
			i++;
		}
		if (last.size()) gen(last, cur);
		last = cur;
		cur.clear();
	}
	for (int i = 0; i + 1 < n; i++) {
		int u = v[i].second.second;
		int V = v[i + 1].second.second;
		g[u].push_back(V);
		g[V].push_back(u);
	}

	solve();
	return 0;
}

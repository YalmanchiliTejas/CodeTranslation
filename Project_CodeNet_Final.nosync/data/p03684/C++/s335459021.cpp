#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > xs;
vector<pair<int, int> > ys;

vector<int> uf;
int getpar(int a) {
	return uf[a] < 0 ? a : (uf[a] = getpar(uf[a]));
}
bool merge(int a, int b) {
	a = getpar(a);
	b = getpar(b);
	if (a == b) return false;
	uf[b] = a;
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	xs.resize(n), ys.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> xs[i].first >> ys[i].first;
		xs[i].second = ys[i].second = i;
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	vector<pair<int, pair<int, int> > > edges;
	edges.reserve(2 * (n-1));
	for (int i = 0; i+1 < n; i++) {
		edges.push_back(make_pair(xs[i+1].first - xs[i].first, make_pair(xs[i].second, xs[i+1].second)));
		edges.push_back(make_pair(ys[i+1].first - ys[i].first, make_pair(ys[i].second, ys[i+1].second)));
	}
	uf.assign(n, -1);
	sort(edges.begin(), edges.end());
	long long tot = 0;
	for (int i = 0; i < int(edges.size()); i++) {
		pair<int, pair<int, int> >& e = edges[i];
		if (merge(e.second.first, e.second.second)) {
			tot += e.first;
		}
	}
	cout << tot << '\n';
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = (1e5)+1;

int n, dsu[MAX];
long long ans;
vector<pair<int,int> > x, y;
priority_queue<pair<int, pair<int,int> > > pq;
int root(int v) { return (dsu[v] < 0 ? v : dsu[v] = root(dsu[v])); }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	fill(dsu, dsu+n, -1);
	for(int i = 0, xx, yy; i < n; i++) {
		cin >> xx >> yy;
		x.emplace_back(xx-1, i);
		y.emplace_back(yy-1, i);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i = 0; i < n-1; i++) {
		pq.emplace(x[i].first-x[i+1].first, make_pair(x[i].second, x[i+1].second));
		pq.emplace(y[i].first-y[i+1].first, make_pair(y[i].second, y[i+1].second));
	}
	while(!pq.empty()) {
		int u, v, w;
		w = pq.top().first;
		tie(u, v) = pq.top().second;
		pq.pop();
		if((u = root(u)) == (v = root(v))) continue;
		if(dsu[u] > dsu[v]) swap(u, v);
		dsu[u] += dsu[v];
		dsu[v] = u;
		ans -= w;
	}
	cout << ans;
}
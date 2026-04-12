#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y, id;
} p[100005];

vector< pair<int, pair<int, int> > > q;

bool cmpx(point a, point b) {
	if (a.x != b.x) return a.x > b.x;
	else return a.y > b.y;
}

bool cmpy(point a, point b) {
	if (a.y != b.y) return a.y > b.y;
	else return a.x > b.x;
}

int up[100005];

int Find(int x) {
	if (up[x] < 0) return x;
	int root = Find(up[x]);
	up[x] = root;
	return root;
}

void Union(int x, int y) {
	if (Find(x) == Find(y)) return;
	if (up[x] < up[y]) {
		up[x] += up[y];
		up[y] = x;
	} else {
		up[y] += up[x];
		up[x] = y;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i].x >> p[i].y;
		p[i].id = i;
	}
	sort(p+1, p+1+n, cmpx);
	for (int i=1; i<n; i++) q.push_back(make_pair(p[i].x - p[i+1].x, make_pair(p[i].id, p[i+1].id)));
	sort(p+1, p+1+n, cmpy);
	for (int i=1; i<n; i++) q.push_back(make_pair(p[i].y - p[i+1].y, make_pair(p[i].id, p[i+1].id)));
	sort(q.begin(), q.end());
	for (int i=0; i<100001; i++) up[i] = -1;
	long long ans = 0;
	for (int i=0; i<q.size(); i++) {
		int u = q[i].second.first, v = q[i].second.second;
		if (Find(u) != Find(v)) {
			Union(Find(u), Find(v));
			ans += q[i].first;
		}
	}
	cout << ans;
}

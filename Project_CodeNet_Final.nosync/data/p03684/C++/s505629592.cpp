#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef long long llong;
typedef pair<int, int> pii;

int find(vector<int> &parent, int cur) {
	if (cur == parent[cur]) return cur;
	else return find(parent, parent[cur]);
}

void solve() {

	srand(time(0));

	int n;
	cin >> n;

	// coordinate, vertex
	vector<pii> x_coord(n), y_coord(n);
	// x, y coordinate combo
	vector<pii> vertexes(n);

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x_coord[i] = mp(x, i);
		y_coord[i] = mp(y, i);
		vertexes[i] = mp(x, y);
	}

	sort(x_coord.begin(), x_coord.end());
	sort(y_coord.begin(), y_coord.end());

	vector< pair<int, pii> > edges;

	// x coordinates
	for (int i = 1; i < n; i++) {
		int u = x_coord[i - 1].ss;
		int v = x_coord[i].ss;
		int weight = x_coord[i].ff - x_coord[i - 1].ff;
		edges.pb(mp(weight, mp(u, v)));
	}

	// y coordinates
	for (int i = 1; i < n; i++) {
		int u = y_coord[i - 1].ss;
		int v = y_coord[i].ss;
		int weight = y_coord[i].ff - y_coord[i - 1].ff;
		edges.pb(mp(weight, mp(u, v)));
	}
	sort(edges.begin(), edges.end());


	// disjoint union set
	vector<int> parent(n), rank(n);
	for (int i = 0; i < n; i++) parent[i] = i;

	int ans = 0;

	for (const auto &edge : edges) {

		int weight = edge.ff;
		int u = edge.ss.ff;
		int v = edge.ss.ss;

		// cout << u << ' ' << v << " : " << weight << endl;

		int up = find(parent, u);
		int vp = find(parent, v);

		// disjoint
		if (up != vp) {

			if (rank[up] > rank[vp]) {
				parent[vp] = up;
			} else if (rank[vp] > rank[up]) {
				parent[up] = vp;
			} else {
				parent[up] = vp;
				rank[vp]++;
			}
			
			ans += weight;
		}
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef LOCAL
		ifstream in("in");
		cin.rdbuf(in.rdbuf());
	#endif

	solve();
}
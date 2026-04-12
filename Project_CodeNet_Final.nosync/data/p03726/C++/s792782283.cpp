// author: Saman Mahdanian
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

struct cmp { bool operator() (const int &, const int &) const; };

int n;
set <int> g[N];
bool mark[N];

set <int, cmp> heap;

int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].insert(b);
		g[b].insert(a);
	}

	for (int i = 0; i < n; i++) 
		heap.insert(i);

	while (!heap.empty()) {
		int v = *heap.begin();
		heap.erase(v);

		if (mark[v])
			continue;
		mark[v] = true;

		// assert(g[v].size() == 1);
		int pv = *g[v].begin();

		heap.erase(pv);
		mark[pv] = true;

		g[pv].erase(v);
		g[v].erase(pv);

		for (int u: g[pv]) {
			assert(heap.find(u) != heap.end());
			heap.erase(u);
			g[u].erase(pv);
			if (g[u].empty()) {
				cout << "First" << endl;
				return 0;
			}
			heap.insert(u);
		}
		g[pv].clear();
		// cerr << v + 1 << ' ' << pv + 1 << endl;
	}

	cout << "Second" << endl;
}


bool cmp::operator() (const int &v, const int &u) const {
	return g[v].size() != g[u].size()? g[v].size() < g[u].size() : v < u;
}


// SamMHD :: Feb17-2019 :: Another Simulation

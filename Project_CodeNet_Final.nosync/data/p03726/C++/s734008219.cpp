#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

vector<vector<int>> adj;
vector<int> pr;
vector<int> num_ch;
vector<int> h;

void DFS(int v, int p) {
	pr[v] = p;
	num_ch[v] = 0;
	if (p == -1) {
		h[v] = 0;
	} else {
		h[v] = h[p] + 1;
	}
	
	for (int i = 0; i < sz(adj[v]); ++i) {
		if (adj[v][i] != p) {
			++num_ch[v];
			DFS(adj[v][i], v);
		}
	}
}

int main () {
    ios_base::sync_with_stdio(0);
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);

	int n;
	cin >> n;

	if (n % 2 == 1) {
		cout << "First" << endl;
		return 0;
	}

	adj.resize(n);
	pr.resize(n);
	num_ch.resize(n);
	h.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		--v1, --v2;
		adj[v1].pb(v2);
		adj[v2].pb(v1);
	}

	DFS(0, -1);

	set<pair<int, int>> vert;
	for (int i = 0; i < n; ++i) {
		vert.insert(mp(h[i], i));
	}

	while (!vert.empty()) {
		auto it = vert.end();
		--it;
		
		int v1 = it->sc;
		vert.erase(it);

		if (pr[v1] == -1 || num_ch[pr[v1]] > 1) {
			cout << "First" << endl;
			return 0;
		}

		int v2 = pr[v1];
		if (pr[v2] != -1) {
			--num_ch[pr[v2]];
		}
		vert.erase(mp(h[v2], v2));
	}

	cout << "Second" << endl;

	return 0;
}

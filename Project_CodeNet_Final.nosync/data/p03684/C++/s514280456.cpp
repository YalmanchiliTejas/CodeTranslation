#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int INF = 2e9;

struct pnt {
	int x, y;
	int id;

	void read(int i) {
		id = i;
		scanf("%d%d", &x, &y);
	}

	bool operator < (const pnt& p) const {
		return x < p.x;
	}
};

int n;
vector<pnt> ps;

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	ps.resize(n);
	forn(i, n) {
		ps[i].read(i);
	}
	return 1;
}

struct DSU {
	vi par;

	DSU(int n = 0) {
		par.assign(n, -1);
	}

	int get(int x) {
		return par[x] < 0 ? x : par[x] = get(par[x]);
 	}

 	bool unite(int x, int y) {
 		x = get(x);
 		y = get(y);
 		if  (x == y) {
 			return 0;
 		}
 		if  (-par[x] < -par[y]) {
 			swap(x, y);
 		}
 		par[x] += par[y];
 		par[y] = x;
 		return 1;
 	}
};

map<int, vii> ys;
vii es;
vector<pnt> by_id;

void build(int x1, int x2) {
	const auto& ys2 = ys[x2];
	for (const auto& cur : ys[x1]) {
		int y, id;
		tie(y, id) = cur;
		int pos = upper_bound(all(ys2), mp(y, INF)) - ys2.begin();
		forn(it, 2) {
			if  (0 <= pos && pos < sz(ys2)) {
				es.pb(mp(id, ys2[pos].snd));
			}
			--pos;
		}
	}
}

int dist(int i, int j) {
	const auto& p1 = by_id[i];
	const auto& p2 = by_id[j];
	return min(abs(p1.x - p2.x), abs(p1.y - p2.y));
}

int solve() {
	es.clear();
	by_id.resize(n);
	for (const auto& p : ps) {
		by_id[p.id] = p;
	}

	forn(it, 2) {
		sort(all(ps));
		ys.clear();
		forn(i, sz(ps)) {
			ys[ps[i].x].pb(mp(ps[i].y, ps[i].id));
		}

		forn(i, sz(ps) - 1) {
			if  (ps[i].x != ps[i + 1].x) {
				build(ps[i].x, ps[i + 1].x);
			}
		}
	
		for (const auto& it : ys) {
			const auto& vect = it.snd;
			forn(i, sz(vect) - 1) {
				es.pb(mp(vect[i].snd, vect[i + 1].snd));
			}
		}

		for (auto& p : ps) {
			swap(p.x, p.y);
		}
	}

	sort(all(es), [&](const pii& e1, const pii& e2) {
		return dist(e1.fst, e1.snd) < dist(e2.fst, e2.snd);
	});

	int ans = 0;
	DSU dsu(sz(ps));
	for (const auto& e : es) {
		if  (dsu.unite(e.fst, e.snd)) {
			const int d = dist(e.fst, e.snd);
			ans += d;
			// printf("d = %d\n", d);
		}
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}

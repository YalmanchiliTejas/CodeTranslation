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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

int n, m;
int s, t;
vector<vii> g;

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return 0;
	}
	scanf("%d%d", &s, &t);
	--s;
	--t;
	g.clear();
	g.resize(n);
	forn(i, m) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		--a;
		--b;
		g[a].pb(mp(b, d));
		g[b].pb(mp(a, d));
	}
	return 1;
}

const ll INF = 1e18;

void calc(int start, vi& cnt, vll& dist) {
	cnt.assign(n, 0);
	dist.assign(n, INF);

	cnt[start] = 1;
	dist[start] = 0;

	set<pair<ll, int>> S;
	S.insert(mp(0, start));

	while (!S.empty()) {
		int v = S.begin()->snd;
		S.erase(S.begin());

		for (const auto& e : g[v]) {
			int to, d;
			tie(to, d) = e;

			if  (dist[to] < dist[v] + d) {
				continue;
			}

			if  (dist[to] == dist[v] + d) {
				add(cnt[to], cnt[v]);
				continue;
			}

			S.erase(mp(dist[to], to));
			dist[to] = dist[v] + d;
			cnt[to] = cnt[v];
			S.insert(mp(dist[to], to));
		}
	}
}

int solve() {
	vll distS;
	vi cntS;
	calc(s, cntS, distS);

	vll distT;
	vi cntT;
	calc(t, cntT, distT);

	int bad = 0;
	
	const ll D = distS[t];
	forn(v, n) {
		if  (distS[v] < INF && distS[v] == distT[v] && distS[v] + distT[v] == D) {
			int coef = mul(cntS[v], cntT[v]);
			int cur = mul(coef, coef);
			// eprintf("v=%d, cur=%d\n", v + 1, cur);
			add(bad, cur);
		}
	}

	forn(v, n) {
		for (const auto& e : g[v]) {
			int to, d;
			tie(to, d) = e;

			const ll d1 = distS[v];
			const ll d2 = distT[to];

			if  (d1 >= INF || d2 >= INF) {
				continue;
			}

			if  (d1 + d2 + d != D) {
				continue;
			}

			// if  (d - d1 + d2 > 0 && d - d1 + d2 < 2 * d) {
			if  (d1 + d > d2 && d2 + d > d1) {
				const int coef = mul(cntS[v], cntT[to]);
				int cur = mul(coef, coef);
				// eprintf("v=%d, to=%d, cur=%d\n", v + 1, to + 1, cur);
				add(bad, cur);
			}
		}
	}

	int ans = mul(cntS[t], cntS[t]);
	add(ans, -bad + MOD);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());

		// break;
	}

#ifdef LOCAL
	eprintf("Time: %.10f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

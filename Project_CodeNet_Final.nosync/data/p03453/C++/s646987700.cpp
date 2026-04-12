#include <bits/stdc++.h>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define MAXN 200002
#define MOD 1000000007

const ll INF = ll(1e18);

inline int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

inline int sub(int a, int b) {
	a -= b;
	if (a < 0) a += MOD;
	return a;
}

inline int mult(int a, int b) {
	return (1LL * a * b) % MOD;
}

inline int power(int a, ll b) {
	int r = 1;
	while(b) {
		if (b & 1) r = mult(r, a);
		a = mult(a, a);
		b >>= 1;
	}
	return r;
}

int n, m, S, T;
vector < pair<int, int> > g[MAXN];
priority_queue < pair<ll, int> > q;
ll d1[MAXN];
ll d2[MAXN];
int f1[MAXN];
int f2[MAXN];

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	scanf("%d%d", &n, &m);
	scanf("%d%d", &S, &T);
	--S, --T;

	for (int i = 0; i < m; ++i) {
		int v1, v2, cost;
		scanf("%d%d%d", &v1, &v2, &cost);
		--v1, --v2;
		g[v1].pb({v2, cost});
		g[v2].pb({v1, cost});
	}

	for (int i = 0; i < n; ++i)
		d1[i] = INF;
	d1[S] = 0;
	f1[S] = 1;
	q.push({0, S});
	while(!q.empty()) {
		ll dist = -q.top().f;
		int v = q.top().s;
		q.pop();
		if (d1[v] != dist) continue;
		for (const auto& t : g[v]) {
			int v2 = t.f;
			int cost = t.s;
			if (d1[v2] > d1[v] + cost) {
				d1[v2] = d1[v] + cost;
            f1[v2] = 0;
				q.push({-d1[v2], v2});
			}
			if (d1[v2] == d1[v] + cost) {
            f1[v2] = add(f1[v], f1[v2]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
		d2[i] = INF;
	d2[T] = 0;
	f2[T] = 1;
	q.push({0, T});
	while(!q.empty()) {
		ll dist = -q.top().f;
		int v = q.top().s;
		q.pop();
		if (d2[v] != dist) continue;
		for (const auto& t : g[v]) {
			int v2 = t.f;
			int cost = t.s;
			if (d2[v2] > d2[v] + cost) {
				d2[v2] = d2[v] + cost;
            f2[v2] = 0;
				q.push({-d2[v2], v2});
			}
			if (d2[v2] == d2[v] + cost) {
            f2[v2] = add(f2[v2], f2[v]);
			}
		}
	}

	int ans = mult(f1[T], f2[S]);
	ll D = d1[T];
	for (int i = 0; i < n; ++i) {
		if (D == d1[i] + d2[i] && d1[i] == d2[i]) {
			ans = sub(ans, mult(mult(f1[i], f1[i]), mult(f2[i], f2[i])));
		}
		for (const auto& t : g[i]) {
			int v2 = t.f;
			int cost = t.s;
			if (D == d1[i] + d2[v2] + cost && (d1[i] + cost) * 2 > D && (d2[v2] + cost) * 2 > D) {
				ans = sub(ans, mult(mult(f1[i], f1[i]), mult(f2[v2], f2[v2])));
			}
		}
	}
	printf("%d\n", ans);
	      
	return 0;
}

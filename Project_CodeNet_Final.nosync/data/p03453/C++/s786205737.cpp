#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-------
const int N = 101010, MOD = 1e9 + 7;
typedef pair<pii, int> iii;
int n, m, S, T;
iii edge[N + N];
vector<pii> G[N];
ll dT[N], dS[N];
int toS[N], toT[N];
bool vis[N];
int add(int a, int b) {
	a += b;
	if(a >= MOD) a -= MOD;
	return a;
}
int sub(int a, int b) {
	a -= b;
	if(a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % MOD;
}
void dij(int st, ll dis[], int tot[]) {
	priority_queue<pair<ll, int> > q;
	rep(i, 0, n) dis[i] = 1e18;
	rep(i, 0, n) vis[i] = 0;
	rep(i, 0, n) tot[i] = 0;
	tot[st] = 1;
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty()) {
		int u = q.top().se; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(const auto & to : G[u]) {
			int v, w; tie(v, w) = to;
			if(vis[v]) continue;
			ll d = dis[u] + w;
			if(d < dis[v]) {
				q.push({-d, v});
				dis[v] = d;
				tot[v] = tot[u];
			} else if(d == dis[v]) {
				tot[v] = add(tot[u], tot[v]);
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &m, &S, &T);
	S--, T--;
	rep(i, 0, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		edge[i] = {{u, v}, w};
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	dij(S, dT, toT);
	dij(T, dS, toS);
	assert(toT[T] == toS[S]);
	assert(dS[S] == dT[T]);
//	rep(i, 0, n) de(dS[i]);
	vector<iii> e;
	rep(i, 0, m) {
		int u, v, w; u = edge[i].fi.fi, v = edge[i].fi.se, w = edge[i].se;
		if(dS[v] + w == dT[T] - dT[u] || dS[u] + w == dT[T] - dT[v]) e.pb(edge[i]);
	}
	int ans = 0;
	ans = mul(toT[T], toS[S]);
//	de(ans);
	rep(i, 0, n) if(dT[i] + dS[i] == dT[T] && dT[i] == dS[i]) ans = sub(ans, mul(mul(toT[i], toS[i]), mul(toT[i], toS[i])));
	rep(i, 0, sz(e)) {
		int u, v, w; u = e[i].fi.fi, v = e[i].fi.se, w = e[i].se;
//		dd(u), dd(v), de(w);
		if(dT[u] + w == dT[v] && dT[u] * 2 < dT[T] && dS[v] * 2 < dT[T] && dT[u] + dS[v] + w == dT[T]) ans = sub(ans, mul(mul(toT[u], toS[v]), mul(toT[u], toS[v])));
		swap(u, v);
		if(dT[u] + w == dT[v] && dT[u] * 2 < dT[T] && dS[v] * 2 < dT[T] && dT[u] + dS[v] + w == dT[T]) ans = sub(ans, mul(mul(toT[u], toS[v]), mul(toT[u], toS[v])));
	//	if(dT[u] + w == dT[v] && abs(dT[u] - dS[v]) < w) ans = sub(ans, mul(toT[u], toS[v]));
//		dd(dT[u]), de(dS[v]);
	//	if(dT[v] + w == dT[u] && abs(dT[v] - dS[u]) < w) ans = sub(ans, mul(toT[v], toS[u]));
//		dd(dT[v]), de(dS[u]);
//		de(ans);
	}
	printf("%d\n", ans);
	return 0;
}


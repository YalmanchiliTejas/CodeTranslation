#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

const int N = 111111;
const long long oo = 1e17;
const int md = 1e9 + 7;

int n, m, s, t;
long long fs[N], ft[N];
int gs[N], gt[N];
vector<pair<int, int> > e[N];

void dijk(int s, long long f[], int g[]){
	set<pair<long long, int> > S;
	S.insert(mp(0, s));
	for(int i = 1; i <= n; ++i) f[i] = oo;
	f[s] = 0;
	g[s] = 1;
	while (!S.empty()){
		pair<long long, int> cur = *S.begin();
		S.erase(S.begin());
		int u = cur.second;
		for(auto p : e[u]){
			int v = p.first, c = p.second;
			if (f[v] > f[u] + c){
				g[v] = g[u];
				S.erase(mp(f[v], v));
				f[v] = f[u] + c;
				S.insert(mp(f[v], v));
			}
			else if (f[v] == f[u] + c){
				g[v] += g[u];
				g[v] %= md;
			}
		}
	}
}

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 1; i <= m; ++i){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		e[u].pb(mp(v, c));
		e[v].pb(mp(u, c));
	}
	dijk(s, fs, gs);
	dijk(t, ft, gt);
	long long ans = 1ll * gs[t] * gs[t] % md;
	for(int i = 1; i <= n; ++i){
		if (fs[i] == ft[i] && fs[i] + ft[i] == fs[t]){
			ans -= 1ll * gs[i] * gs[i] % md * gt[i] % md * gt[i] % md;
			ans += md;
			ans %= md;
		}
	}
	for(int u = 1; u <= n; ++u){
		for(auto p : e[u]){
			int v = p.first, c = p.second;
			if (max(fs[u], ft[v]) * 2 < fs[t] && fs[u] + c + ft[v] == fs[t]){
				ans -= 1ll * gs[u] * gs[u] % md * gt[v] % md * gt[v] % md;
				ans += md;
				ans %= md;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
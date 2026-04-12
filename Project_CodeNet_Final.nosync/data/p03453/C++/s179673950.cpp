#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
const int MOD = 1e9 + 7;
int paths[2][MAX];
ll dis[2][MAX];
vector<ii> adj[MAX];
int s, t;
int n, m;

inline int add(int a, int b) {
	a += b;
	if(a >= MOD) {
		a -= MOD;
	}
	return a;
}

inline int mult(int a, int b) {
	return (1LL * a * b) % MOD;
}

inline int sub(int a, int b) {
	a -= b;
	if(0 > a) {
		a += MOD;
	}
	return a;
}

void bfs(int source, int P[MAX], ll D[MAX]) {
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;

	D[source] = 0;
	P[source] = 1;

	pq.emplace(D[source], source);

	while(!pq.empty()) {
		pair<ll, int> top = pq.top(); pq.pop();

		ll w;
		int cur;
		tie(w, cur) = top;

		if(w > D[cur]) {
			continue;
		}

		for(auto &each : adj[cur]) {
			int other, weight;
			tie(other, weight) = each;

			if(D[other] > D[cur] + weight) {
				D[other] = D[cur] + weight;
				P[other] = P[cur];
				pq.emplace(D[other], other);
			}
			else if(D[other] == D[cur] + weight) {
				P[other] = add(P[other], P[cur]);
			}
		}
	}
}

pair<ll, ll> intersection(ll sa, ll ea, ll sb, ll eb) {
	return make_pair(max(sa, sb), min(ea, eb));
}

int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);

	fori(i, 1, m + 1) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	memset(dis, 0x7F, sizeof dis);
	bfs(s, paths[0], dis[0]);
	bfs(t, paths[1], dis[1]);

	ll best = dis[0][t];
	int paj = paths[0][t];

	int ans = mult(paj, paj);

	fori(i, 1, n + 1) {
		if(dis[0][i] == dis[1][i] && 2 * dis[0][i] == best) {
			int p = mult(paths[0][i], paths[1][i]);
			int bad = mult(p, p);
			ans = sub(ans, bad);
		}
	}

	fori(i, 1, n + 1) {
		for(auto &each : adj[i]) {
			int j, w;
			tie(j, w) = each;

			if(i > j) {
				continue;
			}

			if((dis[0][i] + dis[1][j] + w) == best) {
				ll S_start = dis[0][i];
				ll S_end = dis[0][i] + w;

				ll T_start = dis[1][j];
				ll T_end = dis[1][j] + w;

				pair<ll, ll> inter = intersection(S_start, S_end, T_start, T_end);
				if(inter.first < inter.second) {
					int p = mult(paths[0][i], paths[1][j]);
					int bad = mult(p, p);
					ans = sub(ans, bad);
				}
			}
			else if((dis[1][i] + dis[0][j] + w) == best) {
				ll S_start = dis[1][i];
				ll S_end = dis[1][i] + w;

				ll T_start = dis[0][j];
				ll T_end = dis[0][j] + w;

				pair<ll, ll> inter = intersection(S_start, S_end, T_start, T_end);
				if(inter.first < inter.second) {
					int p = mult(paths[1][i], paths[0][j]);
					int bad = mult(p, p);
					ans = sub(ans, bad);
				}
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

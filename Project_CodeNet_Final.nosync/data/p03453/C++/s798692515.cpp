#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

#define F first
#define S second

const int MN = 101234, INF = 1ll << 60, MOD = 1000000007;

int n, m, a, b, ans;
int cntA[MN], cntB[MN], disA[MN], disB[MN], MDis;

pii dis[MN];

vector <pii> adj[MN];

void Input();
void GetDist();
void Count();
void Dij(int);

int32_t main() {
	Input();
	GetDist();
   	Count();
}
void Input() {
	cin >> n >> m;
	cin >> a >> b;
	a--, b--;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[--u].push_back({--v, w});
		adj[v].push_back({u, w});
	}
}
void GetDist() {
	Dij(a);
	MDis = dis[b].F;
	for (int i = 0; i < n; i++) {
		disA[i] = dis[i].F;
		cntA[i] = dis[i].S;
	}
	Dij(b);
	for (int i = 0; i < n; i++) {
		disB[i] = dis[i].F;
		cntB[i] = dis[i].S;
	}
}
void Count() {
	ans = cntA[b] * cntA[b] % MOD;
	for (int i = 0; i < n; i++)
		if (disA[i] * 2 == MDis)
			ans = (ans - (cntA[i] * cntB[i] % MOD * cntA[i] % MOD * cntB[i] % MOD) + MOD) % MOD;
	for (int v = 0; v < n; v++) 
		for (auto p: adj[v]) {
			int u = p.F, w = p.S;
			if (disA[v] + w + disB[u] == MDis && disA[v] * 2 < MDis && disB[u] * 2 < MDis)
				ans = (ans - (cntA[v] * cntB[u] % MOD * cntA[v] % MOD * cntB[u] % MOD) + MOD) % MOD;
		}
	cout << ans;
}
void Dij(int v) {
	for (int i = 0; i < n; i++)
		dis[i] = {INF, 0};
	dis[v] = {0, 1};
	set <pii> st = {pii(dis[v].F, v)};
	while (st.size()) {
		int v = st.begin()->S;
		st.erase(st.begin());
		for (auto p: adj[v]) {
			int u = p.F, w = p.S;
			if (dis[v].F + w < dis[u].F) {
				st.erase({dis[u].F, u});
				dis[u] = pii(dis[v].F + w, dis[v].S);
				st.insert({dis[u].F, u});
			} else if (dis[v].F + w == dis[u].F)
				(dis[u].S += dis[v].S) %= MOD;
		}
	}
}



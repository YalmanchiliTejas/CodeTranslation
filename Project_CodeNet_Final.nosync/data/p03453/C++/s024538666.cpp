#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 10, MOD = 1e9 + 7;

int N, M, S, T;
vector<pi> Ed[MAX_N];
ll Dis[2][MAX_N]; int Cnt[2][MAX_N], Vis[2][MAX_N];

typedef pair<ll, int> pli;
void getDis(int s, int t, int k) {
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	for(int i=1; i<=N; i++) Dis[k][i] = LINF;
	Cnt[k][s] = 1;
	Q.emplace(Dis[k][s] = 0, s);
	while(!Q.empty()) {
		ll d; int v; tie(d, v) = Q.top(); Q.pop();
		if(Vis[k][v]) continue; Vis[k][v] = true;
		for(pi &val : Ed[v]) {
			int w, d; tie(w, d) = val;
			if(Dis[k][w] + d == Dis[k][v]) Cnt[k][v] += Cnt[k][w], Cnt[k][v] %= MOD;
		}
		for(pi &val : Ed[v]) {
			int w, d; tie(w, d) = val;
			if(!Vis[k][w] && Dis[k][w] > Dis[k][v] + d) Q.emplace(Dis[k][w] = Dis[k][v] + d, w);
		}
	}
}
int main() {
	cin >> N >> M >> S >> T;
	for(int i=0; i<M; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		Ed[x].emplace_back(y, c);
		Ed[y].emplace_back(x, c);
	}
	getDis(S, T, 0);
	getDis(T, S, 1);

	ll ans = 1ll * Cnt[0][T] * Cnt[0][T] % MOD;
	ll D = Dis[0][T];
	for(int v=1; v<=N; v++) {
		for(auto &val : Ed[v]) {
			int w, d; tie(w, d) = val;
			if(Dis[0][v]*2 < D && Dis[1][w]*2 < D && Dis[0][v] + Dis[1][w] + d == D)
				ans -= 1ll * Cnt[0][v] * Cnt[0][v] % MOD * Cnt[1][w] % MOD * Cnt[1][w] % MOD;
		}
		if(Dis[0][v] * 2 == D) 
			ans -= 1ll * Cnt[0][v] * Cnt[0][v] % MOD * Cnt[1][v] % MOD * Cnt[1][v] % MOD;
		ans %= MOD;
	}
	ans = (ans + MOD) % MOD;
	printf("%lld\n", ans);
	return 0;
}

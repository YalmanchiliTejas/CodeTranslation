//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, m, s, t, dis[2][N], dp[2][N], ind[N];
vector<pii> G[N];
vector<int> g[N];

void DJ(int v, int id){
	memset(dis[id], 31, sizeof dis[id]);
	dis[id][v] = 0;
	set<pii> st;
	st.insert({0, v});
	while (st.size()){
		pii fr = *st.begin();
		st.erase(st.begin());
		for (auto u:G[fr.S]){
			if (dis[id][u.F] > fr.F + u.S){
				st.erase({dis[id][u.F], u.F});
				dis[id][u.F] = fr.F + u.S;
				st.insert({dis[id][u.F],  u.F});
			}
		}
	}
}

bool cmp(int x, int y){
	return dis[0][x] < dis[0][y];
}

bool cmp2(int x, int y){
	return dis[1][x] < dis[1][y];
}

void calc(int id){
	for (int i = 1; i <= n; i++){
		g[i].clear();
	}
	for (int i = 1; i <= n; i++){
		for (auto u:G[i]){
			if (dis[id][u.F] == dis[id][i] + u.S) {g[i].pb(u.F);}
		}
	}
	for (int i = 1; i <= n; i++) ind[i] = i;
	if (id == 0){
		sort(ind + 1, ind + n + 1, cmp);
	}else{
		sort(ind + 1, ind + n + 1, cmp2);
	}
	//cout << ind[1] << '\n';
	dp[id][ind[1]] = 1;
	for (int i = 1; i <= n - 1; i++){
		for (auto u:g[ind[i]]){
			//cout << ind[i] << ' ' << u << '\n';
			dp[id][u] += dp[id][ind[i]];
			dp[id][u] %= MOD;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		G[v].pb({u, w});
		G[u].pb({v, w});
	}
	DJ(s, 0);
	DJ(t, 1);
	calc(0);
	calc(1);
	int sm  = dis[0][t];
	//cout << dp[0][t] << ' ' << dp[1][s] << '\n';
	ll ans = dp[0][t] * dp[0][t] % MOD;
	//cout << ans << '\n';
	for (int i = 1; i <= n; i++){
		if (dis[0][i] * 2 == sm && dis[1][i] * 2 == sm){
			//cout << "YES" << 
			ans -= (dp[0][i] * dp[0][i] % MOD) * 1ll * (dp[1][i] * dp[1][i] % MOD) % MOD;
			ans %= MOD;
			ans += MOD;
			ans %= MOD;
		}
		for (auto u:G[i]){
			if (dis[0][i] * 2 < sm && (dis[0][i] + u.S) * 2 > sm){
				//cout << "YES" << i << ' ' << u.F << '\n';
				if (dis[0][i] + dis[1][u.F] + u.S == sm){
					ans -= (dp[0][i] * dp[0][i] % MOD) * 1ll * (dp[1][u.F] * dp[1][u.F] % MOD) % MOD;
					ans %= MOD;
					ans += MOD;
					ans %= MOD;
				}
			}
		}
	}
	cout << ans;




	return 0;
}

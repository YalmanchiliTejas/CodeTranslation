#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long inf = 1ll << 61;
const long long mod = 1000000007;
struct edge {int to, cost;};
typedef pair<int, int> P;
vector<edge>G[100006];
int u[200006], v[200006], d[200006];
int d1[100006], d2[100006], dp1[100006], dp2[100006];
void dijk(int s,int V,int *d,int *dp) {
	fill(d, d + V, inf);
	d[s] = 0;
	priority_queue<P, vector<P>, greater<P>>Q;
	Q.push(P(0, s));
	dp[s] = 1;
	while (Q.size()) {
		P p = Q.top();
		Q.pop();
		int v = p.second;
		if (d[v] < p.first)continue;
		rep(i, G[v].size()) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				dp[e.to] = dp[v];
				dp[e.to] %= mod;
				Q.push(P(d[e.to], e.to));
			}
			else if(d[e.to]==d[v]+e.cost){
				dp[e.to] += dp[v];
				dp[e.to] %= mod;
			}
		}
	}
}

signed main() {
	int n, m, s, t; cin >> n >> m >> s >> t;
	s--; t--;
	rep(i, m) {
		cin >> u[i] >> v[i] >> d[i];
		u[i]--; v[i]--;
		G[u[i]].push_back({ v[i],d[i] });
		G[v[i]].push_back({ u[i],d[i] });
	}
	dijk(s, n, d1, dp1);
	dijk(t, n, d2, dp2);
	int ans = dp1[t] * dp2[s] % mod;
	int mind = d1[t];
	rep(i, n) {
		if (d1[i] + d2[i] == mind&&d1[i] == d2[i]) {
			ans -= dp1[i] * dp2[i] % mod*dp1[i]%mod*dp2[i]%mod;
			ans = (ans + mod) % mod;
		}
	}
	rep(i, m) {
		if (d1[u[i]] > d1[v[i]])swap(u[i], v[i]);
		if (d1[u[i]] + d[i] + d2[v[i]] == mind) {
			if (d1[u[i]] -d[i]< d2[v[i]] && d2[v[i]] < d1[v[i]]) {
				ans -= dp1[u[i]] * dp2[v[i]] % mod*dp1[u[i]] % mod*dp2[v[i]] % mod;
				ans = (ans + mod) % mod;
			}
		}
	}
	cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N = 100005, inf = 1e18, mod = 1e9+7;

ll n, m, s, t, d[2][N], c[2][N];
vector<pll> adj[N];
priority_queue<pll> pq;

void calc (ll I, ll S) {
	for(ll i=1;i<=n;i++) d[I][i] = inf;
	d[I][S] = 0; c[I][S] = 1;
	pq.push({0, S});
	while(!pq.empty()) {
		ll A, B; tie(A, B) = pq.top(); A *= -1; pq.pop();
		if(d[I][B] != A) continue;
		for(auto &T : adj[B]) {
			ll X, Y; tie(X, Y) = T;
			if(d[I][X] > A + Y) {
				d[I][X] = A + Y;
				c[I][X] = 0;
				pq.push({-A-Y,X});
			}
			if(d[I][X] == A + Y) {
				c[I][X] += c[I][B];
				c[I][X] %= mod;
			}
		}
	}
}

int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	for(ll i=1;i<=m;i++) {
		ll A, B, C;
		scanf("%lld%lld%lld",&A,&B,&C);
		adj[A].push_back({B, C});
		adj[B].push_back({A, C});
	}
	calc(0, s); calc(1, t);
	ll ans = c[0][t] * c[0][t] % mod;
	for(ll i=1;i<=n;i++) {
		if(d[0][i] + d[1][i] != d[0][t]) continue;
		if(d[0][i] == d[1][i]) ans = (ans + mod - c[0][i] * c[1][i] % mod * c[0][i] % mod * c[1][i] % mod) % mod;
		for(auto &T : adj[i]) {
			ll A, B; tie(A, B) = T;
			if(d[0][i] + B != d[0][A] || d[1][A] + B != d[1][i] || d[0][A] <= d[1][A] || d[1][i] <= d[0][i]) continue;
			ans = (ans + mod - c[0][i] * c[1][A] % mod * c[0][i] % mod * c[1][A] % mod) % mod;
		}
	}
	printf("%lld\n",ans);
}

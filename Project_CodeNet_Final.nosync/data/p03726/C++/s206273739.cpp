#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 2e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

vector<ll> G[N];
ll par[N], cnt[N], h[N];
void A() {
	cout << "First";
	exit(0);
}
void B() {
	cout << "Second";
	exit(0);
}
void DFS(ll v, ll p = 0) {
	for (auto u : G[v]) {
		if (u ^ p) {
			h[u] = h[v] + 1;
			par[u] = v;
			cnt[v] ++;
			DFS(u, v);
		}
	}
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i ++) {
    	ll v, u;
    	cin >> v >> u;
    	G[v].pb(u);
    	G[u].pb(v);
	}
	DFS(1);
	set<pll> s;
	for (int i = 1; i <= n; i ++) {
		s.insert({h[i], i});
	}
	if (n & 1) {
		A();
	}
	while (s.size()) {
		auto x = *s.rbegin();
		ll v = x.S;
		ll pp = par[v];
		if (cnt[pp] > 1) A();
		cnt[par[pp]] --;
		s.erase({h[v], v});
		s.erase({h[pp], pp});
		
	}
	B();
    return (0);
}
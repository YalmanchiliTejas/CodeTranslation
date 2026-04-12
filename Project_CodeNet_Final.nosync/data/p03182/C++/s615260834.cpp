#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define sol (k+k)
#define sag (k+k+1)
#define orta ((bas+son)/2)
#define inf 100000000000000007
#define N 1000005
using namespace std;
typedef long long ll;
typedef pair < ll , ll > ii;

ll n, m, top, x[N], y[N], z[N], dp[N], seg[4*N], laz[4*N];
vector < ii > g[N];

void put(ll k, ll z){
	seg[k] += z;
	laz[k] += z;
}

void push(ll k){
	put(sol, laz[k]);
	put(sag, laz[k]);
	laz[k] = 0;
}

ll qu(ll k, ll bas, ll son, ll x, ll y){
	if(bas > y or son < x)
		return inf;
	if(bas >= x and son <= y)
		return seg[k];
	push(k);
	return min(qu(sol, bas, orta, x, y), qu(sag, orta + 1, son, x, y));
}

void up(ll k, ll bas, ll son, ll x, ll y, ll z){
	if(bas > y or son < x)
		return;
	if(bas >= x and son <= y){
		put(k, z);
		return;
	}
	push(k);
	up(sol, bas, orta, x, y, z);
	up(sag, orta + 1, son, x, y, z);
	seg[k] = min(seg[sol], seg[sag]);
}

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld %lld",&n ,&m);
	for(ll i = 1; i <= m; i++){
		scanf("%lld %lld %lld",x + i, y + i, z + i);
		top += z[i];
		g[x[i]].pb(mp(y[i], z[i]));
	}
	for(ll i = n; i >= 0; i--){
		dp[i] = qu(1, 1, n + 1, i + 1, n + 1);
		up(1, 1, n + 1, i, i, dp[i]);
		for(ll j = 0; j < g[i].size(); j++)
			up(1, 1, n + 1, g[i][j].st + 1, n + 1, g[i][j].nd);
	}
	printf("%lld\n", top - dp[0]);
	return 0;
}
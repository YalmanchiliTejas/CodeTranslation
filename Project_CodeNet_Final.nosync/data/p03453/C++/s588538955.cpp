#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime> 
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#include <iomanip>
#define y1 y11
#define sc second
#define fr first
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define skip continue
#define all(x) x.begin(), x.end()
#define NAME "code"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> piii;

const ld pi = 2 * acos(0.0);
const ll prime = 31;
const ll inf = 1e18;
const ll mod = 1e9 + 7;
const ll maxn = 2e5 + 11;
const ll dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

ll n, m, d[2][maxn], f[2][maxn], s[2], ans, cnt;

vector<pii> g[maxn];

priority_queue<pii> q;

void dijkstra(bool x){
	for(int i = 1; i <= n; ++i)
		d[x][i] = inf;

	d[x][s[x]] = 0;
	f[x][s[x]] = 1;
	q.push({0, s[x]});
	while(!q.empty()){
		ll v = q.top().sc, dist = -q.top().fr;
		q.pop();
		if(dist != d[x][v]) skip;
		for(pii to : g[v]){
			if(d[x][v] + to.sc < d[x][to.fr]){
				d[x][to.fr] = d[x][v] + to.sc;
				f[x][to.fr] = 0;
				q.push({-d[x][to.fr], to.fr});
			}
			if(d[x][to.fr] == d[x][v] + to.sc)
				f[x][to.fr] = (f[x][to.fr] + f[x][v]) % mod;
		}
	}
}

int main(){

ios_base::sync_with_stdio(0);
cin.tie(NULL);

cin >> n >> m >> s[0] >> s[1];

for(int i = 0, v[2], cost; i < m; ++i){
	cin >> v[0] >> v[1] >> cost;
	g[v[0]].pb({v[1], cost});
	g[v[1]].pb({v[0], cost});	
}

dijkstra(0);
dijkstra(1);

ans = (f[0][s[1]] * f[1][s[0]]) % mod;
cnt = d[0][s[1]];

for(int i = 1; i <= n; ++i){
	if(d[0][i] + d[1][i] == cnt && d[1][i] == d[0][i])
		ans = (ans - ((((f[0][i] * f[1][i]) % mod) * ((f[0][i] * f[1][i]) % mod)) % mod) + mod) % mod;
	for(pii to : g[i]){
		if(d[0][i] + d[1][to.fr] + to.sc == cnt && d[0][i] * 2 < cnt && d[1][to.fr] * 2 < cnt)
			ans = (ans - ((((f[0][i] * f[1][to.fr]) % mod) * ((f[0][i] * f[1][to.fr]) % mod)) % mod) + mod) % mod;
	}
}

cout << ans;

return 0;
}
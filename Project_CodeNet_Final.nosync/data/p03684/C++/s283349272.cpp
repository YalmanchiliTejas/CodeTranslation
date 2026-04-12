//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

vi G[N];
int n, X[N], Y[N], ind[N], par[N], sz[N];
ll ans;
vector<pair<int, pii>> E;

bool cmp(int x, int y){
	return (X[x] < X[y]);
}

bool cmp2(int x, int y){
	return (Y[x] < Y[y]);
}

int getpar(int v){
	return (par[v] == v?v:par[v] = getpar(par[v]));
}

void merge(int v, int u, int w){
	v = getpar(v), u = getpar(u);
	if (v == u) return;
	ans += w;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> X[i] >> Y[i];
		ind[i] = i;
	}
	sort(ind + 1, ind + n + 1, cmp);
	for (int i = 2; i <= n; i++){
		E.pb({X[ind[i]] - X[ind[i - 1]], {ind[i - 1], ind[i]}});
	}
	sort(ind + 1, ind + n + 1, cmp2);
	for (int i = 2; i <= n; i++){
		E.pb({Y[ind[i]] - Y[ind[i - 1]], {ind[i - 1], ind[i]}});
	}
	sort(all(E));
	for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
	for (auto u:E){
		merge(u.S.F, u.S.S, u.F);
	}
	cout << ans;




	return 0;
}

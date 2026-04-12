#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e15;
const ll MOD = 1e9 + 7;

const ll MAX_N = 100000 * 2;

// Union-Find
ll par[MAX_N];
ll u_rank[MAX_N];

void init(ll n){
	for (ll i = 0; i < n; i++){
		par[i] = i;
		u_rank[i] = 0;
	}
}

ll find(ll x){
	if (par[x] == x){
		return x;
	}
	else{
		return par[x] = find(par[x]);
	}
}

void unite(ll x, ll y){
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (u_rank[x] < u_rank[y]){
		par[x] = y;
	}
	else{
		par[y] = x;
		if (u_rank[x] == u_rank[y]) u_rank[x]++;
	}
}

bool same(ll x, ll y){
	return find(x) == find(y);
}

struct edge{ ll u, v, cost; };

bool comp_p(const pll& l, const pll& r){
	return l.second < r.second;
}

bool comp_e(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

int main(){
	ll N;
	cin >> N;
	vector<pll> P;
	vector<pll> X, Y;
	ll i, j, k;
	for (i = 0; i < N; i++){
		ll x, y;
		cin >> x >> y;
		X.push_back(pll(i, x));
		Y.push_back(pll(i, y));
	}
	sort(X.begin(), X.end(), comp_p);
	sort(Y.begin(), Y.end(), comp_p);
	vector<edge> E;
	for (i = 0; i < N - 1; i++){
		ll u = X[i].first;
		ll v = X[i + 1].first;
		edge e;
		e.u = u;
		e.v = v;
		e.cost = X[i + 1].second - X[i].second;
		E.push_back(e);
		u = Y[i].first;
		v = Y[i + 1].first;
		edge f;
		f.u = u;
		f.v = v;
		f.cost = Y[i + 1].second - Y[i].second;
		E.push_back(f);
	}
	sort(E.begin(), E.end(), comp_e);
	ll M = E.size();
	init(M);
	ll ans = 0;
	for (i = 0; i < M; i++){
		edge e = E[i];
		if (!same(e.u, e.v)){
			unite(e.u, e.v);
			ans += e.cost;
		}
	}
	cout << ans << endl;
	return 0;
}

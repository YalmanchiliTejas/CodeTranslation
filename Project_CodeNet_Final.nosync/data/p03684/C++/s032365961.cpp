#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];

template <class Abel> struct UnionFind {
	vector<ll> par, rank;
	vector<Abel> dif_weight;
	UnionFind(int n = 1, Abel SUM_UNIT = 0){
		par.resize(n);rank.resize(n);dif_weight.resize(n);
		for(int i = 0;i < n;i++){
			par[i] = i;rank[i] = 0;
			dif_weight[i] = SUM_UNIT;
		}
	}
	Abel weight(int i){
		root(i);
		return dif_weight[i];
	}
	bool merge(int x, int y, Abel w) {
		w += dif_weight[x]; w-= dif_weight[y];
		x = root(x), y = root(y);
		if(x == y)return false;
		if(rank[x] < rank[y])swap(x, y), w = -w;
		if(rank[x] == rank[y])++rank[x];
		par[y] = x;
		dif_weight[y] = w;
		return true;
	}
	bool isSame(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		if(x == par[x])return x;
		else {
			int r = root(par[x]);
			dif_weight[x] += dif_weight[par[x]];
			return par[x] = r;
		}
	}
	Abel dif(int x, int y){
		return dif_weight[y] - dif_weight[x];
	}
};

int main(){
	IOS;
	ll n;
	cin >> n;
	vec<P> vx(n),vy(n);
	REP(i,n){
		ll x, y;
		cin >> x >> y;
		vx[i] = make_pair(x,i);
		vy[i] = make_pair(y,i);
	}
	sort(ALL(vx));
	sort(ALL(vy));
	vec<tuple<ll,ll,ll>> g;
	REP(i,n - 1){
		ll cost = abs(vx[i + 1].first - vx[i].first);
		ll from = vx[i].second;
		ll to = vx[i + 1].second;
		g.push_back(make_tuple(cost,from,to));
		cost = abs(vy[i + 1].first - vy[i].first);
		from = vy[i].second;
		to = vy[i + 1].second;
		g.push_back(make_tuple(cost,from,to));
	}
	sort(ALL(g));
	ll m = g.size();
	UnionFind<ll> uf(n);
	ll ans = 0;
	REP(i,m){
		ll cost = get<0>(g[i]);
		ll from = get<1>(g[i]);
		ll to = get<2>(g[i]);
		if(!uf.isSame(from,to)){
			uf.merge(from,to,0);
			ans += cost;
		}
	}
	dump(ans);
}
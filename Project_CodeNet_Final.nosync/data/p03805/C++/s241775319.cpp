#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);(i)++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;(i)>=(int)(m);(i)--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)

#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'

using ll = long long;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;


typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

//constexpr long long MOD = (ll) 1e9+7;
constexpr long long MOD = 998244353;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	int to, cap, rev;
	Edge(int _to, int _cap, int _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, int from, int to, int cap, bool revFlag, int revCap) {
	G[from].push_back(Edge(to, cap, G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, G[from].size() - 1));
}

ll n, m;
ll ans;

void dfs(vector<vector<ll>>& g, ll v, Array order) {
	order.push_back(v);
	if (order.size() == n) {
		ans++;
		return;
	}
	for (auto next : g[v]) {
		bool flag = false;
		for (auto i : order) if (i == next) flag = true;
		if (flag) continue;
		dfs(g, next, order);
	}
}

void solve() {
	
	cin >> n >> m;

	vector<vector<ll>> g(n);
	REP(i, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	Array order;
	dfs(g, 0, order);
	cout << ans << en;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	//int t; cin >> t; REP(i, t) solve();

	return 0;
}

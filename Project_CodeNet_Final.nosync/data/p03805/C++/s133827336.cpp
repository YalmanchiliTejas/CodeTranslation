#include <iostream>
#include<queue>
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

#define MOD 1000000007
#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define rep(i,j,n) for(ll (i)=(j);(i)<(n);(i)++)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
typedef pair<ll, ll> P;
const long long INF = 1LL << 60;
typedef vector<ll> Array;
typedef vector<Array> Matrix;


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

//グラフ関連
struct Edge {//グラフ
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

bool dfs(Graph& g, Array& used, ll v,ll pre) {
	used[v] = true;
	for (auto e : g[v]) {
		if (e.to != pre) {
			if (used[e.to]) {
				return false;
			}
			else {
				if (!dfs(g, used, e.to, v)) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	Matrix map(n, Array(n, false));
	
	REP(i, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		map[a][b] = true;
		map[b][a] = true;
	}

	Array order(n-1,0);
	REP(i, n - 1) order[i] = i + 1;

	ll ans = 0;
	do {
		bool flag = true;
		ll u = 0;
		REP(i, n - 1) {
			ll v = order[i];
			if (map[u][v] ==false) {
				flag = false;
				break;
			}
			u = v;
		}
		if (flag)ans++;
	
	} while (next_permutation(all(order)));

	cout << ans << endl;

	return 0;
}
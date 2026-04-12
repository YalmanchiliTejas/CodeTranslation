#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using u32 = uint32_t;
using vi = vector<int>;    using vvi = vector<vi>;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;
using vd = vector<double>; using vvd = vector<vd>;

#define MAXC(c, x) (c = max(c, x))
#define MINC(c, x) (c = min(c, x))

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;

const ll INF = 1e9;

template<typename F> double bsearch(double ok, double ng, ll loop, F f) {
	REP(i, loop) {
		double middle = (ok + ng) / 2;
		(f(middle) ? ok : ng) = middle;
	}
	return ok;
}


int main() {
	#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
	#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);
	ll n; cin >> n;
	vvl path(n);
	REP(i, n - 1) {
		ll u, v; cin >> u >> v;
		u--,v--;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	vl leafs;
	REP(i, n) if (path[i].size() == 1) leafs.push_back(i);

	vl deg(n); REP(i, n) deg[i] = path[i].size();
	vb used(n, 0);
	while (!leafs.empty()) {
		ll id = leafs.back();
		leafs.pop_back();
		if (used[id]) continue;

		// 葉の親を探す
		ll next = [&] {
			for (auto node : path[id]) if (!used[node]) return node;
			assert(false);
		}();

		// 葉が孤独頂点だった場合
		used[id] = 1;
		used[next] = 1;
		for (auto node : path[next]) if(!used[node]) {
			deg[node]--;
			if (deg[node] == 1) leafs.push_back(node);
			if (deg[node] == 0) {
				cout << "First" << endl;
				return 0;
			}
		}
	}
	cout << "Second" << endl;


	return 0;
}

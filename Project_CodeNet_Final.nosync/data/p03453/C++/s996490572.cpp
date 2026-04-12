#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 1000000007;







int n, m, s, t;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;


void dijkstra(int s, vector<vector<pair<int, int>>> &E, vector<ll> &D, vector<ll> &C) {
	REP(i, n) D[i] = INFL;

	min_priority_queue<pair<ll, int>> que;

	D[s] = 0;
	que.push({ 0, s });

	while (!que.empty()) {
		auto q = que.top();
		que.pop();

		ll cst = q.first;
		int cu = q.second;


		fore(p, E[cu]) {
			ll cst2 = cst + p.second;
			int to = p.first;
			if (D[to] == cst2) {
				C[to] += C[cu];
				C[to] %= mod;
			}
			
			if (chmin(D[to], cst2)) {
				que.push({ D[to], to });
				C[to] = C[cu];
			}
		}
	}
}



int main() {


	cin >> n >> m >> s >> t;
	s--; t--;

	vector<vector<pair<int, int>>> c(n), d(n);

	VLL da(n), db(n);

	vector<pair<int, pair<int, int>>> p;

	REP(i, m) {
		int u, v, a, b;
		cin >> u >> v >> a;
		u--; v--;
		p.push_back({ u,{v,a} });
		p.push_back({ v,{u,a} });
		c[u].push_back({ v,a });
		c[v].push_back({ u,a });
		d[u].push_back({ v,a });
		d[v].push_back({ u,a });
	}

	VLL pa(n, 0), pi(n, 0);
	pa[s] = 1;
	pi[t] = 1;

	dijkstra(s, c, da, pa);
	dijkstra(t, d, db, pi);
	REP(i, n) {
		pa[i] %= mod;
		pi[i] %= mod;
	}

	ll ans = pa[t] * pa[t] % mod;




	REP(i, n) {
		if (da[i] + da[i] == da[t]) {
			ans -= pa[i] * pi[i] % mod * pa[i] % mod * pi[i] % mod;
			ans += mod;
			ans %= mod;
		}
	}



	REP(i, m * 2) {
		int a = p[i].first;
		int b = p[i].second.first;
		int c = p[i].second.second;
		if (da[a] + da[a] == da[t])continue;
		if (da[a] + db[b] + c == da[t]) {
			if (da[a] + da[a] < da[t] && db[b] + db[b] < da[t]) {
				ans -= pa[a] * pi[b] % mod*pa[a] % mod*pi[b] % mod;
				ans += mod;
				ans %= mod;
			}
		}
	}

	cout << ans << endl;


	return 0;
}
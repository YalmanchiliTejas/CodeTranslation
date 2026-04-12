#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;
const ll INF = 1e18;
const ll MOD = 1000000007;

int N, M;
int S, T;
vector<pii> g[MN];
ll d[2][MN];
ll dp[MN];
ll dpr[MN];

int main() {
	cin >> N >> M;
	cin >> S >> T;
	--S; --T;

	rep(i, M) {
		int u, v, d;
		cin >> u >> v >> d;
		--u; --v; 
		g[u].eb(v, d);
		g[v].eb(u, d);
	}

	using Data = pair<ll, int>;

	vector<int> vec[2];

	rep(tt, 2) {
		priority_queue<Data, vector<Data>, greater<Data>> que;

		int s = (tt == 0 ? S : T);
		que.push(mp(0LL, s));

		rep(i, N) {
			d[tt][i] = INF;
		}
		d[tt][s] = 0;

		while (!que.empty()) {
			Data p = que.top(); que.pop();
			int v = p.se;
			if (d[tt][v] < p.fi) continue;

			vec[tt].pb(v);

			for (auto e : g[v]) {
				ll nd = d[tt][v] + e.se;
				if (d[tt][e.fi] > nd) {
					d[tt][e.fi] = nd;
					que.push(mp(nd, e.fi));
				}
			}
		}
	}

	dp[S] = 1;
	rep(i, N) {
		int v = vec[0][i];
		for (auto e : g[v]) {
			if (d[0][e.fi] == d[0][v] + e.se) {
				dp[e.fi] = (dp[e.fi] + dp[v]) % MOD;
			}
		}
	}

	dpr[T] = 1;
	rep(i, N) {
		int v = vec[1][i];
		for (auto e : g[v]) {
			if (d[1][e.fi] == d[1][v] + e.se) {
				dpr[e.fi] = (dpr[e.fi] + dpr[v]) % MOD;
			}
		}
	}

	ll ret = dp[T] * dpr[S] % MOD;
//	cerr << ret << endl;
	ll dT = d[0][T];

	rep(v, N) {
		if (d[0][v] == d[1][v] && d[0][v] + d[1][v] == dT) {
			ll dec = dp[v] * dpr[v] % MOD;
			dec = dec * dec % MOD;
		//	cout << "dec = " << dec << endl;
			ret -= dec;
			if (ret < 0) ret += MOD;
		}

		for (auto e : g[v]) {
			if (d[0][e.fi] == d[0][v] + e.se && d[1][v] == d[1][e.fi] + e.se && d[0][v] + d[1][e.fi] + e.se == dT) {
				ll D = e.se;
				ll m1 = d[0][v];
				ll m2 = d[1][e.fi];
				if (m1 > m2) {
					swap(m1, m2);
				}
				if (m1 + D > m2) {
					ll dec = dp[v] * dpr[e.fi] % MOD;
					dec = dec * dec % MOD;
					ret -= dec;
					if (ret < 0) ret += MOD;
				//	cout << "edge = " << dec << endl;
				}
			}
		}
	}
	cout << ret << endl;

	return 0;
}
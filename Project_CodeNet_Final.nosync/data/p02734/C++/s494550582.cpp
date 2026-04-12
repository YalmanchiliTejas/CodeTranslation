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
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
constexpr long long INF = 1 << 60;
constexpr int INF_INT = 1 << 25;

typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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


void solve() {
	ll n, s;
	cin >> n >> s;
	Array a(n);
	REP(i, n)cin >> a[i];

	Matrix dp(n + 1, Array(s + 1, 0));
	dp[0][0] = 1;
	ll ans = 0;

	REP(i, n) {

		REP(j, s + 1) {
			if (dp[i][j] == 0) continue;

			(dp[i + 1][j] += dp[i][j]) %= MOD;
			
			if (j == 0) {
				//0から遷移するときはi+1区間分、sへ遷移するときはn-i区間分カウントされる
				if (a[i] <= s) (dp[i + 1][j+a[i]] += dp[i][j] * (i + 1) % MOD) %= MOD;
				if (a[i] == s) (ans += dp[i][j] * (i + 1) * (n - i) % MOD) %= MOD;
				continue;
			}

			if (j + a[i] <= s) (dp[i + 1][j + a[i]] += dp[i][j]) %= MOD;
			if (j + a[i] == s) (ans += dp[i][j] * (n - i) % MOD) %= MOD;

		}

	}

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

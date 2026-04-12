#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int main() {
	ll N, X, M;
	cin >> N >> X >> M;
	
	vector<bool> done(M);
	vector<int> g(M, -1);
	int edcnt = 0;
	
	auto dfs = [&](auto && self, ll x) -> void {
		if (done[x]) return;
		done[x] = true;
		
		ll nxt = x * x % M;
		g[x] = nxt;
		++edcnt;
		self(self, nxt);
	};
	
	dfs(dfs, X);
	
	vector<int> in(M, 0); // 入次数
	REP(i, M) if (g[i] != -1) ++in[g[i]];
	
	ll ans = 0, cur = X;
	while (N > 0 && in[cur] == 0) {
		ans += cur;
		--N;
		--in[g[cur]];
		--edcnt;
		cur = g[cur];
	}
	
	ll cyclesum = 0;
	REP(i, M) if (in[i] == 1) cyclesum += i;
	
	if (N == 0) {
		cout << ans << endl;
		return 0;
	}
	
	// 閉路には edcnt 個の辺
	ans += (N / edcnt) * cyclesum;
	N %= edcnt;
	while (N > 0) {
		ans += cur;
		--N;
		cur = g[cur];
	}
	
	cout << ans << endl;
	
	return 0;
}

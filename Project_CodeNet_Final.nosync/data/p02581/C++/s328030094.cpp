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
	int N;
	cin >> N;
	
	vector<int> A(3 * N);
	REP(i, 3 * N) scanf("%d", &A[i]), --A[i];
	
	int base = 0;
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, -INF));
	
	auto update = [&](int i, int j, int x) {
		chmax(dp[i][j], x);
		chmax(dp[j][i], x);
		chmax(dp[N][j], x);
		chmax(dp[j][N], x);
		chmax(dp[i][N], x);
		chmax(dp[N][i], x);
		chmax(dp[N][N], x);
	};
	
	update(A[0], A[1], 0);
	
	struct Data { int i, j, x; };
	
	REP(t, N - 1) {
		int idx = t * 3 + 2;
		if (A[idx] == A[idx + 1] && A[idx + 1] == A[idx + 2]) { ++base; continue; }
		
		vector<Data> upd;
		FOR(s, 1, 7) {
			vector<int> v, ev;
			REP(i, 3) {
				if (s >> i & 1) v.emplace_back(A[idx + i]);
				else ev.emplace_back(A[idx + i]);
			}
			
			if (v.size() == 1) {
				upd.emplace_back(Data{ev[0], ev[1], dp[N][N]});
				if (dp[v[0]][v[0]] != -INF) upd.emplace_back(Data{ev[0], ev[1], dp[v[0]][v[0]] + 1});
			}
			else {
				REP(j, N) upd.emplace_back(Data{ev[0], j, dp[N][j]});
				if (v[0] == v[1]) REP(j, N) if (dp[j][v[0]] != -INF) upd.emplace_back(Data{ev[0], j, dp[j][v[0]] + 1});
			}
		}
		
		for (auto &&cur : upd) update(cur.i, cur.j, cur.x);
	}
	int ans = -INF;
	REP(i, N) REP(j, N) chmax(ans, dp[i][j]);
	chmax(ans, dp[A.back()][A.back()] + 1);
	ans += base;
	cout << ans << endl;
	return 0;
}

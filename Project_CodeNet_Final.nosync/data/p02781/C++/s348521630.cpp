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

string N;
int K;

ll dp[110][2][4][2];

// i 桁目で合計sk個 maxかどうか
ll dfs(int i, int lz, int sk, int mx) {
	if (i == -1) {
		return !lz && sk == K;
	}
	if (sk > K) return 0;
	// cout << i << " " << lz << " " << sk <<" " <<  mx << endl;
	
	ll &res = dp[i][lz][sk][mx];
	if (~res) return res;
	res = 0;
	
	REP(k, 10) {
		if (mx && k > N[i] - '0') break;
		res += dfs(i - 1, lz && k == 0, sk + (k != 0), mx && k == (N[i] - '0'));
	}
	// cout << i << " " << lz << " " << sk << mx << endl;
	return res;
}

int main() {
	cin >> N >> K;
	while (N.size() < 105) N.insert(N.begin(), '0');
	reverse(ALL(N));
	ll ans = 0;
	
	memset(dp, -1, sizeof(dp));
	cout << dfs(104, true, 0, true);
	return 0;
}

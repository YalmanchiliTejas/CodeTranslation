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
	
	using ull = unsigned long long;
	vector<ull> S(N), T(N), U(N), V(N);
	REP(i, N) scanf("%llu", &S[i]);
	REP(i, N) scanf("%llu", &T[i]);
	REP(i, N) scanf("%llu", &U[i]);
	REP(i, N) scanf("%llu", &V[i]);
	
	vector<vector<ull>> ans(N, vector<ull>(N, 0));
	REP(bit, 64) {
		REP(i, N) if (S[i] == 0) REP(j, N) ans[i][j] |= U[i] & (1ull << bit);
		REP(j, N) if (T[j] == 0) REP(i, N) ans[i][j] |= V[j] & (1ull << bit);
		
		vector<int> cx, cy; // 追加で置かなければならない
		vector<int> prx, pry; // 置いても良い
		REP(i, N) if (S[i] == 1 && (U[i] >> bit & 1)) { // i行目 OR 1
			bool ok = false; // j 列目 AND 1 の存在確認
			REP(j, N) if (T[j] == 0 && (V[j] >> bit & 1)) ok = true;
			if (ok) pry.push_back(i);
			else cy.push_back(i);
		}
		
		REP(j, N) if (T[j] == 1 && (V[j] >> bit & 1)) {
			bool ok = false;
			REP(i, N) if (S[i] == 0 && (U[i] >> bit & 1)) ok = true;
			if (ok) prx.push_back(j);
			else cx.push_back(j);
		}
		
		// S-U, T-V
		REP(i, N) if (S[i] == 0 && (U[i] >> bit & 1 ^ 1)) pry.push_back(i);
		REP(j, N) if (T[j] == 0 && (V[j] >> bit & 1 ^ 1)) prx.push_back(j);
		
		int ccx = cx.size();
		int ccy = cy.size();
		REP(i, prx.size()) cx.push_back(prx[i]);
		REP(i, pry.size()) cy.push_back(pry[i]);
		
		REP(i, ccx) {
			if (cy.empty()) continue;
			int cy_idx = i % (ccy >= 2 ? ccy : cy.size());
			ans[cy[cy_idx]][cx[i]] |= 1ull << bit;
		}
		REP(i, ccy) {
			if (cx.empty()) continue;
			int cx_idx = i % (ccx >= 2 ? ccx : cx.size());
			ans[cy[i]][cx[cx_idx]] |= 1ull << bit;
		}
	}
	
	bool ok = true;
	REP(i, N) {
		ull bor = 0, band = ans[i][0];
		REP(j, N) {
			bor |= ans[i][j];
			band &= ans[i][j];
		}
		if (!(S[i] == 0 && band == U[i] || S[i] == 1 && bor == U[i])) ok = false;
	}
	
	REP(j, N) {
		ull bor = 0, band = ans[0][j];
		REP(i, N) {
			bor |= ans[i][j];
			band &= ans[i][j];
		}
		if (!(T[j] == 0 && band == V[j] || T[j] == 1 && bor == V[j])) ok = false;
	}
	
	if (!ok) puts("-1");
	else REP(i, N) REP(j, N) printf("%llu%c", ans[i][j], j + 1 == N ? '\n' : ' ');
	return 0;
}

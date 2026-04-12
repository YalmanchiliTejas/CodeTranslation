#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;
int64 N, X;
vector<int64> lay, pat;

int64 dfs(int64 lev, int64 rest){
	if(lev < 0) return 0;
	if(rest <= 0) return 0;
	if(rest == 1) return lev == 0;
	if(lay[lev] <= rest) return pat[lev];
	return dfs(lev-1, rest-1)+dfs(lev-1, rest-lay[lev-1]-2)+(rest >= lay[lev-1]+2 ? 1 : 0);
}

int main(void){
	cin >> N >> X;
	lay.resize(N+1); pat.resize(N+1);
	lay[0] = 1; pat[0] = 1;
	FOR(i, 1, N+1){
		lay[i] = lay[i-1]*2+3;
		pat[i] = pat[i-1]*2+1;
	}
	cout << dfs(N, X) << endl;
}

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

using Row = vector<int64>;
using Mat = vector<Row>;

int64 dp[3010][3010] = {};
bool visited[3010][3010] = {};
int32 N;
vector<int64> a;

int64 dfs(int32 l, int32 r){
	if(visited[l][r]) return dp[l][r];
	if(l == r) return 0;
	visited[l][r] = 1;
	int32 rest = r-l;
	if(rest%2 == N%2){
		dp[l][r] = max(dfs(l+1,r)+a[l], dfs(l,r-1)+a[r-1]);
	}else{
		dp[l][r] = min(dfs(l+1,r)-a[l], dfs(l,r-1)-a[r-1]);
	}
	return dp[l][r];
}

int main(void){
	cin >> N;
	a.resize(N);
	REP(i, N) cin >> a[i];
	REP(i, N+1){
		REP(j, N+1){
			if((j-i)%2 == N%2)
				dp[i][j] = INF_LL;
			else
				dp[i][j] = -INF_LL;
		}
	}
	cout << dfs(0, N) << endl;
}


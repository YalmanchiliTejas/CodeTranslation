#include "bits/stdc++.h"
using namespace std;
//#include "atcoder/all"
namespace atcoder{}
using namespace atcoder;
#define int long long
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define RREP(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define FOR(i, s, n) for (int i = s; i < (int)n; ++i)
#define RFOR(i, s, n) for (int i = (int)n - 1; i >= s; --i)
#define ALL(a) a.begin(), a.end()
#define IN(a, x, b) (a <= x && x < b)
template<class T>istream&operator >>(istream&is,vector<T>&vec){for(T&x:vec)is>>x;return is;}
template<class T>inline void out(T t){cout << t << "\n";}
template<class T,class... Ts>inline void out(T t,Ts... ts){cout << t << " ";out(ts...);}
template<class T>inline bool CHMIN(T&a,T b){if(a > b){a = b;return true;}return false;}
template<class T>inline bool CHMAX(T&a,T b){if(a < b){a = b;return true;}return false;}
constexpr int INF = 1e18;

signed main(){
	int N, X, M;
	cin >> N >> X >> M;
	vector<int>to(M);
	vector<int>val(M);
	REP(i, M) {
		to[i] = i * i % M;
		val[i] = i;
	}
	vector<vector<int>>dp(60, vector<int>(M));
	vector<vector<int>>cost(60, vector<int>(M));
	REP(i, M) {
		dp[0][i] = to[i];
		cost[0][i] = val[i];
	}
	REP(i, 59) {
		REP(j, M) {
			dp[i + 1][j] = dp[i][dp[i][j]];
			cost[i + 1][j] = cost[i][j] + cost[i][dp[i][j]];
		}
	}
	int ans = 0;
	int pos = X;
	REP(i, 60) {
		if((N & (1ll << i)) == 0) continue;
		ans += cost[i][pos];
		pos = dp[i][pos];
	}
	out(ans);

}
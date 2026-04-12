#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

const int MOD = 998244353;
int dp[3005];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, s;
	std::cin >> n >> s;
	VI A(n+1);
	FOR(i, n) std::cin >> A[i+1];
	int ans = 0;
	dp[0] = 1;
	REP(i, 1, n+1){
		for(int j=s; j > A[i]; --j)
			dp[j] = (dp[j]+dp[j-A[i]])%MOD;
		dp[A[i]] = (dp[A[i]] + i)%MOD;
		ans = (ans+dp[s])%MOD;
	}
	std::cout << ans;

	return 0;
}
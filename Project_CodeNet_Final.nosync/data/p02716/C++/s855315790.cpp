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

int N;
int A[212345];
map<int, ll> dp[212345][2];

ll dfs(int i, bool used, int sum) {
	if (i == N) {
		if (sum == N / 2) return 0;
		else return -longINF;
	}
	if (sum > N / 2) return -longINF;
	
	int res = N - i - used;
	if (res < 0 || res == 0 && sum != N / 2) return -longINF;
	
	int can = (res + 1) / 2;
	if (sum + can < N / 2) return -longINF;
	
	if (used) return dfs(i + 1, false, sum);
	
	if (dp[i][used].find(sum) != dp[i][used].end()) return dp[i][used][sum];
	
	ll mx = dfs(i + 1, true, sum + 1) + A[i];
	chmax(mx, dfs(i + 1, false, sum));
	return dp[i][used][sum] = mx;
}

int main() {
	cin >> N;
	REP(i, N) scanf("%d", A + i);
	cout << dfs(0, 0, 0);
	return 0;
}

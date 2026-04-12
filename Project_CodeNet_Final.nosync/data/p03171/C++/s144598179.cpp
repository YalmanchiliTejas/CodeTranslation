#include"bits/stdc++.h"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7



//メイン関数
int main()
{
	// input
	int N;
	cin >> N;
	vector<ll> a(N);
	vector<vector<ll>> dp(N, vector<ll>(N));
	REP(i, N)cin >> a[i];

	// init
	REP(i, N)dp[i][i] = (N % 2 == 1 ? 1 : -1)*a[i];

	// dp
	REP(i, N)for(int j = i - 1; j >= 0; j--)
	{
		dp[i][j] = (N % 2 == (i + j + 1) % 2
			? max(dp[i - 1][j] + a[i], dp[i][j + 1] + a[j])
			: min(dp[i - 1][j] - a[i], dp[i][j + 1] - a[j]));
	}
	cout << dp.back().front() << endl;
	cin >> N;

	return 0;
}

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

vector<vector<ll>> make_dp(const int H, const int W)
{
	vector<vector<ll>> dp(H, vector<ll>(W, 0));

	// init
	REP(i, 10)dp[0][i%W]++;

	// dp
	REP(i, H - 1)REP(j, W)REP(k, 10)
	{
		dp[i + 1][(j + k) % W] = (dp[i + 1][(j + k) % W] + dp[i][j]) % MOD;
	}
	return dp;
}

ll summerize(const vector<vector<ll>>& dp, const string& K)
{
	const int D = dp[0].size();
	ll res = 0;
	ll odd = 0;
	REP(i, K.size() - 1)
	{
		REP(j, K[i] - '0')
		{
			ll tmp = (odd + j) % D;
			tmp = (D - tmp) % D;
			res = (res + dp[i + 1][tmp]) % MOD;
		}
		odd = (odd + K[i] - '0') % D;
	}
	REP(i, K.back() - '0' + 1)if((odd + i) % D == 0)res++;
	res = (res - 1 + MOD) % MOD;
	return res;
}

//メイン関数
int main()
{
	string K;
	int D;
	cin >> K >> D;

	auto dp = make_dp(K.size(), D);
	reverse(dp.begin(), dp.end());
	cout << summerize(dp, K) << endl;
	cin >> K;

	return 0;
}

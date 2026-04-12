#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll MOD = 1e9+7;
constexpr ll INF = 1ll<<60;

#define FOR(i,a,b) for (ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

ll MAX_J = 100;
ll dp[110][2][110];

int main(int argc, char **argv)
{
	string S; cin >> S;
	ll K; cin >> K;
	ll N = S.size();

	memset(dp, 0, sizeof dp);
	***dp = 1;

	REP(i, N)
	{
		REP(j, MAX_J)
		{
			REP(k, 10)
				dp[i+1][true][j+(k!=0)] += dp[i][true][j];

			ll Ni = S[i] - '0';

			REP(k, Ni)
				dp[i+1][true][j+(k!=0)] += dp[i][false][j];

			dp[i+1][false][j+(Ni!=0)] += dp[i][false][j];
		}
	}

	std::cout << dp[N][0][K] + dp[N][1][K] << std::endl;
}
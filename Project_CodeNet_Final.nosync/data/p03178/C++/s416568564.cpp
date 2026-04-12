#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
constexpr ll MOD = 1e9 + 7;

vector<vector<vector<ll>>> way(ll D) {
	// 桁数 -> 末尾数字 -> D除算の余り -> 場合の数
	vector<vector<vector<ll>>> dp(1e4 + 3, vector<vector<ll>>(10, vector<ll>(D, 0)));
	rep(i, 10)dp[0][i][i%D]++;

	// 桁数 -> ソースの末尾数字 -> ソースのD除算余り -> 次の末尾数字
	rep(e, 1e4 + 2)rep(num, 10)rep(d, D)rep(add, 10) {
		(dp[e + 1][add][(d + add) % D] += dp[e][num][d]) %= MOD;
	}
	return dp;
}

int main()
{
	ll D;
	string N;
	cin >> N >> D;
	auto dp = way(D);

	ll res = 0;
	ll left = 0;
	rep(i, N.size()) {
		ll pos = N.size() - i - 1;
		ll top = N[i] - '0';
		rep(j, top) {
			(res += dp[pos][j][(D * 10000 - left) % D]) %= MOD;
		}
		(left += top) %= D;
	}
	if (left == 0)res++;
	//rep(i, N.back() - '0' + 1)if ((left + i) % D == 0)res++;
	res = (res - 1 + MOD) % MOD;
	cout << res % MOD << endl;

	return 0;
}

#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
constexpr ll MOD = 1e9 + 7;

vector<vector<vector<ll>>> dp;

ll rec(const string& s, const ll D, int k = 0, bool tight = true, ll odd = 0) {
	if (k == s.size())return odd == 0;

	ll x = s[k] - '0';
	ll r = tight ? x : 9;
	ll& res = dp[k][tight][odd];
	if (res != -1)return res;
	res = 0;

	rep(d, r + 1) {
		(res += rec(s, D, k + 1, tight && (d == r), (odd + d) % D)) %= MOD;
	}
	return res;
}

int main()
{
	string K;
	ll D;
	cin >> K >> D;
	dp.resize(K.size() + 2, vector<vector<ll>>(2, vector<ll>(D, -1)));
	cout << (rec(K, D) - 1 + MOD) % MOD << endl;
	return 0;
}

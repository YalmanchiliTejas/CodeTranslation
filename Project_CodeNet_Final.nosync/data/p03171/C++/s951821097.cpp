#include "bits/stdc++.h"

using namespace std;
using ll = long long;
const double pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	REP(i, v.size()) { if (i)os << " "; os << v[i]; }return os;
}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
	REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;
}

const ll INF = 1LL << 60;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

#define int long long

inline void my_io() {

	std::ios::sync_with_stdio(false);

	std::cin.tie(0);

	cout << fixed << setprecision(16);

	//cout << setprecision(10) << scientific << ans << endl;

}

ll n;
vector<ll> a;
vector<vector<ll>> dp(3001, vector<ll>(3001, 0));
vector<vector<ll>> used(3001, vector<ll>(3001, 0));

ll solve(ll l, ll r) {
	if (l > r) {
		return 0;
	}

	if (used[l][r]) {
		return dp[l][r];
	}

	used[l][r] = 1;

	ll res;
	ll dif = n - (r - l + 1);

	if (dif % 2 == 0) {
		res = -INF;
		res = max(res, solve(l + 1, r) + a[l]);
		res = max(res, solve(l, r - 1) + a[r]);
	}
	else {
		res = INF;
		res = min(res, solve(l + 1, r) - a[l]);
		res = min(res, solve(l, r - 1) - a[r]);
	}

	dp[l][r] = res;

	return res;
}

signed main() {
	ll x;

	cin >> n;

	REP(i, n) {
		cin >> x;
		a.push_back(x);
	}

	cout << solve(0, n - 1) << endl;
}
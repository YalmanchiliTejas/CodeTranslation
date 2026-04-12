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

	cout << fixed << setprecision(10);

}

bool used[51];
ll b[51];
ll p[51];

pair<ll, ll> solve1(ll n) {
	if (n == 0) {
		return make_pair(1, 1);
	}
	if (used[n]) {
		return make_pair(b[n], p[n]);
	}
	pair<ll, ll> pa = solve1(n - 1);
	b[n] = 2 * pa.first + 3;
	p[n] = 2 * pa.second + 1;
	used[n] = true;
	return make_pair(b[n], p[n]);
}

ll solve2(ll n, ll x) {
	if (n == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	else if (x < b[n - 1] + 2) {
		return solve2(n - 1, x - 1);
	}
	else if (x == b[n - 1] + 2) {
		return p[n - 1] + 1;
	}
	else if (x < 2 * b[n - 1] + 3) {
		return p[n - 1] + 1 + solve2(n - 1, x - b[n - 1] - 2);
	}
	else {
		return 2 * p[n - 1] + 1;
	}
}

signed main() {
	ll n, x;

	cin >> n >> x;

	REP(i, 51) {
		used[i] = false;
		b[i] = 0;
		p[i] = 0;
	}

	used[0] = true;
	b[0] = 1;
	p[0] = 1;
	solve1(n - 1);

	cout << solve2(n, x) << endl;
}
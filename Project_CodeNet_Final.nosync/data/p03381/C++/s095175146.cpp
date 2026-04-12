
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

int main() {
	ll n;
	vector<ll> v, v2;

	cin >> n;

	REP(i, n) {
		ll a;
		cin >> a;
		v.push_back(a);
		v2.push_back(a);
	}

	sort(v2.begin(), v2.end());

	ll x = (v2[n / 2] + v2[n / 2 - 1]);

	REP(i, n) {
		if (v[i] * 2 < x) {
			cout << v2[n / 2] << endl;
		}
		else {
			cout << v2[n / 2 - 1] << endl;
		}
	}
}
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
	REP(i, v.size()) { if (i)os << ""; os << v[i]; }return os;
}
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) {
	REP(i, v.size()) { if (i)os << endl; os << v[i]; }return os;
}

const ll INF = LLONG_MAX;
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

signed main() {
	ll n;
	string s;

	cin >> n >> s;

	vector<string> v(n, "");
	pair<string, string> p[4] = { 
		make_pair("S", "S"), 
		make_pair("S", "W"), 
		make_pair("W", "S"), 
		make_pair("W", "W") 
	};


	REP(k, 4) {
		v[0] = p[k].first;
		v[1] = p[k].second;

		FOR(i, 1, n - 1) {
			if (s[i] == 'o') {
				if (v[i] == "S") {
					v[i + 1] = v[i - 1];
				}
				else {
					if (v[i - 1] == "S") {
						v[i + 1] = "W";
					}
					else {
						v[i + 1] = "S";
					}
				}
			}
			else {
				if (v[i] == "S") {
					if (v[i - 1] == "S") {
						v[i + 1] = "W";
					}
					else {
						v[i + 1] = "S";
					}
				}
				else {
					v[i + 1] = v[i - 1];
				}
			}
		}

		bool flag = true;

		if (s[0] == 'o') {
			if (v[0] == "S") {
				if (v[1] != v[n - 1]) {
					flag = false;
				}
			}
			else {
				if (v[1] == v[n - 1]) {
					flag = false;
				}
			}
		}
		else {
			if (v[0] == "S") {
				if (v[1] == v[n - 1]) {
					flag = false;
				}
			}
			else {
				if (v[1] != v[n - 1]) {
					flag = false;
				}
			}
		}

		if (s[n - 1] == 'o') {
			if (v[n - 1] == "S") {
				if (v[0] != v[n - 2]) {
					flag = false;
				}
			}
			else {
				if (v[0] == v[n - 2]) {
					flag = false;
				}
			}
		}
		else {
			if (v[n - 1] == "S") {
				if (v[0] == v[n - 2]) {
					flag = false;
				}
			}
			else {
				if (v[0] != v[n - 2]) {
					flag = false;
				}
			}
		}

		if (flag) {
			cout << v << endl;
			return 0;
		}
	}

	cout << -1 << endl;
}
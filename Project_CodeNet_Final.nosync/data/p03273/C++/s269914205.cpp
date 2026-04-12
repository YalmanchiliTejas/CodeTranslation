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

signed main() {
	ll h, w;

	cin >> h >> w;

	vector<string> v(h);

	REP(i, h) {
		cin >> v[i];
	}

	bool flag;
	vector<string> vv;

	REP(i, h) {
		flag = false;

		REP(j, w) {
			if (v[i][j] != '.') {
				flag = true;
				break;
			}
		}

		if (flag) {
			vv.push_back(v[i]);
		}
	}

	vector<vector<char>> ans(vv.size());

	REP(i, w) {
		flag = false;

		REP(j, vv.size()) {
			if (vv[j][i] != '.') {
				flag = true;
				break;
			}
		}

		if (flag) {
			REP(j, vv.size()) {
				ans[j].push_back(vv[j][i]);
			}
		}
	}

	REP(i, ans.size()) {
		REP(j, ans[i].size()) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}
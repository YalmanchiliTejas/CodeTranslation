#include "bits/stdc++.h"

#define REP(i, n) for (ll i = 0; i < ll(n); ++i)
#define RREP(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < ll(n); ++i)
#define RFOR(i, m, n) for (ll i = ll(n) - 1; i >= ll(m); --i)
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T &a, const T &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template <class T> bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vi v(n);
	REP(i, n) cin >> v[i];
	map<int, int> mp;
	REP(i, n) {
		auto c = mp.lower_bound(v[i]);
		if (c == mp.begin()) {
			mp[v[i]]++;
		} else {
			c--;
			pii p = *c;
			mp[v[i]]++;
			if (--mp[p.first] == 0) mp.erase(p.first);
		}
	}
	int ans = 0;
	for (auto a : mp) {
		ans += a.second;
	}
	cout << ans << endl;
}
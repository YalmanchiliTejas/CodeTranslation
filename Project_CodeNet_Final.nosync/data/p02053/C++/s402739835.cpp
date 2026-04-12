#include "bits/stdc++.h"

using namespace std;
#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define ll long long
#define DBG 1
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define loop(n) rep(loop, (0), (n))
#define all(c) begin(c), end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using pii = pair<int, int>;
// template<class T> ostream &operator<<(ostream &os,T &t){dump(t);return os;}
template <typename T, typename S>istream &operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
//template <typename T, typename S>ostream &operator<<(ostream &os, pair<T, S> &p) {os << p.first << " " << p.second;return os;}

template <typename T> void printvv(const vector<vector<T>> &v) {
	cerr << endl;
	rep(i, 0, v.size()) rep(j, 0, v[i].size()) {
		if (typeid(v[i][j]).name() == typeid(INF).name() and v[i][j] == INF) {
			cerr << "INF";
		}
		else
			cerr << v[i][j];
		cerr << (j == v[i].size() - 1 ? '\n' : ' ');
	}
	cerr << endl;
}

#ifndef _DEBUG
#define printvv(...)
#endif
void YES(bool f) { cout << (f ? "YES" : "NO") << endl; }
void Yes(bool f) { cout << (f ? "Yes" : "No") << endl; }
template <class T, class U>bool chmin(T& a, U b) { if (a > b) { a = b; return true; }return false; }
template <class T, class U>bool chmax(T& a, U b) { if (a < b) { a = b; return true; }return false; }

signed main(signed argc, char *argv[]) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(12);

	int H, W; cin >> H >> W;
	vector<string>s(H); rep(i, 0, H) { cin >> s[i]; }
	int ans = 0;

	auto f = [&](vector<string>v) {
		int a = 0;
		while (count(all(v[a]), 'B') == 0)a++;
		int b = v.size() - 1;
		while (count(all(v[b]), 'B') == 0)b--;
		rep(i, 0, v[0].size()) {
			rep(j, 0, v[0].size()) {
				if (a == b and i == j)continue;
				if (v[a][i] == 'B' and v[b][j] == 'B') {
					int d = abs(a - b) + abs(i - j);
					chmax(ans, d);
				}
			}
		}
	};
	f(s);
	vector<string>t(W, string(H, '.'));
	rep(i, 0, H) {
		rep(j, 0, W) {
			t[j][i] = s[i][j];
		}
	}
	f(t);
	
	cout << ans << endl;

	return 0;
}


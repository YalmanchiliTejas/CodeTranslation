#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>
#include <random>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

template<class A, class B> ostream& os_func_(std::ostream& os, const pair<A, B> &p){ return os << p.first << ' ' << p.second;}
template<class C> ostream& os_func_(std::ostream& os, const C &c){ os << '{';  auto && endit = c.end(); for (auto it = c.begin(); it != endit;){ os << *it; if (++it != endit) os << ' '; } os << '}'; return os; }
template<class T, class A = std::allocator<T>, template<class ... _> class C> std::ostream& operator<<(std::ostream& os, const C<T, A> &c){ return os_func_(os, c); }
template<class T, class A = std::allocator<T>, template<class T> class COMP, template<class ... _> class C> std::ostream& operator<<(std::ostream& os, const C<T, COMP<T>, A> &c){ return os_func_(os, c); }
template<class T, class U, class A = std::allocator<T>, template<class T> class COMP, template<class ... _> class C> std::ostream& operator<<(std::ostream& os, const C<T, U, COMP<T>, A> &c){ return os_func_(os, c); }

typedef long long ll;
typedef pair<int, int> P;

const int N = 10;
int dp[N][1 << N];

int x[N], y[N];
int d[N][N];

int n, m, W, T;
int rec(int pos, int need){
	if (!need) return d[pos][n];

	int &res = dp[pos][need];
	if (res + 1) return res;
	res = 1e9;
	rep(i, n){
		if (~need >> i & 1) continue;
		res = min(res, d[pos][i] + rec(i, need&~(1 << i)));
	}

	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(12);

	MEMSET(dp, -1);

	cin >> n >> m >> W >> T;

	map<string, pair<int, int>> mp;
	rep(i, m){
		string s;
		cin >> s;
		int w, p;
		cin >> w >> p;
		mp[s] = MP(w, p);
	}

	vector<vector<int>> w(n), v(n);
	rep(i, n){
		int l;
		cin >> l >> x[i] >> y[i];
		while (l--){
			string s;
			int q;
			cin >> s >> q;
			auto p = mp[s];
			if (p.second <= q) continue;
			w[i].push_back(p.first);
			v[i].push_back(p.second - q);
		}
	}

	rep(i, n + 1) rep(j, n + 1) d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

	vector<ll> w2, v2;
	rep(i, 1 << n){
		int cost = 1e9;
		rep(j, n) if (i >> j & 1) cost = min(cost, d[n][j] + rec(j, i&~(1 << j)));

		vector<int> ww, vv;
		rep(j, n) if (i >> j & 1){
			rep(k, w[j].size()){
				ww.push_back(w[j][k]);
				vv.push_back(v[j][k]);
			}
		}

		int sz = ww.size();
		vector<ll> dp(W + 1);
		rep(j, sz) rep(k, W + 1 - ww[j]){
			dp[k + ww[j]] = max(dp[k + ww[j]], dp[k] + vv[j]);
		}

		w2.push_back(cost);
		v2.push_back(*max_element(ALL(dp)));
	}

	int sz = w2.size();
	vector<ll> dp(T + 1);
	rep(i, sz) rep(j, T + 1 - w2[i]){
		dp[j + w2[i]] = max(dp[j + w2[i]], dp[j] + v2[i]);
	}
	cout << *max_element(ALL(dp)) << endl;

	return 0;
}
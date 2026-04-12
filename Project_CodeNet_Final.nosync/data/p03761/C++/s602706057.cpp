#include "bits/stdc++.h"
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

#ifndef _DEBUG
#define main_ main
#endif
#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define INF (INT_MAX/2)
#define EPS (1.0e-8)
#define LINF (LONG_MAX/2)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
typedef vector<string> vs;

template <typename T>
using keyVal = pair<string, T>;
template<typename T>
bool val_greater(const keyVal<T>& left, const keyVal<T>& right) {
	return left.second > right.second;
}

void init_global() {}

int main_() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;  cin >> N;
	vs S(N); FOR(i, 0, N) cin >> S[i];
		
	vi h(26, INF);
	FOR(i, 0, N) {
		vi th(26, 0);
		FOR(j, 0, S[i].size()) {
			th[S[i][j] - 'a']++;
		}

		FOR(c,0,26) {
			h[c] = min(h[c], th[c]);
		}
	}

	string ans = "";
	for (char c = 'a'; c <= 'z'; ++c) {
		ans += string(h[c - 'a'], c);
	}

	cout << ans << endl;
	return 0;
}

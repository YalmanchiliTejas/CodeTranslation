#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int long long

#define rep(i, n) for (signed i = 0; i < signed(n); i++)
#define REP(i, s, n) for (signed i = signed(s); i < signed(n); i++)
#define rrep(i, n) for (signed i = signed(s) - 1; i >= 0; i--)

#define all(c) begin(c), end(c)
template<typename T>bool maxup(T& a, const T&& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool maxup(T& a, const T& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T&& b) { if (a > b) { a = b; return true; }; }
template<typename T>bool minup(T& a, const T& b) { if (a > b) { a = b; return true; }; }

#define X first
#define Y second

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }


void calc() {
	string s;
	cin >> s;
	rep(i, s.size() - 1) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	calc();
#ifdef _MSC_VER
	system("pause");
#endif
}
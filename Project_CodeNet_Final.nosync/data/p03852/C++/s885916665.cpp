#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int long long

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define REP1(i, s, cond, cal) for (signed i = signed(s); i cond; i cal)
#define REP2(i, s, n) REP1(i, s, < signed(n), ++)
#define REP3(i, n) REP2(i, 0, n)
#define rep(...) CHOOSE((__VA_ARGS__,REP1,REP2,REP3))(__VA_ARGS__)
#define rrep(i, s) rep(i, s, >= 0, --)

#define all(c) begin(c), end(c)
template<typename T>bool maxup(T& a, T&& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool maxup(T& a, T& b) { if (a < b) { a = b; return true; }; }
template<typename T>bool minup(T& a, T&& b) { if (a > b) { a = b; return true; }; }
template<typename T>bool minup(T& a, T& b) { if (a > b) { a = b; return true; }; }

#define X first
#define Y second

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }
signed main() {
	char c; cin >> c;
	set<char> s{ 'a','e','i','u','o' };
	cout << (s.count(c) ? "vowel" : "consonant") << endl;
	system("pause");
}
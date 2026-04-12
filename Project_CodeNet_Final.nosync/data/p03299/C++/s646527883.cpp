/*
ЗАПУСКАЕМ 
░ГУСЯ░▄▀▀▀▄░РАБОТЯГУ░░
▄███▀░◐░░░▌░░░░░░░
░░░░▌░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▐░░░░░▐░░░░░░░
░░░░▌░░░░░▐▄▄░░░░░
░░░░▌░░░░▄▀▒▒▀▀▀▀▄
░░░▐░░░░▐▒▒▒▒▒▒▒▒▀▀▄
░░░▐░░░░▐▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░▀▄░░░░▀▄▒▒▒▒▒▒▒▒▒▒▀▄
░░░░░░▀▄▄▄▄▄█▄▄▄▄▄▄▄▄▄▄▄▀▄
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░░░▌▌░▌▌░░░░░
░░░░░░░░░▄▄▌▌▄▌▌░░░░░ 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const pair<T, U> &_p) { _out << _p.first << ' ' << _p.second; return _out; }
template<typename T, typename U> inline istream &operator>> (istream &_in, pair<T, U> &_p) { _in >> _p.first >> _p.second; return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const vector<T> &_v) { if (_v.empty()) { return _out; } _out << _v.front(); for (auto _it = ++_v.begin(); _it != _v.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
template<typename T> inline ostream &operator<< (ostream &_out, const set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_set<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T> inline ostream &operator<< (ostream &_out, const unordered_multiset<T> &_s) { if (_s.empty()) { return _out; } _out << *_s.begin(); for (auto _it = ++_s.begin(); _it != _s.end(); ++_it) { _out << ' ' << *_it; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
template<typename T, typename U> inline ostream &operator<< (ostream &_out, const unordered_map<T, U> &_m) { if (_m.empty()) { return _out; } _out << '(' << _m.begin()->first << ": " << _m.begin()->second << ')'; for (auto _it = ++_m.begin(); _it != _m.end(); ++_it) { _out << ", (" << _it->first << ": " << _it->second << ')'; } return _out; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 101;
const int Mod = 1000000007;


int mul(int a, int b) {
	return (1LL * a * b) % Mod;
}

int sum(int a, int b) {
	return (a + b) % Mod;
}


int powm(int a, int b) {
	if (b == 0) {
		return 1;
	}
	if (b & 1) {
		return mul(a, powm(a, b - 1));
	} else {
		int g = powm(a, b >> 1);
		return mul(g, g);
	}
} 


int n;
int h[MAXN];


int solve1(int l, int r, int depth) {
	if (l == r) {
		return 1;
	}
	int curh = Mod;	
	for (int i = l; i < r; i++) {
		chkmin(curh, h[i]);
	}
	vector<int> st;
	st.pb(l - 1);
	for (int i = l; i < r; i++) {
		if (h[i] == curh) {
			st.pb(i);
		}
	}
	st.pb(r);
	int res = powm(2, curh - depth + 1);
	for (int i = 0; i < sz(st) - 1; i++) {
		int nl = st[i] + 1;
		int nr = st[i + 1];
		if (nl != nr) {
			res = mul(res, solve1(nl, nr, curh + 1));
		} 
	}
	return res;
}


int solve(int l, int r, int depth) {
	if (l + 1 >= r) {
		return 0;
	}
	int curh = Mod;	
	for (int i = l; i < r; i++) {
		chkmin(curh, h[i]);
	}
	if (depth > curh) {
		return 1;
	}
	vector<int> st;
	st.pb(l - 1);
	int res = 1;
	for (int i = l; i < r; i++) {
		if (h[i] == curh) {
			st.pb(i);
			res = mul(res, 2);
		}
	}
	st.pb(r);
	for (int i = 0; i < sz(st) - 1; i++) {
		int nl = st[i] + 1;
		int nr = st[i + 1];
		if (nl != nr) {
			res = mul(res, sum(solve(nl, nr, curh + 1), mul(solve1(nl, nr, curh + 1), 2)));
		}
	}
	return sum(res, Mod - solve1(l, r, curh));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	if (n == 1) {
		cout << powm(2, h[0]) << '\n';
		return 0;
	}
	cout << sum(solve(0, n, 1), solve1(0, n, 1)) << '\n';
}


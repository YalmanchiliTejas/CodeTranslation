#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<(o)<<" ";}
#define dumpl(o) if(DBG){cerr<<#o<<" "<<(o)<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

class Parser {
public:
	using Iter = string::const_iterator;
	Iter it;
	Parser(Iter it) :it(it) {}
	void cmp(char expected) { if (*it != expected)cerr << *it << " is not " << expected << endl; assert(*it == expected); }
	/*
	EBNF
	???=???,{'+',???};
	???=integer,{'*',integer};
	*/
	int a() {
		int ret = b();
		while (true) {
			if (*it == '+') {
				it++;
				ret += b();
			}
			else break;
		}
		return ret;
	}
	int b() {
		int ret = integer();
		while (true) {
			if (*it == '*') {
				it++;
				ret *= integer();
			}
			else break;
		}
		return ret;
	}
	int integer() {
		int ret = 0;
		while (isdigit(*it)) {
			ret *= 10;
			ret += *it - '0';
			it++;
		}
		return ret;
	}
};

class Parser2 {
public:
	using Iter = string::const_iterator;
	Iter it;
	Parser2(Iter it) :it(it) {}
	void cmp(char expected) { if (*it != expected)cerr << *it << " is not " << expected << endl; assert(*it == expected); }
	/*
	EBNF
	???=integer,{('*'|'+'),integer};
	*/
	int a() {
		int ret = integer();
		while (true) {
			if (*it == '*') {
				it++;
				ret *= integer();
			}
			else if (*it == '+') {
				it++;
				ret += integer();
			}
			else break;
		}
		return ret;
	}
	int integer() {
		int ret = 0;
		while (isdigit(*it)) {
			ret *= 10;
			ret += *it - '0';
			it++;
		}
		return ret;
	}
};



signed main() {
	string s; getline(cin, s);
	s += "$";
	Parser P(s.begin());
	Parser2 P2(s.begin());
	int a; cin >> a;
	int a1 = P.a(), a2 = P2.a();
	if (a == a1&&a == a2)cout << "U" << endl;
	else if (a == a1)cout << "M" << endl;
	else if (a == a2)cout << "L" << endl;
	else cout << "I" << endl;
	return 0;
}
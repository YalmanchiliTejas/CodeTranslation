#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <istream>
#include <map>
#include <set>
#include <queue>
#define rep0(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i) 
constexpr int  INF = 1000000007;
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/*
	/
	/
	/
	*/
	string s;
	cin >> s;
	if (s[0] == 'a' || s[0] == 'i' || s[0] == 'u' || s[0] == 'e' || s[0] == 'o') {
		cout<<"vowel"<<endl;
	}
	else {
		cout<<"consonant"<<endl;
	}
}
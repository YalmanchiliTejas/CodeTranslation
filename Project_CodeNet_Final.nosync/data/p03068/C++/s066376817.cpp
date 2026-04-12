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
#define rep0(i,n) for (int i = 0; i <= (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define REP(a,b) for (int i = a; i <= (b); ++i) 
#define mREP(a,b) for (int i = a; i == (b); --i)
#define mod 1e9 + 7
typedef long long ll;
using namespace std;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	/*
	　　　　　 　 _... ..._
	　　　　　 , ´⌒ ⌒ヽ
	　　　 　 ﾉｨ（ノﾉ）ﾉ）ﾉ）
	　　　 　 （（q|.ﾟ ヮﾟﾉ|ﾊ
	　　　　　　△ﾑ,8ﾑﾌつ
	　　　　　/(ﾝ_/＿ヽ＼
	　　　　 ～～i_ﾌ_ﾌ～´
	*/
	int n, m;
	string s;
	cin >> n >> s >> m;

	rep0(i, n - 1) {
		if (s[i] != s[m - 1]) {
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}

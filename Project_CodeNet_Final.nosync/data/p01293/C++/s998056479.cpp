#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int b[256];

int winner(char s, char t, vector<string>& a) {
	vector<int> x(4);
	for (int i = 0; i < 4; i++)
		if (a[i][1] == s) x[i] = b[a[i][0]];
		else if (a[i][1] == t) x[i] = 13 + b[a[i][0]];
		else x[i] = -1;
	int _i, maxi = -1;
	for (int i = 0; i < 4; i++)
		if (x[i] > maxi) {
			_i = i;
			maxi = x[i];
		}
	return _i;
}

int main() {
	b['2'] = 0;
	b['3'] = 1;
	b['4'] = 2;
	b['5'] = 3;
	b['6'] = 4;
	b['7'] = 5;
	b['8'] = 6;
	b['9'] = 7;
	b['T'] = 8;
	b['J'] = 9;
	b['Q'] = 10;
	b['K'] = 11;
	b['A'] = 12;
	for (;;) {
		string _t; cin >> _t;
		char t = _t[0];
		if (t == '#') break;
		vector< vector<string> > c(4, vector<string>(13));
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++)
				cin >> c[i][j];
		int _i = 0, ns = 0, ew = 0;
		for (int j = 0; j < 13; j++) {
			vector<string> a(4);
			for (int i = 0; i < 4; i++)
				a[i] = c[i][j];
			_i = winner(c[_i][j][1], t, a);
			if (_i % 2 == 0) ns++;
			else ew++;
		}
		if (ns > ew) cout << "NS " << ns - 6 << endl;
		else cout << "EW " << ew - 6 << endl;
	}
}
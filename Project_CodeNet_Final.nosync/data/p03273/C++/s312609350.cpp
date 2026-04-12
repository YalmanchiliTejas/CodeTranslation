#include <iostream>
#include <utility>
#include <functional>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
using namespace std;
#define rep(i,n,x) for(int i=n;i<x;i++)
#define rem(i,n,x) for(int i=n;i>x;i--)
#define SORT(x) sort(x.begin(),x.end())
#define REV(x) reverse(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define setp(x) setprecision(x)
using LL = long long;
using ULL = unsigned long long;

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<char>> cell(h, vector<char>(w));
	rep(i, 0, h) rep(j, 0, w) cin >> cell[i][j];

	vector<bool> y(h, false);
	vector<bool> x(w, false);
	rep(i, 0, h) {
		rep(j, 0, w) {
			if (cell[i][j] == '#') {
				y[i] = true;
				x[j] = true;
			}
		}
	}

	rep(i, 0, h) {
		rep(j, 0, w) {
			if (y[i] && x[j]) cout << cell[i][j];
		}
		if (!y[i]) continue;
		cout << endl;
	}

	return 0;
}
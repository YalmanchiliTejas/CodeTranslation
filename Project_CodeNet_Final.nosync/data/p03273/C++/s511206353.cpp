#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <queue>
#include <functional>
#include <cassert>
#include <cmath>
#include <set>
#include <map>

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define NL << endl
using namespace std;
using ll = long long;
const int INFINT = 1 << 30;
const ll INFLL = 1LL << 60;
const int MOD = 1000000007;
int gcd(int a, int b) {return b ? gcd(b, a%b) : a;}

int main() {

	int h, w;

	cin >> h >> w;

	vector<string> map(h);
	REP(i, h) map[i].resize(w);
	vector<int> dx(w);
	vector<int> dy(h);

	REP(i, h)
		cin >> map[i];

	REP(i, h)
		REP(j, w)
		cin >> map[i][j];

	REP(y, h) {
		bool del = true;
		REP(x, w) {
			if (map[y][x] == '#') {
				del = false;
			}
		}
		if (del) dy[y] = 1;
	}
	REP(x, w) {
		bool del = true;
		REP(y, h) {
			if (map[y][x] == '#') {
				del = false;
			}
		}
		if (del) dx[x] = 1;
	}

	REP(y, h) {
		bool out = false;
		REP(x, w) {
			if (dx[x] == 0 && dy[y] == 0) {
				cout << map[y][x];
				out = true;
			}
		}
		if (out) cout NL;
	}



	return 0;
}
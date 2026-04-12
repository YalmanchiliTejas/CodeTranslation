#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
#include <numeric>
#include <limits>
#include <iomanip>
#include <queue>
#include <cmath>
#include <math.h>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
using pll = pair<long long, long long>;
typedef long long ll;
#define min(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)

string getString(char x) {
	string s(1, x);
	return s;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	// cout << std::fixed << std::setprecision(15);

	int A, B, C;
	int X, Y;
	cin >> A >> B >> C >> X >> Y;
	C = 2 * C;
	int big = X;
	int small = X;
	chmax(big, Y);
	chmin(small, Y);
	long long res = INF;
	for (int i = 0; i <= big; i++) {
		long long tmpRes = 0;
		tmpRes += C * i;
		int countA = X;
		int countB = Y;
		if (X - i < 0) {
			countA = 0;
		}
		else {
			countA = X - i;
		}
		if (Y - i < 0) {
			countB = 0;
		}
		else {
			countB = Y - i;
		}
		tmpRes += A * (countA);
		tmpRes += B * (countB);
		chmin(res, tmpRes);
	}

	cout << res << endl;
}

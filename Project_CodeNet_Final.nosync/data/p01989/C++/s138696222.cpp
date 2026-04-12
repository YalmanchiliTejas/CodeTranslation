#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

string S;
int f(int x, int y, int z, int w) {
	dump(x, y, z);
	if (x == 4) {
		if (y == S.size()) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (y == S.size())
			return 0;
	}
	z *= 10;
	z += S[y] - '0';
	if (z > 255)
		return 0;
	
	int ret = 0;
	ret += f(x + 1, y + 1, 0, 0);
	if (z == 0 && w == 0)
		return ret;
	ret += f(x, y + 1, z, w + 1);
	return ret;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> S;
	cout << f(0, 0, 0, 0) << endl;
	return 0;
}

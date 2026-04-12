#include <bits/stdc++.h>
using namespace std;

string k;
int d;
int dp[10010][110][5];
int rj[10010][110];
const int MOD = 1e9 + 7;
int sol = 0;

int rek(int x, int y, int z) {
	if (x == k.size()) {
		if (y == 0) return 1;
		return 0;
	}

	int &ret = dp[x][y][z];
	if (ret != -1) return ret;
	ret = 0;

	if (z == 0) {
		for (int i = 0; i <= 9; i ++) {
			ret += rek(x+1, (y+i)%d, 0);
			ret %= MOD;
		}
	}
	else {
		for (int i = 0; i < (k[x] - '0'); i ++) {
			ret += rek(x+1, (y+i)%d, 0);
			ret %= MOD;
		}

		ret += rek(x+1, (y+(k[x] - '0'))%d, 1);
		ret %= MOD;
	}

	return ret;
}

int dr(int x, int y) {
	if (x == k.size()-1) {
		if (y == 0) return 1;
		return 0;
	}

	int &ret = rj[x][y];
	if (ret != -1) return ret;
	ret = 0;
	if (y == 0) ret ++;

	for (int i = 0; i <= 9; i ++) {
		ret += dr(x+1, (y+i)%d);
		ret %= MOD;
	}

	return ret;
}

int main () {

	cin >> k;
	cin >> d;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i < k[0] - '0'; i ++) {
		sol += rek(1, i%d, 0);
		sol %= MOD;
	}

	sol += rek(1, (k[0] - '0')%d, 1);
	sol %= MOD;

	if (k.size() > 1) {
		memset(rj, -1, sizeof rj);
		for (int i = 1; i < 10; i ++) {
			sol += dr(1, i%d);
			sol %= MOD;
		}
	}

	cout << sol;

	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 105;
const int mod = 1e9 + 7;
int n, num[N], d;
string snum;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mem[N][M][2];
bool vis[N][M][2];

int dp(int i, int m, bool border) {
	if (i == n) {
		return m ? 0 : 1;
	}
	if (vis[i][m][border]) {
		return mem[i][m][border];
	}
	vis[i][m][border] = true;

	int lv = border ? num[i] : 9;

	int ans = 0;
	for (int j = 0; j <= lv; j++) {
		bool nb = border && j == lv;
		ans = add(ans, dp(i + 1, (m + j) % d, nb));
	}

	return mem[i][m][border] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> snum >> d;
	n = snum.size();

	for (int i = 0; i < n; i++) {
		num[i] = snum[i] - '0';
	}

	cout << (mod + dp(0, 0, true) - 1) % mod << '\n';

	return 0;
}

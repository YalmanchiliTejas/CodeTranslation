#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, mod = 1000000007, inf = 0x3f3f3f3f;
int n, h[maxn + 10], ans;
int f[maxn + 10][maxn + 10][2][2][2], tmp[2][2][2];
int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1; x = mul(x, x);
	}
	return ans;
}

int calcmin(int l, int r) {
	int ans = inf;
	for (int i = l; i <= r; ++i) ans = min(ans, h[i]);
	return ans;
}

void upd(int l, int r, int h) {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				tmp[i][j][k] = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) {
			if (h) {
				tmp[i][j][0] = add(tmp[i][j][0], mul(f[l][r][i][j][0], fpow(2, h - 1)));
				tmp[j][i][0] = add(tmp[j][i][0], mul(f[l][r][i][j][0], fpow(2, h - 1)));
			} else tmp[i][j][0] = add(tmp[i][j][0], f[l][r][i][j][0]);
			if (h & 1) tmp[i ^ 1][j ^ 1][1] = add(tmp[i ^ 1][j ^ 1][1], f[l][r][i][j][1]);
			else tmp[i][j][1] = add(tmp[i][j][1], f[l][r][i][j][1]);
		}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				f[l][r][i][j][k] = tmp[i][j][k];
}

void merge(int l, int r, int ll, int rr) {
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				tmp[i][j][k] = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int s = 0; s < 2; ++s)
					for (int p = 0; p < 2; ++p)
						for (int q = 0; q < 2; ++q) {
							int st = i, ed = p, t = k || q || (j == s);
							tmp[st][ed][t] = add(tmp[st][ed][t], mul(f[l][r][i][j][k], f[ll][rr][s][p][q]));
						}
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				f[l][r][i][j][k] = tmp[i][j][k];
}

void dp(int l, int r) {
	if (l == r) {
		f[l][r][0][0][0] = f[l][r][1][1][0] = 1;
	} else {
		int minv = calcmin(l, r);
		int lst = l - 1;
		vector<pair<int, int> > vec;
		for (int i = l; i <= r; ++i)
			if (h[i] == minv) {
				if (lst + 1 <= i - 1) vec.push_back(make_pair(lst + 1, i - 1));
				vec.push_back(make_pair(i, i)); lst = i;
			}
		if (lst < r) vec.push_back(make_pair(lst + 1, r));
		for (int i = 0; i < vec.size(); ++i) {
			pair<int, int> e = vec[i];
			dp(e.first, e.second);
			upd(e.first, e.second, calcmin(e.first, e.second) - minv);
			if (i) merge(l, r, e.first, e.second);
			else {
				for (int j = 0; j < 2; ++j)
					for (int k = 0; k < 2; ++k)
						for (int s = 0; s < 2; ++s)
							f[l][r][j][k][s] = f[e.first][e.second][j][k][s];
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &h[i]);
	dp(1, n);
	upd(1, n, calcmin(1, n) - 1);
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				ans = add(ans, f[1][n][i][j][k]);
	printf("%d", ans);
}
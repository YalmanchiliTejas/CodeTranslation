#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
	int H, W; cin >> H >> W;
	string a;
	vector<vector<string>> q(H, vector<string>(W));
	vector<vector<string>> p(H, vector<string>(W));
	vector<vector<string>> ans(H, vector<string>(W));
	int height = 0;
	bool flg = true;
	for (int i = 0; i < H; ++i) {
		cin >> a;
		for (int j = 0; j < a.size(); ++j) {
			q[i][j] = a[j];
		}
		int cnt = 0;
		for (int j = 0; j < a.size(); ++j) {
			if (a[j] == '.') cnt++;	
		}
		if (cnt != W) {
			for (int j = 0; j < a.size(); ++j) {
				p[height][j] = a[j];
			}
			height++;
		}
	}
	int max_height = height;
	int width = 0;
	for (int i = 0; i < W; ++i) {
		int cnt = 0;
		for (int j = 0; j < max_height; ++j) {
			if (p[j][i] == ".") cnt++;
		}
		if (cnt != max_height) {
			for (int j = 0; j < max_height; ++j) {
				ans[j][width] = p[j][i];
			}
			width++;
		}
	}
	int max_width = width;
	if (max_height == 0 && max_width == 0) flg = false;
	if (flg) {
		for (int i = 0; i < max_height; ++i) {
			for (int j = 0; j < max_width; ++j) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	} else {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				cout << q[i][j];
			}
			cout << endl;
		}
	}
	return;
}
int main() {
	solve();
	return 0;
}
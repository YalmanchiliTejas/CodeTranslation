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
	vector<vector<string>> a(H, vector<string>(W));
	vector<int> mark_h, mark_w;
	for (int i = 0; i < H; ++i) {
		string tmp; cin >> tmp;
		for (int j = 0; j < W; ++j) {
			a[i][j] = tmp[j];
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (a[i][j] == "#")  {
				mark_h.push_back(i);
				break;
			}
		}
	}
	for (int i = 0; i < W; ++i) {
		for (auto j : mark_h) {
			if (a[j][i] == "#")  {
				mark_w.push_back(i);
				break;
			}
		}
	}
	for (auto h : mark_h) {
		for (auto w : mark_w) {
			cout << a[h][w];
		}
		cout << endl;
	}
	return;
}
int main() {
	solve();
	return 0;
}
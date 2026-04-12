#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int i = 0; i < H; ++i) {
		cin >> S[i];
	}
	int xl = inf, xr = -inf, yl = inf, yr = -inf;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == 'B') {
				xl = min(xl, i + j);
				xr = max(xr, i + j);
				yl = min(yl, i - j);
				yr = max(yr, i - j);
			}
		}
	}
	cout << max(xr - xl, yr - yl) << endl;
	return 0;
}

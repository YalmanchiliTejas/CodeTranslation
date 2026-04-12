#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) { cin >> a[i]; }

	bool can = true;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (a[i][j] == '.') { continue; }

			int cnt1 = 0;
			if ((i > 0) && (a[i - 1][j] == '#')) { ++cnt1; }
			if ((j > 0) && (a[i][j - 1] == '#')) { ++cnt1; }

			int cnt2 = 0;
			if ((i < H - 1) && (a[i + 1][j] == '#')) { ++cnt2; }
			if ((j < W - 1) && (a[i][j + 1] == '#')) { ++cnt2; }

			if ((i == 0) && (j == 0)) {
				if (cnt2 > 1) { can = false; }
			} else if ((i == H - 1) && (j == W - 1)) {
				if (cnt1 > 1) { can = false; }
			} else {
				if ((cnt1 != 1) || (cnt2 != 1)) { can = false; }
			}
		}
	}

	if (can) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }

	return 0;
}

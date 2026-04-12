#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; ++i) { cin >> s[i]; }

	bool ok = true;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (s[i][j] == '.') { continue; }

			int cnt1 = 0;
			int cnt2 = 0;
			if ((i > 0) && (s[i - 1][j] == '#')) { ++cnt1; }
			if ((j > 0) && (s[i][j - 1] == '#')) { ++cnt1; }
			if ((i < H - 1) && (s[i + 1][j] == '#')) { ++cnt2; }
			if ((j < W - 1) && (s[i][j + 1] == '#')) { ++cnt2; }

			if ((i == 0) && (j == 0)) {
				if (cnt2 > 1) { ok = false; }
			} else if ((i == H - 1) && (j == W - 1)) {
				if (cnt1 > 1) { ok = false; }
			} else {
				if ((cnt1 != 1) || (cnt2 != 1)) { ok = false; }
			}
		}
	}

	if (ok) { cout << "Possible" << endl; }
	else { cout << "Impossible" << endl; }

	return 0;
}

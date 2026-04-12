
// A - Shik and Stone

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

char grid[9][9];

int main() {
	int H, W;
	cin >> H >> W;

	int all_cnt = 0;
	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '#') all_cnt++;
		}
	}

	int r = 0;
	int c = 0;
	int cnt = 0;

	while (1) {
		cnt++;

		if (r == H-1 && c == W-1) break;

		if (grid[r+1][c] == '#') {
			r++;
		} else if (grid[r][c+1] == '#') {
			c++;
		} else {
			break;
		}
	}

	string ans;

	if (cnt == all_cnt) ans = "Possible";
	else ans = "Impossible";

	cout << ans << endl;

	return 0;
}
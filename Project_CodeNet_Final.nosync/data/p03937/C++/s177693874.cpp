#include <bits/stdc++.h>
using namespace std;

int H, W, cnt; char c[10][10];

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) { cin >> c[i][j]; if (c[i][j] == '#') cnt++; }
	}
	if (cnt == H + W - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}

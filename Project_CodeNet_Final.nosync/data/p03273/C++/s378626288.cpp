
// B - Grid Compression

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

char grid[100][100];

int main() {
	int H, W;
	cin >> H >> W;

	for (int i=0; i<H; i++) {
		for (int j=0; j<W; j++) {
			cin >> grid[i][j];
		}
	}

	set<int> i_skip, j_skip;

	for (int i=0; i<H; i++) {
		bool skip = true;
		for (int j=0; j<W; j++) {
			if (grid[i][j] == '#') skip = false;
		}
		if (skip) i_skip.insert(i);
	}

	for (int j=0; j<W; j++) {
		bool skip = true;
		for (int i=0; i<H; i++) {
			if (grid[i][j] == '#') skip = false;
		}
		if (skip) j_skip.insert(j);
	}

	for (int i=0; i<H; i++) {
		if (i_skip.find(i) != i_skip.end()) continue;
		for (int j=0; j<W; j++) {
			if (j_skip.find(j) != j_skip.end()) continue;
			cout << grid[i][j];
		}
		cout << endl;
	}

	return 0;
}
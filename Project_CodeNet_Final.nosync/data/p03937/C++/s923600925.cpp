#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)

int R, C;
vector<string> G;
vector<string> H;

void traverse(int r, int c) {
	H[r][c] = '#';

	int cnt = 0;
	if (r+1 < R && G[r+1][c] == '#') {
		cnt++;
	}
	if (c+1 < C && G[r][c+1] == '#') {
		cnt++;
	}

	if (cnt != 1) {
		return;
	}
	if (r+1 < R && G[r+1][c] == '#') {
		traverse(r+1, c);
	}
	if (c+1 < C && G[r][c+1] == '#') {
		traverse(r, c+1);
	}
}

int main() {
	cin >> R >> C;
	REP(i, R) {
		string c;
		cin >> c;
		G.push_back(c);
		string c2;
		REP(j, C) {
			c2 += ".";
		}
		H.push_back(c2);
	}

	traverse(0, 0);
	cout << (G == H ? "Possible" : "Impossible") << endl;
}

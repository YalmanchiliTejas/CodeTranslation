#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	string S;
	while (cin >> S, S != "#") {
		int W = 0, H = 1;
		bool once = true;
		for (auto c : S) {
			if (c == '/') {
				once = false;
				H++;
			}
			else if (c == 'b') {
				if (once) W++;
			}
			else if (isdigit(c)) {
				if (once) W += c - '0';
			}
		}
		vector<vector<int>> state(H, vector<int>(W));
		int y = 0, x = 0;
		for (auto c : S) {
			if (c == '/') {
				y++;
				x = 0;
			}
			else if (c == 'b') {
				state[y][x++] = 1;
			}
			else if (isdigit(c)) {
				x += c - '0';
			}
		}
		cin >> a >> b >> c >> d;
		state[a - 1][b - 1] = 0;
		state[c - 1][d - 1] = 1;
		for (int i = 0; i < H; i++) {
			int sp = 0;
			for (int j = 0; j < W; j++) {
				if (state[i][j]) {
					if (sp) cout << sp;
					cout << 'b';
					sp = 0;
				}
				else {
					sp++;
				}
			}
			if (sp) cout << sp;
			if (i != H - 1) cout << '/';
		}
		cout << endl;
	}
	return 0;
}
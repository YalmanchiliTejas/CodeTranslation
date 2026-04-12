#include "bits/stdc++.h"
using namespace std;

int e[10][10];
int main() {
	while (true) {
		string s;
		cin >> s;
		if (s == "#") break;
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int x = 0, y = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '/') {
				y++;
				x = 0;
				continue;
			}
			else if (s[i] == 'b') {
				e[y][x] = 1;
				x++;
			}
			else {
				int j = s[i] - '0';
				while (j > 0) {
					e[y][x] = 0;
					x++;
					--j;
				}
			}
		}

		e[a - 1][b - 1] = 0;
		e[c - 1][d - 1] = 1;
		/*cout << x << " " << y << endl;
		for (int i = 0; i <= y; ++i) {
			for (int j = 0; j < x; ++j) {
				cout << e[i][j] << " ";
			}
			cout << endl;
		}*/
		string ans = "";
		for (int i = 0; i <= y; ++i) {
			int con = 0;
			for (int j = 0; j < x; ++j) {
				if (e[i][j] == 1) {
					if(con > 0) ans += con + '0';
					ans += 'b';
					con = 0;
				}
				else {
					con++;
				}
			}
			if(con > 0) ans += con + '0';
			if (i != y) ans += '/';
			//cout << "i;" << i << " " << ans << endl;
		}

		cout << ans << endl;
	}
	return 0;
}
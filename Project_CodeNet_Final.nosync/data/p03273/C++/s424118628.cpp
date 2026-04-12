#include <bits/stdc++.h>

using namespace std;

int H, W;
int n, m;
string s[105];

int main() {
	cin >> H >> W;
	n = 0;
	for (int i = 0; i < H; ++i) {
		cin >> s[n];
		bool flag = true;
		for (int j = 0; j < W; ++j)
			if (s[n][j] == '#') {
				flag = false;
				break;
			}
		if (!flag) n++;
	}
	m = W;
	for (int i = 0; i < m; ++i) {
		bool flag = true;
		for (int j = 0; j < n; ++j)
			if (s[j][i] == '#') {
				flag = false;
				break;
			}
		if (flag) {
			m--;
			for (int j = 0; j < n; ++j)
				s[j].erase(i, 1);
			--i;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << s[i] << endl;
	return 0;
}
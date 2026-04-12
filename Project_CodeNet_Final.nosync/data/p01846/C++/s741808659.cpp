#include <bits/stdc++.h>

using namespace std;

char G[10][10];

int main () {
	string s;
	while (cin >> s, s[0] != '#') {
		s += '/';
		int h = 0, w;
		for (int i = 0; i < s.size (); ++i) {
			w = 0;
			while (s[i] != '/') {
				if (isdigit (s[i])) {
					for (int j = 0; j < s[i] - '0'; ++j)
						G[h][w++] = '.';
				} else G[h][w++] = 'b';
				++i;
			}
			++h;
		}
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		swap (G[a - 1][b - 1], G[c - 1][d - 1]);
		string ans;
		for (int i = 0; i < h; ++i) {
			if (i) ans += '/';
			int cnt = 0;
			for (int j = 0; j < w; ++j) {
				if (G[i][j] == '.') ++cnt;
				else if (cnt) ans += to_string (cnt) + "b", cnt = 0;
				else ans += 'b';
			}
			if (cnt) ans += '0' + cnt;
		}
		cout << ans << endl;
    }

	return 0;
}

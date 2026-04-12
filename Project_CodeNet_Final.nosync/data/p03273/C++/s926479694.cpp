#include <bits/stdc++.h>
typedef long long ll; 

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> s(H);
	for (int i = 0; i < H; i++) {
		cin >> s[i];
	}

	vector<bool> r(H, false);
	vector<bool> c(H, false);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == '#') {
				r[i] = true;
				c[j] = true;
			}
		}
	}

	for (int i = 0; i < H; i++) {
		if (!r[i]) continue;

		for (int j = 0; j < W; j++) {
			if (!c[j]) continue;

			cout << s[i][j];
		}
		cout << endl;
	}

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	char c[h][w];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];
		}
	}
	vector<string> ans;
	for (int i = 0; i < h; i++) {
		bool flag = true;
		for (int j = 0; j < w; j++) {
			if (c[i][j] == '#') flag = false;
		}
		if (!flag)ans.push_back(c[i]);
	}
	bool FLAG[w] = {};
	for (int j = 0; j < w; j++) {
		bool flag = true;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i][j] == '#') flag = false;
		}
		if (!flag) FLAG[j] = true;
	}
	cout << endl;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < w; j++) {
			if (FLAG[j]) cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; i++) {
		cin >> a[i];
	}
	vector<int> r, c;
	for (int i = 0; i < H; i++) {
		if (a[i] != string(W, '.')) r.push_back(i);
	}
	for (int j = 0; j < W; j++) {
		bool ok = false;
		for (int i = 0; i < H; i++) {
			ok |= a[i][j] != '.';
		}
		if (ok) c.push_back(j);
	}
	for (auto i : r) {
		for (auto j : c) {
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}

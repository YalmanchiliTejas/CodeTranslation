#include <bits/stdc++.h>
#include<chrono>
#define ll long long
using namespace std;
ll MOD = 1e9 + 7;
ll A, B, H, N, M, L, K, W, X, Y, Z;
ll ans = 0;
int main() {
	cin >> H >> W;
	vector<vector<char>>a(H, vector<char>(W));
	vector<int>h, w;
	for (int i = 0; i < H; i++) {
		bool flag = 0;
		for (int j = 0; j < W; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				flag = 1;
			}
		}
		if (flag)h.push_back(i);
	}
	for (int j = 0; j < W; j++) {
		bool flag = 0;
		for (int i = 0; i < H; i++) {
			if (a[i][j] == '#') {
				flag = 1; break;
			}
		}
		if (flag)w.push_back(j);
	}
	for (int i : h) {
		for (int j : w) {
			cout << a[i][j];
		}
		cout << endl;
	}
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (int i=0;i<N;i++)

//変数
int H, W;

//解法
void solve() {

	vector<vector<char>> vec(H, vector<char>(W));

	vector<bool> h(H, false), w(W, false);

	rep(i, H) rep(j, W) {
		cin >> vec[i][j];
		if (vec[i][j] == '#') {
			h[i] = true;
			w[j] = true;
		}
	}

	rep(i, H) {
		if (h[i]) {
			rep(j, W) {
				if (w[j]) {
					cout << vec[i][j];
				}
			}
			cout << endl;
		}
	}

	return;
}

int main() {
	//入力
	cin >> H >> W;
	solve();
	//cout << endl;
	return 0;
}

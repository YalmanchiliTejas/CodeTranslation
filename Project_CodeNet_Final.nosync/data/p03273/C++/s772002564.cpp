#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> matrix(H, vector<char>(W));
	rep(i, H) rep(j, W) cin >> matrix[i][j];

	vector<int> remove_h, remove_w;
	rep(i, H) {
		int cnt=0;
		rep(j, W) if (matrix[i][j]=='#') cnt++;
		if (cnt==0) remove_h.push_back(i);
	}
	rep(j, W) {
		int cnt=0;
		rep(i, H) if (matrix[i][j]=='#') cnt++;
		if (cnt==0) remove_w.push_back(j);
	}
	
	if (remove_h.size() || remove_w.size()) {
		rep(i, H) rep(j, W) {
			if (find(ALL(remove_h), i) != remove_h.end()) continue;
			if (find(ALL(remove_w), j) == remove_w.end()) cout << matrix[i][j];
			if (j==W-1) cout << endl;
		}
	} else {
		rep(i, H) rep(j, W) {
			cout << matrix[i][j];
			if (j==W-1) cout << endl;
		}
	}
}
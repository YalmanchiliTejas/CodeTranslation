#include <bits/stdc++.h>

int main(void) {
	using namespace std;
	int H, W;
	cin >> H >> W;
	vector<string> A;
	for(int i = 0; i < H; ++i) {
		string s;
		cin >> s;
		A.push_back(s);
	}
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			for(int k = 0; k < H; ++k) {
				for(int l = 0; l < W; ++l) {
					if(A[i][j] == '#' && A[k][l] == '#' && k < i && j < l) {
						cout << "Impossible\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "Possible\n";
	return 0;
}


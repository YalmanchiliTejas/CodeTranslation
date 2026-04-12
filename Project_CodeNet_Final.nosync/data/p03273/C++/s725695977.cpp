#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	vector<vector<char>> A(H, vector<char>(W, 0));
	map<int, bool> outputH;
	map<int, bool> outputW;
	for (int i = 0; i < H; ++i) {
		bool check = false;
		for (int j = 0; j < W; ++j) {
			char c;
			cin >> c;
			A[i][j] = c;
			if (A[i][j] == '#')check = true;
		}
		if(!check) outputW[i] = 1;
	}
	for (int i = 0; i < W; ++i) {
		bool check = false;
		for (int j = 0; j < H; ++j) {
			if (A[j][i] == '#')check = true;
		}
		if(!check) outputH[i] = 1;
	}


	for (int i = 0; i < H; ++i) {
		if (outputW[i] == 1)continue;
		for (int j = 0; j < W; ++j) {
			if (outputH[j] == 1) {
				continue;
			}
			cout << A[i][j];
			
		}
		cout << endl;
	}

	return 0;
}
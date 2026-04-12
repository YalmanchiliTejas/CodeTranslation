#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <functional>
using namespace std;

int H, W; char c[200][200]; vector<int>A, B;

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> c[i][j];
	}
	for (int i = 0; i < H; i++) {
		int cnt = 0;
		for (int j = 0; j < W; j++) { if (c[i][j] == '#') cnt++; }
		if (cnt != 0) A.push_back(i);
	}
	for (int i = 0; i < W; i++) {
		int cnt = 0;
		for (int j = 0; j < H; j++) { if (c[j][i] == '#') cnt++; }
		if (cnt != 0) B.push_back(i);
	}
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) cout << c[A[i]][B[j]]; cout << endl;
	}
	return 0;
}
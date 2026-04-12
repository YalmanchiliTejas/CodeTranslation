#include<iostream>
#include<string>
using namespace std;
int main() {
	int H, W;
	cin >> H >> W;
    char S[101][101];
	int A[101];
	int B[101];
	for (int i = 0; i < 101; ++i) {
		A[i] = 0;
		B[i] = 0;
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> S[i][j];
			if (S[i][j] == '#') {
				A[i] = 1;
				B[j] = 1;
			}
		}
	}
	for (int i = 0; i < H; ++i) {
		if (A[i]) {
			for (int j = 0; j < W; ++j) {
				if (B[j]) {
					cout << S[i][j];
				}
			}
			cout << endl;
		}
	}
	return 0;
}
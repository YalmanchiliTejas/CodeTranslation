#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W;
	bool h[100] = { false }, w[100] = { false };
	cin >> H >> W;
	string S[100];
	for (int i = 0; i < H; i++) {
		cin >> S[i];
		for (int j = 0; j < W; j++) {
			if (S[i][j] == '#') h[i] = true, w[j] = true;
		}
	}
	for (int i = 0; i < H; i++) {
		if (h[i]) {
			for (int j = 0; j < W; j++) {
				if (w[j]) {
					cout << S[i][j];
				}
			}
			cout << endl;
		}
	}
}
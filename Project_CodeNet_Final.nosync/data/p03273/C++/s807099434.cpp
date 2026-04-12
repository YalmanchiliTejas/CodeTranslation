#include<iostream>
using namespace std;
int main() {
	int H, W; cin >> H >> W;
	char c[100][100];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> c[i][j];
	}
	bool blackH[100];
	bool blackW[100];
	for (int i = 0; i < H; i++)
		blackH[i] = false;
	for (int i = 0; i < W; i++)
		blackW[i] = false;

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			if (c[j][i] == '#') {
				blackW[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (c[i][j] == '#') {
				blackH[i] = true;
				break;
			}
		}
	}
	
	for (int i = 0; i < H; i++) {
		if (blackH[i]) {
			for (int j = 0; j < W; j++) {
				if (blackW[j])
					cout << c[i][j];
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}

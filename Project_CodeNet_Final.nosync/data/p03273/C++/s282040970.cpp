#include <iostream>
#include <stdio.h>
using namespace std;

int main(void) {
	int H1, W1;
	int H2 = 0, W2 = 0;
	int H3 = 0, W3 = 0;
	string a1[100];
	string a2[100];
	char a3[100][100];

	scanf("%d %d", &H1, &W1);
	W2 = W1;
	for (int i = 0; i < H1; i++) {
		cin >> a1[i];
	}

	// 横を消す
	for (int i = 0; i < H1; i++) {
		bool sFlag = false;
		for (int j = 0; j < W1; j++) {
			if (a1[i][j] == '#') {
				sFlag = true;
				break;
			}
		}
		if (sFlag == true) {
			a2[H2] = a1[i];
			H2++;
		}
	}

	// 縦を消す
	H3 = H2;
	for (int j = 0; j < W2; j++) {
		bool sFlag = false;
		for (int i = 0; i < H2; i++) {
			if (a2[i][j] == '#') {
				sFlag = true;
				break;
			}
		}
		if (sFlag == true) {
			for (int i = 0; i < H2; i++) {
				a3[i][W3] = a2[i][j];
			}
			W3++;
		}
	}

	for (int i = 0; i < H3; i++) {
		for (int j = 0; j < W3; j++) {
			cout << a3[i][j];
		}
		cout << endl;
	}

	return 0;
}

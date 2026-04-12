#include <iostream>
#include <string>

using namespace std;

string s[102];

int C[102], R[102];

int H, W;

int main(void) {
	cin >> H >> W;
	string tmp;

	for (int i = 1; i <= H; i++) {
		cin >> tmp;
		s[i] = "%" + tmp;
	}

	for (int i = 1; i <= H; i++) {
		int sign = 0;
		for (int j = 1; j <= W; j++) {
			if (s[i][j] == '#') { sign = 1; }
		}
		if (sign == 0) { C[i] = 1; }
	}

	for (int j = 1; j <= W; j++) {
		int sign = 0;
		for (int i = 1; i <= H; i++) {
			if (s[i][j] == '#') { sign = 1; }
		}
		if (sign == 0) { R[j] = 1; }
	}

	/*for (int i = 1; i <= W; i++) {
		cout << R[i] << endl;
	}*/

	for (int i = 1; i <= H; i++) {
		if (C[i] == 1) { continue; }
		for (int j = 1; j <= W; j++) {
			if (R[j] == 0) { cout << s[i][j]; }
		}
		cout << endl;
	}

	//system("pause");
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		string c;
		int dice[3][4]  = {{0, 5, 0, 0},
						   {4, 1, 3, 6},
						   {0, 2, 0, 0}};
		int kari;
		int sum = 1;
		for (int i = 0; i < n; i++) {
			cin >> c;
			if (c == "North") {
				kari = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = dice[1][3];
				dice[1][3] = kari;
				sum += dice[1][1];
			} else if (c == "South") {
				kari = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = dice[1][3];
				dice[1][3] = kari;
				sum += dice[1][1];
			} else if (c == "West") {
				kari = dice[1][0];
				for (int i = 0; i < 3; i++) {
					dice[1][i] = dice[1][i+1];
				}
				dice[1][3] = kari;
				sum += dice[1][1];
			} else if (c == "East") {
				kari = dice[1][3];
				for (int i = 3; i > 0; i--) {
					dice[1][i] = dice[1][i-1];
				}
				dice[1][0] = kari;
				sum += dice[1][1];
			} else if (c == "Right") {
				kari = dice[2][1];
				dice[2][1] = dice[1][2];
				dice[1][2] = dice[0][1];
				dice[0][1] = dice[1][0];
				dice[1][0] = kari;
				sum += dice[1][1];
			} else {
				kari = dice[2][1];
				dice[2][1] = dice[1][0];
				dice[1][0] = dice[0][1];
				dice[0][1] = dice[1][2];
				dice[1][2] = kari;
				sum += dice[1][1];
			}
		}
		cout << sum << endl;
	}
	return 0;
}
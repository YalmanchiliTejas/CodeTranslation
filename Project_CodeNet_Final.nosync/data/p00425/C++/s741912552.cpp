#include <iostream>
using namespace std;

int main()
{
	int n;
	string str;
	while (cin >> n, n) {
		int dice[] = { 1, 2, 3, 4, 5, 6 };
		int cd[6];
		int res = dice[0];
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (str == "North") {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[0] = cd[1];
				dice[1] = cd[5];
				dice[5] = cd[4];
				dice[4] = cd[0];
				res += dice[0];
			}
			else if (str == "East") {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[0] = cd[3];
				dice[3] = cd[5];
				dice[5] = cd[2];
				dice[2] = cd[0];
				res += dice[0];
			}
			else if (str == "West") {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[0] = cd[2];
				dice[2] = cd[5];
				dice[5] = cd[3];
				dice[3] = cd[0];
				res += dice[0];
			}
			else if (str == "South") {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[0] = cd[4];
				dice[4] = cd[5];
				dice[5] = cd[1];
				dice[1] = cd[0];
				res += dice[0];
			}
			else if (str == "Right") {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[1] = cd[2];
				dice[2] = cd[4];
				dice[4] = cd[3];
				dice[3] = cd[1];
				res += dice[0];
			}
			else {
				for (int j = 0; j < 6; j++) {
					cd[j] = dice[j];
				}
				dice[1] = cd[3];
				dice[3] = cd[4];
				dice[4] = cd[2];
				dice[2] = cd[1];
				res += dice[0];
			}
		}
		cout << res << endl;
	}
	return 0;
}
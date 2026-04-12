#include <iostream>
#include <string>

using namespace std;

void swapDice(int* dice, int* ret) {
	for (int i = 0; i < 6; i++) {
		dice[i] = ret[i];
	}
}

void insertDice(int* dice, int up, int south, int east, int west, int north, int down) {
	dice[0] = up;
	dice[1] = south;
	dice[2] = east;
	dice[3] = west;
	dice[4] = north;
	dice[5] = down;
}

int main(void) {
	int n = 0;
	while (cin >> n && n != 0) {
		int dice[] = {1, 2, 3, 4, 5, 6};
		int count = 1;
		for (int i = 0; i < n; i++) {
			string command;
			cin >> command;
			int ret[6];
			if (command.find("North") != string::npos) {
				insertDice(ret, dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]);
			} else if (command.find("East") != string::npos) {
				insertDice(ret, dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]);
			} else if (command.find("West") != string::npos) {
				insertDice(ret, dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]);
			} else if (command.find("South") != string::npos) {
				insertDice(ret, dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]);
			} else if (command.find("Right") != string::npos) {
				insertDice(ret, dice[0], dice[2], dice[4], dice[1], dice[3], dice[5]);
			} else if (command.find("Left") != string::npos) {
				insertDice(ret, dice[0], dice[3], dice[1], dice[4], dice[2], dice[5]);
			}
			swapDice(dice, ret);
			count += dice[0];
		}
		cout << count << endl;
	}
}
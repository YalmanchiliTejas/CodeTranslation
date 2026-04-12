#include <bits/stdc++.h>

using namespace std;

const int NSDirection[4] = { 1,2,6,5 };
const int EWDirection[4] = { 1,4,6,3 };
const int RLDirection[4] = { 3,5,4,2 };
int Dice[] = { 0,1,2,3,4,5,6 };

void change(int p1, int p2, int p3, int p4) {
	int tmp;

	tmp = Dice[p1];
	Dice[p1] = Dice[p2];
	Dice[p2] = Dice[p3];
	Dice[p3] = Dice[p4];
	Dice[p4] = tmp;
}

int main() {
	int n, sum;
	string dir;
	
	while (cin >> n, n) {
		sum = 1;
		for (int i = 0; i < n; ++i) {
			cin >> dir;
			switch (dir[0]) {
				case 'N':change(1, 2, 6, 5); break;
				case 'S':change(1, 5, 6, 2); break;
				case 'E':change(1, 4, 6, 3); break;
				case 'W':change(1, 3, 6, 4); break;
				case 'R':change(3, 5, 4, 2); break;
				case 'L':change(3, 2, 4, 5); break;
				default:break;
			}
			sum += Dice[1];
		}
		cout << sum << endl;
		for (int i = 0; i < 7; ++i) {
			Dice[i] = i;
		}
	}
	
	return 0;
}

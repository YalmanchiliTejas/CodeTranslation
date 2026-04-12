#include<iostream>
#include<string>
using namespace std;

int main() {
	int n, sum;
	int up = 1, down = 6, right = 3, left = 4, front = 2, back = 5;
	string action;

	while (1) {
		cin >> n;
		if (n == 0) break;

		up = 1;
		down = 6;
		right = 3;
		left = 4;
		front = 2;
		back = 5;

		sum = 1;

		for (int i = 0; i < n; i++) {
			cin >> action;

			if (action == "North") {
				back = up;
				up = front;
				front = down;
				down = 7 - up;
			}
			else if (action == "East") {
				right = up;
				up = left;
				left = down;
				down = 7 - up;
			}
			else if (action == "West") {
				left = up;
				up = right;
				right = down;
				down = 7 - up;
			}
			else if (action == "South") {
				front = up;
				up = back;
				back = down;
				down = 7 - up;
			}
			else if (action == "Right") {
				left = front;
				front = right;
				right = back;
				back = 7 - front;
			}
			else if (action == "Left") {
				right = front;
				front = left;
				left = back;
				back = 7 - front;
			}

			sum += up;

		}

		cout << sum << endl;

	}
	return 0;
}

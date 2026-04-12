#include<iostream>
#include<string>
#include<vector>
using namespace std;
class dice {
	int a;
public:
	void North(int *up, int *back, int *right, int *left, int *front, int *under) {
		int a;
		a = *up;
		*up = *back;
		*back = *under;
		*under = *front;
		*front = a;
	}
	void East(int *up, int *back, int *right, int *left, int *front, int *under) {
		a = *up;
		*up = *left;
		*left = *under;
		*under = *right;
		*right = a;
	}
	void West(int *up, int *back, int *right, int *left, int *front, int *under) {
		a = *up;
		*up = *right;
		*right = *under;
		*under = *left;
		*left = a;
	}
	void South(int *up, int *back, int *right, int *left, int *front, int *under) {
		a = *up;
		*up = *front;
		*front = *under;
		*under = *back;
		*back = a;
	}
	void Right(int *up, int *back, int *right, int *left, int *front, int *under) {
		a = *front;
		*front = *left;
		*left = *back;
		*back = *right;
		*right = a;
	}
	void Left(int *up, int *back, int *right, int *left, int *front, int *under) {
		a = *front;
		*front = *right;
		*right = *back;
		*back = *left;
		*left = a;

	}

};
int main() {
	int up = 1, back = 2, right = 3, left = 4, front = 5, under = 6;
	dice die;
	int n, sum ;
	string str;
	while (1) {
		cin >> n;
		if (n == 0) { break; }
		sum = 1;
		up = 1; back = 2; right = 3; left = 4; front = 5; under = 6;
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (str == "North") {
				die.North(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
			else if (str == "East") {
				die.East(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
			else if (str == "West") {
				die.West(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
			else if (str == "South") {
				die.South(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
			else if (str == "Right") {
				die.Right(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
			else if (str == "Left") {
				die.Left(&up, &back, &right, &left, &front, &under);
				sum += up;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
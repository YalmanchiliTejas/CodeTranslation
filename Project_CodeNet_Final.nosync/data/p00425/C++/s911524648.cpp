#include<iostream>
#include<string>
#include<array>


typedef std::array<int, 6> Dice;

enum Direction {
	Top,
	Bottom,
	North,
	South,
	East,
	West
};

typedef std::array<Direction, 4> RotateDirection;

const RotateDirection north = { {Top, North, Bottom, South } };
const RotateDirection east = { { Top, East, Bottom, West} };
const RotateDirection south = { { Top, South, Bottom, North } };
const RotateDirection west = { { Top, West, Bottom, East } };
const RotateDirection right = { { North, East, South, West } };
const RotateDirection left = { { North, West, South, East } };


void RotateDice(Dice& dice , const RotateDirection& direction) {
	int temp = dice[direction[3]];
	dice[direction[3]] = dice[direction[2]];
	dice[direction[2]] = dice[direction[1]];
	dice[direction[1]] = dice[direction[0]];
	dice[direction[0]] = temp;
}


int main() {

	int n;


	while (true) {
		std::cin >> n;
		if (n == 0) {
			break;
		}

		int sum = 1;
		Dice dice{ { 1, 6, 5, 2, 3, 4 } };

		for (int i = 0; i < n; ++i) {
			std::string dir;
			std::cin >> dir;
			if (dir == "North") {
				RotateDice(dice, north);
			}
			else if (dir == "East") {
				RotateDice(dice, east);
			}
			else if (dir == "West") {
				RotateDice(dice, west);
			}
			else if (dir == "South") {
				RotateDice(dice, south);
			}
			else if (dir == "Right") {
				RotateDice(dice, right);
			}
			else if (dir == "Left") {
				RotateDice(dice, left);
			}
			using std::cout;
			sum += dice[Top];
		}
		std::cout << sum << std::endl;
	}
	return 0;
}
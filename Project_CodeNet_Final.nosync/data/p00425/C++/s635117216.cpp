#include <iostream>
#include <cstring>
#include <map>


/*
 *    1
 * 2, 3, 5, 4
 *    6
 */

class Dice {

	public:
		enum CONSTS {
			NORTH = 0,
			EAST,
			SOUTH,
			WEST,
			RIGHT,
			LEFT,
			NUMOFROLL,

			N = 6,
		};
	private:

		static const int rollType[N][NUMOFROLL];
		static const std::map<std::string, int> rollMap;

		int _dice[N];

	public:
		Dice() : _dice{1, 2, 3, 5, 4, 6} {}
		
		int Roll(std::string type) { return Roll(rollMap.at(type)); }
		int Roll(CONSTS type) { return Roll(static_cast<int>(type)); }
		int Roll(int type) {
			if (type < 0 || static_cast<int>(NUMOFROLL) <= type) return -1;

			int d[N];
			std::memcpy(d, _dice, sizeof(int) * N);

			for (int i = 0; i < N; ++i) _dice[i] = d[rollType[type][i]];

			return _dice[0];
		}

};

const int Dice::rollType[Dice::N][Dice::NUMOFROLL] = {
	{1, 5, 2, 0, 4, 3},
	{4, 1, 0, 3, 5, 2},
	{3, 0, 2, 5, 4, 1},
	{2, 1, 5, 3, 0, 4},
	{0, 2, 3, 4, 1, 5},
	{0, 4, 1, 2, 3, 5},
};
const std::map<std::string, int> Dice::rollMap = {
	{"North", 0},
	{"East", 1},
	{"South", 2},
	{"West", 3},
	{"Right", 4},
	{"Left", 5},
};



int main() {

	for (int n; std::cin >> n, n > 0;) {
		Dice dice;
		int sum = 1;
		while (n--) {
			std::string str;
			std::cin >> str;

			sum += dice.Roll(str);
		}
		std::cout << sum << std::endl;
	}


	return 0;
}
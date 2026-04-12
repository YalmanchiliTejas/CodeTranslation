#include <map>
#include <array>
#include <string>
#include <iostream>

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::array;
using std::string;

using dice_t = array<int,6>;
using order_t = array<int,4>;

void turn(dice_t &dice,order_t i) {
	int tmp = dice[i[0]];
	dice[i[0]] = dice[i[1]];
	dice[i[1]] = dice[i[2]];
	dice[i[2]] = dice[i[3]];
	dice[i[3]] = tmp;
}

int main() {
	map<string,order_t> oper {
		{"North",{0,1,5,4}},
		{"South",{0,4,5,1}},
		{"East",{0,3,5,2}},
		{"West",{0,2,5,3}},
		{"Left",{1,3,4,2}},
		{"Right",{1,2,4,3}}
	};
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin.ignore();
		dice_t dice = {1,2,3,4,5,6};
		int sum = 1;
		while (n--) {
			string dir;
			cin >> dir;
			turn(dice,oper[dir]);
			sum += dice[0];
		}
		cout << sum << endl;
	}
}
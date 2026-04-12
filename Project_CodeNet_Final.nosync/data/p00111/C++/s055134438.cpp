#include<iostream>
#include<string>
#include<map>
#include<algorithm>

std::map<char, std::string> map;
const char before[32] = {
	' ', '\'', ',', '-', '.', '?',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
	'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
	'Y', 'Z'
};
const std::string after[32] = {
	"101", "000000", "000011", "10010001", "010001", "000001",
	"100101", "10011010", "0101", "0001", "110", "01001", "10011011", "010000",
	"0111", "10011000", "0110", "00100", "10011001", "10011110", "00101", "111",
	"10011111", "1000", "00110", "00111", "10011100", "10011101", "000010",
	"10010010", "10010011", "10010000"
};

void Initialize() {
	map.insert(std::make_pair('A', "00000"));
	map.insert(std::make_pair('B', "00001"));
	map.insert(std::make_pair('C', "00010"));
	map.insert(std::make_pair('D', "00011"));
	map.insert(std::make_pair('E', "00100"));
	map.insert(std::make_pair('F', "00101"));
	map.insert(std::make_pair('G', "00110"));
	map.insert(std::make_pair('H', "00111"));
	map.insert(std::make_pair('I', "01000"));
	map.insert(std::make_pair('J', "01001"));
	map.insert(std::make_pair('K', "01010"));
	map.insert(std::make_pair('L', "01011"));
	map.insert(std::make_pair('M', "01100"));
	map.insert(std::make_pair('N', "01101"));
	map.insert(std::make_pair('O', "01110"));
	map.insert(std::make_pair('P', "01111"));
	map.insert(std::make_pair('Q', "10000"));
	map.insert(std::make_pair('R', "10001"));
	map.insert(std::make_pair('S', "10010"));
	map.insert(std::make_pair('T', "10011"));
	map.insert(std::make_pair('U', "10100"));
	map.insert(std::make_pair('V', "10101"));
	map.insert(std::make_pair('W', "10110"));
	map.insert(std::make_pair('X', "10111"));
	map.insert(std::make_pair('Y', "11000"));
	map.insert(std::make_pair('Z', "11001"));
	map.insert(std::make_pair(' ', "11010"));
	map.insert(std::make_pair('.', "11011"));
	map.insert(std::make_pair(',', "11100"));
	map.insert(std::make_pair('-', "11101"));
	map.insert(std::make_pair('\'', "11110"));
	map.insert(std::make_pair('?', "11111"));
}

int main(){

	Initialize();

	std::string bestr;

	while (std::getline(std::cin, bestr)){

		std::string afstr, res;

		for (int i = 0; i < bestr.size(); i++){
			afstr += map[bestr[i]];
		}

		std::string check;
		for (int i = 0; i < afstr.size(); i++){
			check += afstr[i];

			int it = std::find(&(after[0]), &(after[32]), check) - after;
			if (it != 32){
				res += before[it];
				check.clear();
			}

		}

		std::cout << res << std::endl;

	}
	return 0;
}
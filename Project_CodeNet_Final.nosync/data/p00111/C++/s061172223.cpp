#include <iostream>
#include <map>
#include <cstring>
using namespace std;
#define mk make_pair

int main(){
	map<char, string> former;
	former['A'] = "00000";
	former['B'] = "00001";
	former['C'] = "00010";
	former['D'] = "00011";
	former['E'] = "00100";
	former['F'] = "00101";
	former['G'] = "00110";
	former['H'] = "00111";
	former['I'] = "01000";
	former['J'] = "01001";
	former['K'] = "01010";
	former['L'] = "01011";
	former['M'] = "01100";
	former['N'] = "01101";
	former['O'] = "01110";
	former['P'] = "01111";
	former['Q'] = "10000";
	former['R'] = "10001";
	former['S'] = "10010";
	former['T'] = "10011";
	former['U'] = "10100";
	former['V'] = "10101";
	former['W'] = "10110";
	former['X'] = "10111";
	former['Y'] = "11000";
	former['Z'] = "11001";
	former[' '] = "11010";
	former['.'] = "11011";
	former[','] = "11100";
	former['-'] = "11101";
	former['\''] = "11110";
	former['?'] = "11111";

	map<string, char> later;
	later["101"] 		= ' ';
	later["000000"] = '\'';
	later["000011"] = ',';
	later["10010001"] = '-';
	later["010001"] = '.';
	later["000001"] = '?';
	later["100101"] = 'A';
	later["10011010"] = 'B';
	later["0101"] = 'C';
	later["0001"] = 'D';
	later["110"] = 'E';
	later["01001"] = 'F';
	later["10011011"] = 'G';
	later["010000"] = 'H';
	later["0111"] = 'I';
	later["10011000"] = 'J';
	later["0110"] = 'K';
	later["00100"] = 'L';
	later["10011001"] = 'M';
	later["10011110"] = 'N';
	later["00101"] = 'O';
	later["111"] = 'P';
	later["10011111"] = 'Q';
	later["1000"] = 'R';
	later["00110"] = 'S';
	later["00111"] = 'T';
	later["10011100"]= 'U';
	later["10011101"] = 'V';
	later["000010"] = 'W';
	later["10010010"] = 'X';
	later["10010011"] = 'Y';
	later["10010000"] = 'Z';

	string s;
	while( getline(cin, s) ){
		string ans = "";
		for( int i = 0; i < s.size(); i++ ){
			ans += former[s[i]];
		}

		s = ans;
		ans = "";
		for( int i = 0; i < s.size(); i++ ){
			for( int j = 1; i+j <= s.size(); j++ ){
				if( later.find(s.substr(i,j)) == later.end() ) continue;
				ans += later[s.substr(i,j)];
				i = i+j-1;
				break;
			}
		}
		cout << ans << endl;
	}
}
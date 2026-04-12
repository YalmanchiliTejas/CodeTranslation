#include <string>
#include <vector>
#include <iostream>
using namespace std;
string e = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
vector<string> s1 = {
	"100101", "10011010", "0101", "0001", "110",
	"01001", "10011011", "010000", "0111", "10011000",
	"0110", "00100", "10011001", "10011110", "00101",
	"111", "10011111", "1000", "00110", "00111",
	"10011100", "10011101", "000010", "10010010", "10010011",
	"10010000", "101", "010001", "000011", "10010001",
	"000000", "000001"
};
vector<string> s2 = {
	"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", "01000", "01001",
	"01010", "01011", "01100", "01101", "01110", "01111", "10000", "10001", "10010", "10011",
	"10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101",
	"11110", "11111"
};
string s;
int main() {
	while (s = "", getline(cin, s)) {
		string t;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < e.size(); j++) {
				if (s[i] == e[j]) t += s2[j];
			}
		}
		string ret = "";
		for (int i = 0; i < t.size();) {
			bool flag = false;
			for (int j = 0; j < e.size(); j++) {
				if (t.substr(i, s1[j].size()) == s1[j]) {
					ret += e[j]; i += s1[j].size(); flag = true;
					break;
				}
			}
			if (!flag) break;
		}
		cout << ret << endl;
	}
	return 0;
}
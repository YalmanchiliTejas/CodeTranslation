#include <iostream>
#include <string>

using namespace std;

int main() {
	string b;
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	string kazu = "01";
	while (getline(cin, b)) {
		string c;
		for (int i = 0; i < b.size(); i++) {
			int k;
			string a;
			for (int j = 0; j < abc.size(); j++) {
				if (b[i] == abc[j]) {
					k = j;
					break;
				}
			}
			a = kazu[k%2];
			k /= 2;
			a += kazu[k%2];
			k /= 2;
			a += kazu[k%2];
			k /= 2;
			a += kazu[k%2];
			k /= 2;
			a += kazu[k%2];
			for (int j = 4; j >= 0; j--) {
				if (i == 0 && j == 4) {
					c = a[j];
				} else {
					c += a[j];
				}
			}
		}
		while (true) {
			if (c.substr(0, 3) == "101") {
				cout << ' ';
				c = c.substr(3);
			} else if (c.substr(0, 3) == "110") {
				cout << 'E';
				c = c.substr(3);
			} else if (c.substr(0, 3) == "111") {
				cout << 'P';
				c = c.substr(3);
			} else if (c.substr(0, 4) == "0101") {
				cout << 'C';
				c = c.substr(4);
			} else if (c.substr(0, 4) == "0001") {
				cout << 'D';
				c = c.substr(4);
			} else if (c.substr(0, 4) == "0111") {
				cout << 'I';
				c = c.substr(4);
			} else if (c.substr(0, 4) == "0110"){
				cout << 'K';
				c = c.substr(4);
			} else if (c.substr(0, 4) == "1000"){
				cout << 'R';
				c = c.substr(4);
			} else if (c.substr(0, 5) == "01001"){
				cout << 'F';
				c = c.substr(5);
			} else if (c.substr(0, 5) == "00100"){
				cout << 'L';
				c = c.substr(5);
			} else if (c.substr(0, 5) == "00101") {
				cout << 'O';
				c = c.substr(5);
			} else if (c.substr(0, 5) == "00110"){
				cout << 'S';
				c = c.substr(5);
			} else if (c.substr(0, 5) == "00111") {
				cout << 'T';
				c = c.substr(5);
			} else if (c.substr(0, 6) == "000000") {
				cout << "'";
				c = c.substr(6);
			} else if (c.substr(0, 6) == "000011"){
				cout << ',';
				c = c.substr(6);
			} else if (c.substr(0, 6) == "010001"){
				cout << '.';
				c = c.substr(6);
			} else if (c.substr(0, 6) == "000001") {
				cout << '?';
				c = c.substr(6);
			} else if (c.substr(0, 6) == "100101") {
				cout << 'A';
				c = c.substr(6);
			} else if (c.substr(0, 6) == "010000") {
				cout << 'H';
				c = c.substr(6);
			} else if (c.substr(0, 6) == "000010") {
				cout << 'W';
				c = c.substr(6);
			} else if (c.substr(0, 8) == "10010001") {
				cout << '-';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011010") {
				cout << 'B';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011011") {
				cout << 'G';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011000") {
				cout << 'J';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011001") {
				cout << 'M';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011110") {
				cout << 'N';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011111") {
				cout << 'Q';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011100") {
				cout << 'U';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10011101") {
				cout << 'V';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10010010") {
				cout << 'X';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10010011") {
				cout << 'Y';
				c = c.substr(8);
			} else if (c.substr(0, 8) == "10010000") {
				cout << 'Z';
				c = c.substr(8);
			} else {
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
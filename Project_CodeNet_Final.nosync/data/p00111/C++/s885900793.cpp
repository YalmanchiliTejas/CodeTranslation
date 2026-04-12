#include <iostream>
#include <string>
using namespace std;
#define rep2(x,from,to) for(int x=(from);x<(to);++(x))
#define rep(x,to) rep2(x,0,to)

int main() {
	string code[32] = {"00000", "00001", "00010", "00011", "00100", "00101", "00110", "00111", 
				   "01000", "01001", "01010", "01011", "01100", "01101", "01110", "01111",
				   "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111",
				   "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111"};
	string decode[32] = {"101", "000000", "000011", "10010001", "010001", "000001", "100101", "10011010",
					"0101", "0001", "110", "01001", "10011011", "010000", "0111", "10011000",
					"0110", "00100", "10011001", "10011110", "00101", "111", "10011111", "1000",
					"00110", "00111", "10011100", "10011101", "000010", "10010010", "10010011", "10010000"};
	char ch[6] = {' ', '.', ',', '-', '\'', '?'};
	char hc[6] = {' ', '\'', ',', '-', '.', '?'};
	string str;
	while(getline(cin, str)) {
		const char *c = str.c_str();
		string ret;
		for(int i = 0; c[i] != '\0'; i++) {
			if(isalpha(c[i])) {
				int a = c[i] - 'A';
				ret += code[a];
			} else {
				rep(j,6) {
					if(c[i] == ch[j]) ret+= code[26+j];
				}
			}
		}
		int len = ret.length();
		int i = 0;
		string ans;
		while(len > i) {
			bool f = 1;
			rep(j,32) {
				f = 1;
				rep(k,decode[j].length()) {
					if(decode[j][k] != ret[i+k]) {
						f = 0;
						break;
					}
				}
				if(f) {
					if(j < 6) ans += hc[j];
					else ans += (char)('A'+j-6);
					i += decode[j].length();
					break;
				}
			}
			if(!f) break;
		}
		cout << ans << endl;
	}
	return 0;
}
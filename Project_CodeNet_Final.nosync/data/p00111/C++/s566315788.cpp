#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<functional>
#include<queue>
using namespace std;

unordered_map<string, char>U;
string x[] = {
"101",
"000000",
"000011",
"10010001",
"010001",
"000001",
"100101",
"10011010",
"0101",
"0001",
"110",
"01001",
"10011011",
"010000",
"0111",
"10011000",
"0110",
"00100",
"10011001",
"10011110",
"00101",
"111",
"10011111",
"1000",
"00110",
"00111",
"10011100",
"10011101",
"000010",
"10010010",
"10010011",
"10010000"
};
string y = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
	for (int i = 0; i < y.length(); i++) {
		U[x[i]] = y[i];
	}
	string a;
	while (getline(cin, a)) {
		string b;
		for (char c : a) {
			int d = 0;
			switch (c) {
			case ' ':d = 26; break;
			case '.':d = 27; break;
			case ',':d = 28; break;
			case '-':d = 29; break;
			case '\'':d = 30; break;
			case '?':d = 31; break;
			default:d = c - 'A';
			}
			for (int i = 4; i >= 0; i--) {
				if (d&(1 << i))b += "1";
				else b += "0";
			}
		}
		int now = 0;
		b += "#########################################################################################";
		for (int i = 0; i < 100; i++) {
			for (int j = 3; j < 10; j++) {
				if (U[b.substr(now, j)] != 0) {
					cout << U[b.substr(now, j)];
					now += j;
					break;
				}
			}
		}
		puts("");
	}
}
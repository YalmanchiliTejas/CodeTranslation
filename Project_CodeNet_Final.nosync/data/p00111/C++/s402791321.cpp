#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
map<char, int> word;
string eng = " \',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string to_b(int a) {
	string ret;
	for(int i = 0; i < 5; i++) {
		ret += (bool)(a & 1 << (4 - i)) + '0';
	}
	return ret;
}
int main() {
	for(int i = 'A'; i <= 'Z'; i++) {
		word[i] = i - 'A';
	}
	word[' '] = 26;
	word['.'] = 27;
	word[','] = 28;
	word['-'] = 29;
	word['\''] = 30;
	word['?'] = 31;
	string f[32] = {
		"101", "000000", "000011", "10010001", "010001", "000001","100101",
		"10011010", "0101", "0001", "110", "01001", "10011011", "010000",
		"0111", "10011000", "0110", "00100", "10011001", "10011110", "00101",
		"111", "10011111", "1000", "00110", "00111", "10011100", "10011101",
		"000010", "10010010", "10010011", "10010000"
	};
	string str;
	while(getline(cin,str)) {
		string ret,ans;
		for(int i = 0; i < str.size(); i++) {
			ret += to_b(word[str[i]]);
		}
		for(int j = 3; j < 9; j++) {
			for(int i = 0; i < 32; i++) {
				if(f[i].size() != j) continue;
				if(ret.substr(0, j) != f[i]) continue;
				ret = ret.substr(j);
				ans += eng[i];
				j = 2;
				i = -1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
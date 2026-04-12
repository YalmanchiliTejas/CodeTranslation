#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string index[] = {
	"11010", "11011",
	"11100", "11101",
	"11110", "11111"
};

string code(char c){
	int i = (int)c - 'A';
	if(i >= 0 && i < 26){
		string s;
		for(int j = 16; j >= 1; j = j / 2){
			if(i / j){
				i = i - j;
				s.push_back('1');
			}else{
				s.push_back('0');
			}
		}
		return s;
	}else{
		if(c == ' ') return index[0];
		if(c == '.') return index[1];
		if(c == ',') return index[2];
		if(c == '-') return index[3];
		if(c == '\'') return index[4];
		if(c == '?') return index[5];
	}
}

int main(){
	const string nums[] = {
		"101", "000000",
		"000011", "10010001",
		"010001", "000001",
		"100101", "10011010",
		"0101", "0001",
		"110", "01001", "10011011",
		"010000", "0111",
		"10011000", "0110",
		"00100", "10011001",
		"10011110", "00101",
		"111", "10011111",
		"1000", "00110",
		"00111", "10011100",
		"10011101", "000010",
		"10010010", "10010011",
		"10010000"
	};

	const char chs[] = {
		' ', '\'', ',',
		'-', '.', '?',
		'A', 'B', 'C',
		'D', 'E', 'F', 'G',
		'H', 'I', 'J', 'K',
		'L', 'M', 'N', 'O',
		'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W',
		'X', 'Y', 'Z'
	};
	const string z = "0000";

	string s;
	while(getline(cin, s)){
		string v;
		for(string::iterator iter = s.begin();
			iter != s.end(); iter++)
		{
			v += code(*iter);
		}
		string::iterator iter = v.begin();
		string::iterator iter2 = iter;
		while(iter != v.end()){
			if(search(z.begin(), z.end(), iter, v.end()) != z.end()) break;
			int i = 0;
			string s2(iter, iter2);
			while(s2 != nums[i]){
				i++;
				if(i == 32) break;
			}
			if(i == 32) iter2++;
			else{
				iter = iter2;
				cout << chs[i];
			}
		}
		cout << endl;
	}
	return 0;
}
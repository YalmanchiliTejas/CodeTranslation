#include <iostream>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<string, string> P;

int main() {
	map<char, string> tr1;

	tr1['A'] = "00000";
	tr1['B'] = "00001";
	tr1['C'] = "00010";
	tr1['D'] = "00011";
	tr1['E'] = "00100";
	tr1['F'] = "00101";
	tr1['G'] = "00110";
	tr1['H'] = "00111";
	tr1['I'] = "01000";
	tr1['J'] = "01001";
	tr1['K'] = "01010";
	tr1['L'] = "01011";
	tr1['M'] = "01100";
	tr1['N'] = "01101";
	tr1['O'] = "01110";
	tr1['P'] = "01111";
	tr1['Q'] = "10000";
	tr1['R'] = "10001";
	tr1['S'] = "10010";
	tr1['T'] = "10011";
	tr1['U'] = "10100";
	tr1['V'] = "10101";
	tr1['W'] = "10110";
	tr1['X'] = "10111";
	tr1['Y'] = "11000";
	tr1['Z'] = "11001";
	tr1[' '] = "11010";
	tr1['.'] = "11011";
	tr1[','] = "11100";
	tr1['-'] = "11101";
	tr1['\''] = "11110";
	tr1['?'] = "11111";

	map<char, string> tr2;
	tr2[' '] = "101";
	tr2['\''] = "000000";
	tr2[','] = "000011";
	tr2['-'] = "10010001";
	tr2['.'] = "010001";
	tr2['?'] = "000001";
	tr2['A'] = "100101";
	tr2['B'] = "10011010";
	tr2['C'] = "0101";
	tr2['D'] = "0001";
	tr2['E'] = "110";
	tr2['F'] = "01001";
	tr2['G'] = "10011011";
	tr2['H'] = "010000";
	tr2['I'] = "0111";
	tr2['J'] = "10011000";
	tr2['K'] = "0110";
	tr2['L'] = "00100";
	tr2['M'] = "10011001";
	tr2['N'] = "10011110";
	tr2['O'] = "00101";
	tr2['P'] = "111";
	tr2['Q'] = "10011111";
	tr2['R'] = "1000";
	tr2['S'] = "00110";
	tr2['T'] = "00111";
	tr2['U'] = "10011100";
	tr2['V'] = "10011101";
	tr2['W'] = "000010";
	tr2['X'] = "10010010";
	tr2['Y'] = "10010011";
	tr2['Z'] = "10010000";

	string s = "";
	while ( getline(cin, s) ) {
		string code = "";

		for (int i = 0; i < s.size(); ++i) code += tr1[s[i]];

		int max_sz = 0; string ans = "";
		queue<P> Q; Q.push( P("", "") );
		while ( !Q.empty() ) {
			P p = Q.front(); Q.pop();
			string str = p.first;

			if (str.size() > code.size()) continue;

			bool f = true;
			for (int i = 0; i < str.size(); ++i)
				if (str[i] != code[i]) f = false;

			if (!f) continue;

//			for (int i = str.size(); i < code.size(); ++i)
//				if (code[i] == '1') f = false;

			ans = p.second;

			map<char, string>::iterator pos = tr2.begin();
			while ( pos != tr2.end() ) {
				Q.push( P(str + (*pos).second, p.second + (*pos).first) );
				++pos;
			}
		}
		cout << ans << endl;
	}
}
#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

map<char, int>notal{
	{ ' ',26 },{ '.',27 },{ ',',28 },{ '-',29 },{ '\'',30 },{ '?',31 }
};
map<int, char>mp{
	{ 26,' ' },{ 27,'\'' },{ 28,',' },{ 29,'-' },{ 30,'.' },{ 31,'?' },
};
string code[]{ "100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000","101","000000","000011","10010001","010001","000001" };
int main() {
	string s;
	while (getline(cin, s)) {
		stringstream ss;
		for (char c : s) {
			if (isalpha(c))ss << bitset<5>(c - 'A');
			else ss << bitset<5>(notal[c]);
		}
		s = ss.str();
		string ans;
		int i = 0;
		bool flag = true;
		while (flag) {
			flag = false;
			rep(j, 32) {
				if (i + code[j].size() <= s.size() && s.substr(i, code[j].size()) == code[j]) {
					if (j < 26)ans += 'A' + j;
					else ans += mp[j];
					i += code[j].size();
					flag = true;
				}
			}
		}
		cout << ans << endl;
	}
}
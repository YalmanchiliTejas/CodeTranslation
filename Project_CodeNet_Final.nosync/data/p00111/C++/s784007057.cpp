#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

map<char, int> m1;
string parse;

string make2(char c) {
	string res;
	int x = m1[c];

	REP(i, 5) {
		res.push_back((x & 1) + '0');
		x >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	parse = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-\'?";
	REP(i, parse.size()) m1[parse[i]] = i;
	
	string sec[32] = {
		"100101","10011010","0101","0001","110","01001","10011011","010000",
		"0111","10011000","0110","00100","10011001","10011110","00101","111",
		"10011111","1000","00110","00111","10011100","10011101","000010","10010010",
		"10010011","10010000","101","010001","000011","10010001","000000","000001"	
	};
	map<string, int> m2;
	REP(i, 32) m2[sec[i]] = i;
	
	string str;
	while (getline(cin, str)) {
		string tmp;
		REP(i, str.size()) tmp += make2(str[i]);
		
		string ans;
		int pos = 0;
		REP(i, tmp.size()) {
			string s;
			FOR(j, i, tmp.size()) {
				s += tmp[j];
				i = j;
				if (m2.find(s) != m2.end()) {
					ans.push_back(parse[m2[s]]);
					break;
				}
			}
			pos += i;
		}
		cout << ans << endl;
	}
	
	return 0;
}
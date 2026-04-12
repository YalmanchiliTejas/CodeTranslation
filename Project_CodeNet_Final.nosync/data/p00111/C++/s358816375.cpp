#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld =long double;
const ld eps = 1e-9;



int main()
{
	vector<string>cypher2{
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
		"10010000",
	};


	map<char,int>ps{
		make_pair(' ',0),
		make_pair('\'',1),
		make_pair(',',2),
		make_pair('-',3),
		make_pair('.',4),
		make_pair('?',5)
	};
	string st;
	while (getline(cin,st)) {
		string nst;
		for (auto ch : st) {
			int k=0;
			if (ps.find(ch)!= ps.end()) {
				k=26+ps[ch];
				if (k == 27) {
					k=30;

				}
				else if (k == 28) {
					k=28;
				}
				else if (k == 29) {

				}
				else if (k == 30) {
					k=27;
				}
			}
			else {
				k=ch-'A';
			}
			for (int i = 0; i < 5; ++i) {
				nst.push_back('0'+((k&(1<<(4-i)))!=0));
			}

		}

		
		string ans;
		int l=0;
		while (true) {
			char next(0);
			for (int i = 0; i < 32; ++i) {
				if (nst.substr(l, cypher2[i].size())==cypher2[i]) {
					if (i <=5) {
						for (auto m : ps) {
							if (m.second == i) {
								next=m.first;
							}
						}
					}
					else {
						next='A'+i-6;
					}
					l+=cypher2[i].size();
					break;
				}
			}
			if (next) {
				ans.push_back(next);
			}
			else {
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

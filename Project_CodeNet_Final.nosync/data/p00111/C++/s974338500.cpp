#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 10000000;

using namespace std;
/** Problem0088 : The Code A Doctor Loved **/
int main()
{
	string s;
	// 変換表 : http://refiute.hatenablog.com/entry/20111104/1320334135
	map<char,string> tbl1;
	tbl1['A']="00000";
	tbl1['B']="00001";
	tbl1['C']="00010";
	tbl1['D']="00011";
	tbl1['E']="00100";
	tbl1['F']="00101";
	tbl1['G']="00110";
	tbl1['H']="00111";
	tbl1['I']="01000";
	tbl1['J']="01001";
	tbl1['K']="01010";
	tbl1['L']="01011";
	tbl1['M']="01100";
	tbl1['N']="01101";
	tbl1['O']="01110";
	tbl1['P']="01111";
	tbl1['Q']="10000";
	tbl1['R']="10001";
	tbl1['S']="10010";
	tbl1['T']="10011";
	tbl1['U']="10100";
	tbl1['V']="10101";
	tbl1['W']="10110";
	tbl1['X']="10111";
	tbl1['Y']="11000";
	tbl1['Z']="11001";
	tbl1[' ']="11010";
	tbl1['.']="11011";
	tbl1[',']="11100";
	tbl1['-']="11101";
	tbl1['\'']= "11110";
	tbl1['?']="11111";
	map<string,char> tbl2;
	tbl2["101"]=' ';
	tbl2["000000"]='\'';
	tbl2["000011"]=',';
	tbl2["10010001"]='-';
	tbl2["010001"]='.';
	tbl2["000001"]='?';
	tbl2["100101"]='A';
	tbl2["10011010"]='B';
	tbl2["0101"]='C';
	tbl2["0001"]='D';
	tbl2["110"]='E';
	tbl2["01001"]='F';
	tbl2["10011011"]='G';
	tbl2["010000"]='H';
	tbl2["0111"]='I';
	tbl2["10011000"]='J';
	tbl2["0110"]='K';
	tbl2["00100"]='L';
	tbl2["10011001"]='M';
	tbl2["10011110"]='N';
	tbl2["00101"]='O';
	tbl2["111"]='P';
	tbl2["10011111"]='Q';
	tbl2["1000"]='R';
	tbl2["00110"]='S';
	tbl2["00111"]='T';
	tbl2["10011100"]='U';
	tbl2["10011101"]='V';
	tbl2["000010"]='W';
	tbl2["10010010"]='X';
	tbl2["10010011"]='Y';
	tbl2["10010000"]='Z';
	
	while (1) {
		getline(cin, s);
		if (cin.eof()) break;
		
		string code, sc, tmp, ans;
		rep(i, s.length()) {
			code += tbl1[s[i]];
		}
				
		rep(i, code.length()) {
			string t;
			for (; i<code.length(); i++) {
				t += code[i];
				if (tbl2[t]!=0) {
					ans+=tbl2[t];
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
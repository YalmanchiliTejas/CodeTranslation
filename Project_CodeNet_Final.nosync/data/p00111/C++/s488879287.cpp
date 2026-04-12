#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <map>
#include <cmath>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(int x=from;x<to;x++)

using namespace std;


int main(void){
string ws;
map<char,string> aa;
	aa['A']="00000";
	aa['B']="00001";
	aa['C']="00010";
	aa['D']="00011";
	aa['E']="00100";
	aa['F']="00101";
	aa['G']="00110";
	aa['H']="00111";
	aa['I']="01000";
	aa['J']="01001";
	aa['K']="01010";
	aa['L']="01011";
	aa['M']="01100";
	aa['N']="01101";
	aa['O']="01110";
	aa['P']="01111";
	aa['Q']="10000";
	aa['R']="10001";
	aa['S']="10010";
	aa['T']="10011";
	aa['U']="10100";
	aa['V']="10101";
	aa['W']="10110";
	aa['X']="10111";
	aa['Y']="11000";
	aa['Z']="11001";
	aa[' ']="11010";
	aa['.']="11011";
	aa[',']="11100";
	aa['-']="11101";
	aa['\'']= "11110";
	aa['?']="11111";
	map<string,char> bb;
	bb["101"]=' ';
	bb["000000"]='\'';
	bb["000011"]=',';
	bb["10010001"]='-';
	bb["010001"]='.';
	bb["000001"]='?';
	bb["100101"]='A';
	bb["10011010"]='B';
	bb["0101"]='C';
	bb["0001"]='D';
	bb["110"]='E';
	bb["01001"]='F';
	bb["10011011"]='G';
	bb["010000"]='H';
	bb["0111"]='I';
	bb["10011000"]='J';
	bb["0110"]='K';
	bb["00100"]='L';
	bb["10011001"]='M';
	bb["10011110"]='N';
	bb["00101"]='O';
	bb["111"]='P';
	bb["10011111"]='Q';
	bb["1000"]='R';
	bb["00110"]='S';
	bb["00111"]='T';
	bb["10011100"]='U';
	bb["10011101"]='V';
	bb["000010"]='W';
	bb["10010010"]='X';
	bb["10010011"]='Y';
	bb["10010000"]='Z'; 
	
	
	while(getline(cin,ws)){

		string wws="", ans="";
		rep(i, ws.size()) wws += aa[ws[i]];
//		cout << wws <<endl;
		string ww="";
		rep(i,wws.size()){
			ww += wws[i];
			if(bb[ww]!=0){
				ans += bb[ww];
				ww="";
			}
		}
		if(cin.eof()) break;
		cout << ans << endl;
	}

	return 0;
	
}
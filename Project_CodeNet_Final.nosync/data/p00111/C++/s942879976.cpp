#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <bitset>
using namespace std;
 
 
const double EPS = 1e-9;
 
int main(){
    map<char, string> enc;
    enc[' ']  = "101";
    enc['\''] = "000000";
    enc[',']  = "000011";
    enc['-']  = "10010001";
    enc['.']  = "010001";
    enc['?']  = "000001";
    enc['A']  = "100101";
    enc['B']  = "10011010";
    enc['C']  = "0101";
    enc['D']  = "0001";
    enc['E']  = "110";
    enc['F']  = "01001";
    enc['G']  = "10011011";
    enc['H']  = "010000";
    enc['I']  = "0111";
    enc['J']  = "10011000";
    enc['K']  = "0110";
    enc['L']  = "00100";
    enc['M']  = "10011001";
    enc['N']  = "10011110";
    enc['O']  = "00101";
    enc['P']  = "111";
    enc['Q']  = "10011111";
    enc['R']  = "1000";
    enc['S']  = "00110";
    enc['T']  = "00111";
    enc['U']  = "10011100";
    enc['V']  = "10011101";
    enc['W']  = "000010";
    enc['X']  = "10010010";
    enc['Y']  = "10010011";
    enc['Z']  = "10010000";

    string d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
    map<char, string> dec;
    for(int i = 0; i < 32; i++){
        dec[d[i]] = bitset<5>(i).to_string();
    }

    string s;
    while(getline(cin, s)){
        string e;
        for(int i = 0; i < s.size(); i++){
            e += dec[s[i]];
        }
        for(int i = 0; i < e.size();){
			map<char, string>::iterator it;
			for(it = enc.begin(); it != enc.end(); it++){
				int len = (*it).second.size();
				if(i+len <= e.size()){
					if((*it).second == e.substr(i, len)){
						cout << (*it).first;
						i+=len;
						break;
					}
				}
			}
			if(it == enc.end()){
				break;
			}
        }
        cout << endl;
    } 
 
    return 0;
}
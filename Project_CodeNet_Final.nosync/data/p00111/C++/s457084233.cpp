#define	_USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cfloat>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <set>
#include <complex>
#include <utility>
#include <numeric>
using namespace std;
typedef pair<double,double> P;
int b[19][19];


int main(){
	
	map<string,string> ec;
    map<string,string> dc;
     
    ec[" "]="11010";
    ec["'"]="11110";
    ec[","]="11100";
    ec["-"]="11101";
    ec["."]="11011";
    ec["?"]="11111";
    ec["A"]="00000";
    ec["B"]="00001";
    ec["C"]="00010";
    ec["D"]="00011";
    ec["E"]="00100";
    ec["F"]="00101";
    ec["G"]="00110";
    ec["H"]="00111";
    ec["I"]="01000";
    ec["J"]="01001";
    ec["K"]="01010";
    ec["L"]="01011";
    ec["M"]="01100";
    ec["N"]="01101";
    ec["O"]="01110";
    ec["P"]="01111";
    ec["Q"]="10000";
    ec["R"]="10001";
    ec["S"]="10010";
    ec["T"]="10011";
    ec["U"]="10100";
    ec["V"]="10101";
    ec["W"]="10110";
    ec["X"]="10111";
    ec["Y"]="11000";
    ec["Z"]="11001";
     
    dc["100101"]="A";
    dc["10011010"]="B";
    dc["0101"]="C";
    dc["0001"]="D";
    dc["110"]="E";
    dc["01001"]="F";
    dc["10011011"]="G";
    dc["010000"]="H";
    dc["0111"]="I";
    dc["10011000"]="J";
    dc["0110"]="K";
    dc["00100"]="L";
    dc["10011001"]="M";
    dc["10011110"]="N";
    dc["00101"]="O";
    dc["111"]="P";
    dc["10011111"]="Q";
    dc["1000"]="R";
    dc["00110"]="S";
    dc["00111"]="T";
    dc["10011100"]="U";
    dc["10011101"]="V";
    dc["000010"]="W";
    dc["10010010"]="X";
    dc["10010011"]="Y";
    dc["10010000"]="Z";
    dc["101"]=" ";
    dc["010001"]=".";
    dc["000011"]=",";
    dc["10010001"]="-";
    dc["000000"]="'";
    dc["000001"]="?";
	
	string s;
	while(getline(cin,s)){
	
	string temp="";
	for(int i=0;i<s.size();i++){
		temp+=ec[s.substr(i,1)];
	}
	string a="";
	string ans="";
	for(int i=0;i<temp.size();i++){
		a+=temp[i];
		if(dc.count(a)==1){
			ans+=dc[a];
			a="";
		}
	}
	
	cout<<ans<<endl;
	}
}
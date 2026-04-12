#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
string str[3];
map<char,string> v;
int main(void){
	v.insert(pair<char,string>('A',"00000"));
	v.insert(pair<char,string>('B',"00001"));
	v.insert(pair<char,string>('C',"00010"));
	v.insert(pair<char,string>('D',"00011"));
	v.insert(pair<char,string>('E',"00100"));
	v.insert(pair<char,string>('F',"00101"));
	v.insert(pair<char,string>('G',"00110"));
	v.insert(pair<char,string>('H',"00111"));
	v.insert(pair<char,string>('I',"01000"));
	v.insert(pair<char,string>('J',"01001"));
	v.insert(pair<char,string>('K',"01010"));
	v.insert(pair<char,string>('L',"01011"));
	v.insert(pair<char,string>('M',"01100"));
	v.insert(pair<char,string>('N',"01101"));
	v.insert(pair<char,string>('O',"01110"));
	v.insert(pair<char,string>('P',"01111"));
	v.insert(pair<char,string>('Q',"10000"));
	v.insert(pair<char,string>('R',"10001"));
	v.insert(pair<char,string>('S',"10010"));
	v.insert(pair<char,string>('T',"10011"));
	v.insert(pair<char,string>('U',"10100"));
	v.insert(pair<char,string>('V',"10101"));
	v.insert(pair<char,string>('W',"10110"));
	v.insert(pair<char,string>('X',"10111"));
	v.insert(pair<char,string>('Y',"11000"));
	v.insert(pair<char,string>('Z',"11001"));
	v.insert(pair<char,string>(' ',"11010"));
	v.insert(pair<char,string>('.',"11011"));
	v.insert(pair<char,string>(',',"11100"));
	v.insert(pair<char,string>('-',"11101"));
	v.insert(pair<char,string>('\'',"11110"));
	v.insert(pair<char,string>('?',"11111"));
	while(getline(cin,str[0])){
		for(int i=0;i<str[0].size();i++){
			str[1]+=v[str[0][i]];
		}
		while(1){
			if(str[1].find("101")==0){
				str[2]+=" ";
				str[1]=str[1].substr(3);
			}
			else if(str[1].find("000000")==0){
				str[2]+="'";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("000011")==0){
				str[2]+=",";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("10010001")==0){
				str[2]+="-";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("010001")==0){
				str[2]+=".";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("000001")==0){
				str[2]+="?";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("100101")==0){
				str[2]+="A";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("10011010")==0){
				str[2]+="B";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("0101")==0){
				str[2]+="C";
				str[1]=str[1].substr(4);
			}
			else if(str[1].find("0001")==0){
				str[2]+="D";
				str[1]=str[1].substr(4);
			}
			else if(str[1].find("110")==0){
				str[2]+="E";
				str[1]=str[1].substr(3);
			}
			else if(str[1].find("01001")==0){
				str[2]+="F";
				str[1]=str[1].substr(5);
			}
			else if(str[1].find("10011011")==0){
				str[2]+="G";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("010000")==0){
				str[2]+="H";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("0111")==0){
				str[2]+="I";
				str[1]=str[1].substr(4);
			}
			else if(str[1].find("10011000")==0){
				str[2]+="J";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("0110")==0){
				str[2]+="K";
				str[1]=str[1].substr(4);
			}
			else if(str[1].find("00100")==0){
				str[2]+="L";
				str[1]=str[1].substr(5);
			}
			else if(str[1].find("10011001")==0){
				str[2]+="M";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("10011110")==0){
				str[2]+="N";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("00101")==0){
				str[2]+="O";
				str[1]=str[1].substr(5);
			}
			else if(str[1].find("111")==0){
				str[2]+="P";
				str[1]=str[1].substr(3);
			}
			else if(str[1].find("10011111")==0){
				str[2]+="Q";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("1000")==0){
				str[2]+="R";
				str[1]=str[1].substr(4);
			}
			else if(str[1].find("00110")==0){
				str[2]+="S";
				str[1]=str[1].substr(5);
			}
			else if(str[1].find("00111")==0){
				str[2]+="T";
				str[1]=str[1].substr(5);
			}
			else if(str[1].find("10011100")==0){
				str[2]+="U";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("10011101")==0){
				str[2]+="V";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("000010")==0){
				str[2]+="W";
				str[1]=str[1].substr(6);
			}
			else if(str[1].find("10010010")==0){
				str[2]+="X";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("10010011")==0){
				str[2]+="Y";
				str[1]=str[1].substr(8);
			}
			else if(str[1].find("10010000")==0){
				str[2]+="Z";
				str[1]=str[1].substr(8);
			}
			else break;
		}
		cout << str[2] << endl;
		str[0].clear();
		str[1].clear();
		str[2].clear();
	}
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string dectobin(int a){
	string tmp="";
	while(a) { tmp+=(a%2)+'0'; a>>=1;}
	while(tmp.size()<5) tmp+='0';
	reverse(tmp.begin(),tmp.end());
	return tmp;
}
char strtoch(string str){
	if(str.size()==3)
	{
		if(str=="101") return ' ';
		else if(str=="110") return 'E';
		else if(str=="111") return 'P';
	}
	else if(str.size()==4)
	{
		if(str=="0101") return 'C';
		else if(str=="0001") return 'D';
		else if(str=="0111") return 'I';
		else if(str=="0110") return 'K';
		else if(str=="1000") return 'R';
	}
	else if(str.size()==5)
	{
		if(str=="00100") return 'L';
		else if(str=="00101") return 'O';
		else if(str=="00110") return 'S';
		else if(str=="00111") return 'T';
		else if(str=="01001") return 'F';
	}
	else if(str.size()==6)
	{
		if(str=="000000") return '\'';
		else if(str=="000001") return '?';
		else if(str=="000010") return 'W';
		else if(str=="000011") return ',';
		else if(str=="010000") return 'H';
		else if(str=="010001") return '.';
		else if(str=="100101") return 'A';
	}
	else if(str.size()==8)
	{
		if(str=="10010001") return '-';
		else if(str=="10011010") return 'B';
		else if(str=="10011011") return 'G';
		else if(str=="10011000") return 'J';
		else if(str=="10011001") return 'M';
		else if(str=="10011110") return 'N';
		else if(str=="10011111") return 'Q';
		else if(str=="10011100") return 'U';
		else if(str=="10011101") return 'V';
		else if(str=="10010010") return 'X';
		else if(str=="10010011") return 'Y';
		else if(str=="10010000") return 'Z';
	}
	return 'a';
}
int main() {
	string str;
	while(getline(cin,str)){
		string tmp="";
		for(int i=0;i<str.size();i++){
			char ch; ch=str[i];
			if(ch-'A'>=0 && ch-'Z'<=0) tmp+=dectobin(ch-'A');
			else if(ch==' ') tmp+="11010";
			else if(ch=='.') tmp+="11011";
			else if(ch==',') tmp+="11100";			
			else if(ch=='-') tmp+="11101";
			else if(ch=='\'') tmp+="11110";
			else if(ch=='?') tmp+="11111";
		}
		string ans="";
		for(int i=0;i<tmp.size();i++){
			for(int j=3;i+j-1<=tmp.size()-1;j++){
				char ch=strtoch(tmp.substr(i,j));
				if(ch!='a' ) {ans+=ch;i+=j-1;break;}
			}
		}
		cout << ans << '\n' ;
	}
}
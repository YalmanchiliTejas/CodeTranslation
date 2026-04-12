#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	map<char,string> en;
	en['A']="00000";	en['B']="00001";	en['C']="00010";
	en['D']="00011";	en['E']="00100";	en['F']="00101";
	en['G']="00110";	en['H']="00111";	en['I']="01000";
	en['J']="01001";	en['K']="01010";	en['L']="01011";
	en['M']="01100";	en['N']="01101";	en['O']="01110";
	en['P']="01111";	en['Q']="10000";	en['R']="10001";
	en['S']="10010";	en['T']="10011";	en['U']="10100";
	en['V']="10101";	en['W']="10110";	en['X']="10111";
	en['Y']="11000";	en['Z']="11001";	en[' ']="11010";
	en['.']="11011";	en[',']="11100";	en['-']="11101";
	en['\'']="11110";	en['?']="11111";

	map<string,char> de;
	de["101"]=' ';		de["000000"]='\'';	de["000011"]=',';
	de["10010001"]='-';	de["010001"]='.';	de["000001"]='?';
	de["100101"]='A';	de["10011010"]='B';	de["0101"]='C';
	de["0001"]='D';		de["110"]='E';		de["01001"]='F';
	de["10011011"]='G';	de["010000"]='H';	de["0111"]='I';
	de["10011000"]='J';	de["0110"]='K';		de["00100"]='L';
	de["10011001"]='M';	de["10011110"]='N';	de["00101"]='O';
	de["111"]='P';		de["10011111"]='Q';	de["1000"]='R';
	de["00110"]='S';	de["00111"]='T';	de["10011100"]='U';
	de["10011101"]='V';	de["000010"]='W';	de["10010010"]='X';
	de["10010011"]='Y';	de["10010000"]='Z';

	string s;
	while(getline(cin,s)){
		string text;
		for(int i=0;i<s.length();i++)	text+=en[s[i]];
		for(int i=0,len;i<text.length();i+=len){
			bool found=false;
			for(len=3;i+len<=text.length();len++){
				if(de.count(text.substr(i,len))!=0){
					found=true;
					break;
				}
			}
			if(!found)	break;
			cout<<de[text.substr(i,len)];
		}
		cout<<endl;
	}

	return 0;
}
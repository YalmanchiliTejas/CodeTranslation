#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>

using namespace std;

int main(){

	map<string,char> table;
	map<char,string> table2;

	table["101"]=' ';
	table["000000"]=(char)39;
	table["000011"]=',';
	table["10010001"]='-';
	table["010001"]='.';
	table["000001"]='?';
	table["100101"]='A';
	table["10011010"]='B';
	table["0101"]='C';
	table["0001"]='D';
	table["110"]='E';
	table["01001"]='F';
	table["10011011"]='G';
	table["010000"]='H';
	table["0111"]='I';
	table["10011000"]='J';
	table["0110"]='K';
	table["00100"]='L';
	table["10011001"]='M';
	table["10011110"]='N';
	table["00101"]='O';
	table["111"]='P';
	table["10011111"]='Q';
	table["1000"]='R';
	table["00110"]='S';
	table["00111"]='T';
	table["10011100"]='U';
	table["10011101"]='V';
	table["000010"]='W';
	table["10010010"]='X';
	table["10010011"]='Y';
	table["10010000"]='Z';

	// \

	for(int i = 0; i < 26; i++){
		string ms;
		for(int j = 0; j < 5; j++){
			if((i>>j)&1){
				ms+='1';
			}
			else
				ms+='0';
		}
		reverse(ms.begin(),ms.end());
		table2['A'+i]=ms;
	}
	table2[' ']="11010";
	table2['.']="11011";
	table2[',']="11100";
	table2['-']="11101";
	table2[(char)39]="11110";
	table2['?']="11111";


	string str;
	while(getline(cin,str)){
		// ¶ð»
		string nstr;
		for(int i = 0; i < str.size(); i++){
			nstr+=(table2[str[i]]);
		}
		//¡
		string dstr;
		for(int i = 0; i < nstr.size(); i++){
			for(map<string,char>::iterator it = table.begin(); it !=table.end(); it++){
				string s=it->first;
				if(i+s.size()-1<nstr.size()){
					string ss=nstr.substr(i,s.size());
					if(it->first==ss){
						dstr+=it->second;
						i+=s.size()-1;
						break;
					}
				}
			}
		}
		cout<<dstr<<endl;
	}

	return 0;
}
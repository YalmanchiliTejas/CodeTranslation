#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string db(int a){
	string ret;
	for(int i=0;i<5;i++){
		ret += '0'+a%2;
		a/=2;
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

bool cmp(string a,string b){
	return a.length() > b.length();
}

int main(){
	map<char,string> table;
	
	for(int i=0;i<26;i++)table['A'+i] = db(i);
	string tmp = " .,-'?";
	for(int i=0;i<tmp.size();i++)table[tmp[i]] = db(26+i);
	
	string n;
	
	map<string,char> r;
	
	r["101"] = ' '; r["0101"] = 'C'; r["0110"] = 'K'; r["00110"] = 'S';
	r["000000"] = '\''; r["0001"] = 'D'; r["00100"] = 'L'; r["00111"] = 'T';
	r["000011"] = ','; r["110"] = 'E'; r["10011001"] = 'M'; r["10011100"] = 'U';
	r["10010001"] = '-'; r["01001"] = 'F'; r["10011110"] = 'N'; r["10011101"] = 'V';
	r["010001"] = '.'; r["10011011"] = 'G'; r["00101"] = 'O'; r["000010"] = 'W';
	r["000001"] = '?'; r["010000"] = 'H'; r["111"] = 'P'; r["10010010"] = 'X';
	r["100101"] = 'A'; r["0111"] = 'I'; r["10011111"] = 'Q'; r["10010011"] = 'Y';
	r["10011010"] = 'B'; r["10011000"] = 'J'; r["1000"] = 'R'; r["10010000"] = 'Z';
	
	while( getline(cin,n) ){
		string use,ret;
		for(int i=0;i<n.length();i++)
			use += table[n[i]];
		string choice;
		int pos = 0;
		
		vector<string>reset;
		
		for( map<string,char>::iterator it=r.begin(); it != r.end(); ++it){
			reset.push_back((*it).first);
		}
		sort(reset.begin(),reset.end(),cmp);
		
		for(;;){
			choice = "";
			for(int i=0;i<reset.size();i++){
				if(use.find(reset[i]) == 0){
					choice = reset[i];
					break;
				}
			}
			if(choice != "")ret += r[choice];
			else break;
			
			use = use.substr(choice.length(),use.length()-choice.length());
		}
		cout << ret << endl;
		
	}

}
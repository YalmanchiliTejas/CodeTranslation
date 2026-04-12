#include<iostream>
#include<bitset>
#include<string>
using namespace std;
string tbl01[]={
	"101","000000","000011","10010001","010001","000001","100101","10011010",
	"0101","0001","110","01001","10011011","010000","0111","10011000",
	"0110","00100","10011001","10011110","00101","111","10011111","1000",
	"00110","00111","10011100","10011101","000010","10010010","10010011","10010000"
};
string tbl01_idx=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string str_AB=" .,-'?";

string from01(string s){
	string r;
	for(int i=0;i<s.size();){
		for(int j=0;j<32;j++){
			if(s.substr(i,tbl01[j].size())!=tbl01[j]){
				if(j==31)return r;
				continue;
			}
			i+=tbl01[j].size();
			r+=tbl01_idx[j];
			break;
		}
	}
}
string fromAB(string &s){
	string r;
	for(int i=0;i<s.size();i++){
		int c=str_AB.find(s[i]);
		if(c==str_AB.npos)c=s[i]-'A';
		else c+=26;
		r+=bitset<5>(c).to_string<char,char_traits<char>,allocator<char> >();
	}
	return r;
}
int main(){
	string s;
	while(getline(cin,s))cout<<from01(fromAB(s))<<endl;
	return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<set>

using namespace std;
typedef pair<int,int> PII;
typedef long long ll;

vector<string> decode;
vector<string> encode;
string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";

void code(){
	decode.push_back("100101");
	decode.push_back("10011010");
	decode.push_back("0101");
	decode.push_back("0001");
	decode.push_back("110");
	decode.push_back("01001");
	decode.push_back("10011011");
	decode.push_back("010000");
	decode.push_back("0111");
	decode.push_back("10011000");
	decode.push_back("0110");
	decode.push_back("00100");
	decode.push_back("10011001");
	decode.push_back("10011110");
	decode.push_back("00101");
	decode.push_back("111");
	decode.push_back("10011111");
	decode.push_back("1000");
	decode.push_back("00110");
	decode.push_back("00111");
	decode.push_back("10011100");
	decode.push_back("10011101");
	decode.push_back("000010");
	decode.push_back("10010010");
	decode.push_back("10010011");
	decode.push_back("10010000");
	decode.push_back("101");
	decode.push_back("010001");
	decode.push_back("000011");
	decode.push_back("10010001");
	decode.push_back("000000");
	decode.push_back("000001");
	
	for(int i=0;i<32;i++){
		int k=i;
		string line = "";
		for(int j=0;j<5;j++){
			if(k%2)
				line = "1" + line;
			else
				line = "0" + line;
			k/=2;
		}
		encode.push_back(line);
	}
}

string CodeToNum(string line){
	string nums = "";
	for(int i=0;i<line.size();i++){
		nums = nums + encode[character.find(line[i])];
	}
	return nums;
}

string NumToText(string nums){
	string text = "";
	bool findch;
	while(true){
		int findnum;
		findch = false;
		for(findnum=0;findnum<32;findnum++){
			if(decode[findnum] == nums.substr(0,decode[findnum].size())){
				findch = true;
				break;
			}
		}
		if(!findch)break;
		text = text + character[findnum];
		nums = nums.substr(decode[findnum].size());
	}
	return text;
}

int main(){
	code();
	string line;
	while(getline(cin,line,'\n')){
		cout<<NumToText(CodeToNum(line))<<endl;
	}
  return 0;
}
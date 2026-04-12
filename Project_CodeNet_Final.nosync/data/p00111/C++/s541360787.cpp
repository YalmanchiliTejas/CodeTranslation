#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;

typedef map<string,string> MSS;

#define MSSVT MSS::value_type

int main(){
	
	string gc;
	string inp;
	string sea;
	string hen;
	string ans;
	MSS data1,data2;

	data1.insert(MSSVT("101"," "));
	data1.insert(MSSVT("010001","."));
	data1.insert(MSSVT("000011",","));
	data1.insert(MSSVT("10010001","-"));
	data1.insert(MSSVT("000000","'"));
	data1.insert(MSSVT("000001","?"));
	data1.insert(MSSVT("100101","A"));
	data1.insert(MSSVT("10011010","B"));
	data1.insert(MSSVT("0101","C"));
	data1.insert(MSSVT("0001","D"));
	data1.insert(MSSVT("110","E"));
	data1.insert(MSSVT("01001","F"));
	data1.insert(MSSVT("10011011","G"));
	data1.insert(MSSVT("010000","H"));
	data1.insert(MSSVT("0111","I"));
	data1.insert(MSSVT("10011000","J"));
	data1.insert(MSSVT("0110","K"));
	data1.insert(MSSVT("00100","L"));
	data1.insert(MSSVT("10011001","M"));
	data1.insert(MSSVT("10011110","N"));
	data1.insert(MSSVT("00101","O"));
	data1.insert(MSSVT("111","P"));
	data1.insert(MSSVT("10011111","Q"));
	data1.insert(MSSVT("1000","R"));
	data1.insert(MSSVT("00110","S"));
	data1.insert(MSSVT("00111","T"));
	data1.insert(MSSVT("10011100","U"));
	data1.insert(MSSVT("10011101","V"));
	data1.insert(MSSVT("000010","W"));
	data1.insert(MSSVT("10010010","X"));
	data1.insert(MSSVT("10010011","Y"));
	data1.insert(MSSVT("10010000","Z"));
	data2.insert(MSSVT(" ","11010"));
	data2.insert(MSSVT(".","11011"));
	data2.insert(MSSVT(",","11100"));
	data2.insert(MSSVT("-","11101"));
	data2.insert(MSSVT("'","11110"));
	data2.insert(MSSVT("?","11111"));
	data2.insert(MSSVT("A","00000"));
	data2.insert(MSSVT("B","00001"));
	data2.insert(MSSVT("C","00010"));
	data2.insert(MSSVT("D","00011"));
	data2.insert(MSSVT("E","00100"));
	data2.insert(MSSVT("F","00101"));
	data2.insert(MSSVT("G","00110"));
	data2.insert(MSSVT("H","00111"));
	data2.insert(MSSVT("I","01000"));
	data2.insert(MSSVT("J","01001"));
	data2.insert(MSSVT("K","01010"));
	data2.insert(MSSVT("L","01011"));
	data2.insert(MSSVT("M","01100"));
	data2.insert(MSSVT("N","01101"));
	data2.insert(MSSVT("O","01110"));
	data2.insert(MSSVT("P","01111"));
	data2.insert(MSSVT("Q","10000"));
	data2.insert(MSSVT("R","10001"));
	data2.insert(MSSVT("S","10010"));
	data2.insert(MSSVT("T","10011"));
	data2.insert(MSSVT("U","10100"));
	data2.insert(MSSVT("V","10101"));
	data2.insert(MSSVT("W","10110"));
	data2.insert(MSSVT("X","10111"));
	data2.insert(MSSVT("Y","11000"));
	data2.insert(MSSVT("Z","11001"));

	
	while(getline(cin,inp)){
		hen=("");
		for(int i=0;i<inp.size();i++){
			sea=inp[i];
			//cout<<inp[i]<<"||"<<endl;
			hen+=data2[sea];
		}
		ans=("");
		sea=("");
		for(int i=0;i<hen.size();i++){
			sea+=hen[i];
			if(data1.find(sea)!=data1.end()){
				ans+=data1[sea];
				//cout<<data1[sea]<<","<<sea<<endl;
				sea=("");
			}
		}
		if(cin.eof()) break;
		cout<<ans<<endl;
	}

}
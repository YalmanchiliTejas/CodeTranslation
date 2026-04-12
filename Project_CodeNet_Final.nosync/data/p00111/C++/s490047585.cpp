#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	char ch[32+1]="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
	string table[256];
	for(int i=0;i<32;i++){
		string code;
		for(int j=0;j<5;j++)code+=(i>>(4-j)&1)+'0';
		table[ch[i]]=code;
	}
	map<string ,char> mp;
	map<string ,char>::iterator it;
	mp["101"]=' ';
	mp["000000"]='\'';
	mp["000011"]=',';
	mp["10010001"]='-';
	mp["010001"]='.';
	mp["000001"]='?';
	string codes[26]={"100101","10011010"
		,"0101","0001","110","01001","10011011","010000","0111","10011000"
		,"0110","00100","10011001","10011110","00101","111","10011111","1000"
		,"00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
	for(int i=0;i<26;i++)mp[codes[i]]='A'+i;

	
	string s;
	while(getline(cin,s)){
		string t,r,ans;
		for(int i=0;i<s.size();i++){
			t += table[s[i]];
		}
		for(int i=0;i<t.size();i++){
			r+=t[i];
			it=mp.find(r);
			if(it!=mp.end()){
				ans+=it->second;
				r.clear();
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
}
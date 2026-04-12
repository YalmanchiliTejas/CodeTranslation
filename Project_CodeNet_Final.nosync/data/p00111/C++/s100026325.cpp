#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

string table1[32]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
char table2[6]={' ','\'',',','-','.','?'};

string binary(int num){
	string ans="";
	for(int i=4;i>=0;i--){
		ans+=(char)(num/(int)pow(2,i)+'0');
		num-=(num/(int)pow(2,i))*(int)pow(2,i);
	}
	return ans;
}

string change(char c){
	string ans;
	if(isalpha(c)){
		int num=c-'A';
		ans=binary(num);
	}else{
		if(c==' ')ans=binary(26);
		else if(c=='.')ans=binary(27);
		else if(c==',')ans=binary(28);
		else if(c=='-')ans=binary(29);
		else if(c=='\'')ans=binary(30);
		else if(c=='?')ans=binary(31);
	}
	if(ans.size()<5)ans='0'+ans;
	return ans;
}

string rechange(string str){
	int size=str.size();
	string pack="",ans="";
	int counta=0;
	while(counta<size){
		pack+=str[counta];
		for(int i=0;i<32;i++){
			if(pack==table1[i]){
				if(i<6){
					ans+=table2[i];
				}else{
					ans+=(char)(i-6+'A');
				}
				pack="";
				break;
			}
		}
		counta++;
	}
	return ans;
}

int main(){
	string s;
	while(getline(cin,s)){
		int size=s.size();
		string alt="";
		rep(i,size){
			alt+=change(s[i]);
		}
		cout<<rechange(alt)<<endl;
	}
	return 0;
}
#include<iostream>
#include<string>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<char> v;
string n="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
string k=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string m[]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
void F1(char z){
	int a,b=32;
	rep(i,32)if(n[i]==z)a=i;
	rep(i,5){
		v.push_back('0'+(a%b>=b/2));
		b/=2;if(b==1)break;
	}
}
int main(){
	string s,r;
	while(getline(cin,s)){
	r="";v.clear();
	rep(i,s.size())F1(s[i]);
	rep(i,v.size()){
		r.push_back(v[i]);
		rep(j,32){if(m[j]==r){
			cout<<k[j];r="";
		}}
	}cout<<endl;}
	return 0;
}
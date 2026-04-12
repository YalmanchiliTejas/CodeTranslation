//10
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  for(string s;getline(cin,s);){
    string ds;
    for(int i=0;i<s.size();i++){
      string dt="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
      int dd=dt.find(s[i]);
      for(int j=4;j>=0;j--){
	ds+=!!(dd&1<<j)+'0';
      }
    }
    string b;
    for(int i=0;i<ds.size();i++){
      b+=ds[i];
      string e[]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
      const char *ec=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      int p=find(e,e+32,b)-e;
      if(p!=32){
	cout<<ec[p];
	b.clear();
      }
    }
    cout<<endl;
  }
  return 0;
}
      
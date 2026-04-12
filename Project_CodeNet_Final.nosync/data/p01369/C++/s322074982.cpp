#include<iostream>
#include<string>
using namespace std;

int main(){

  string s, left="qwertasdfgzxcvb";

  while(cin>>s){
    if(s=="#") break;
    bool right;
    if(left.find(s[0])!=string::npos) right=false;
    else right=true;
    int cnt=0;
    for(int i=1;i<s.size();i++){
      if(right){
	if(left.find(s[i])!=string::npos){
	  right=false;
	  cnt++;
	}
      }else{
	if(left.find(s[i])==string::npos){
	  right=true;
	  cnt++;
	}
      }
    }
    cout<<cnt<<endl;
  }
  
  return 0;
}
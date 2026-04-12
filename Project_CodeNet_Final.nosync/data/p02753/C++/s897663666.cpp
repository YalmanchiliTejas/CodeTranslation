#include<iostream>
using namespace std;
int main(){
	int i,num=0,num2=0;
  	string ch;
  	cin>>ch;
  	for(i=0;i<ch.size();i++){
    	if(ch[i]=='A')num++;
      	else num2++;
    }
  if(num>0 &&num2>0)cout<<"Yes";
  else cout<<"No";
  return 0;
}
#include<iostream>
using namespace std;
int main(){
	string s;
  	cin>>s;
  	for(int i=0;i<3;i++){
    	if(s[i]!=s[0])return cout<<"Yes"<<endl,0;
    }
  cout<<"No"<<endl;
  return 0;
}
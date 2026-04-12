#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int flag=0;
	if(s[0]!=s[1]){
		flag=1;
	}
	if(s[2]!=s[1]){
		flag=1;
	}
	if(flag==1){
		cout<<"Yes"<<endl;
	}
	if(flag==0){
		cout<<"No"<<endl; 
	}
	return 0;
} 
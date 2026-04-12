#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s[0]=='A' && s[1]=='C'){
		cout<<"Yes"<<endl;
	}
	
	else if(s[1]=='A' && s[2]=='C'){
		cout<<"Yes"<<endl;
	}
	
	else if(s[2]=='A' && s[3]=='C'){
		cout<<"Yes"<<endl;
	}
	
	else if(s[3]=='A' && s[4]=='C'){
		cout<<"Yes"<<endl;
	}
	
	else cout<<"No"<<endl;
}
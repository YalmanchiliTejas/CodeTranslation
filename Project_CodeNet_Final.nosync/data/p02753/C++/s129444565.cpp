#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	int i=0;
	int a=0;
	int b=0;
	cin>>s;
	size_t size=s.length();  
	
	for(i=0;i<size;i++){
		if(s[i]=='A') a=a+1;
		if(s[i]=='B') b=b+1;
	}
	if(a>0 && b>0){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	
	return 0;
}
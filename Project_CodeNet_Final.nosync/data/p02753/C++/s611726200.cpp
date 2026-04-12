#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int c1 = 0,c2=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'){
			c1++;
		}
		else
			c2++;
		
	}
	if(c1==3 || c2==3){
		cout<<"No";
	}
	else{
		cout<<"Yes";
	}
}

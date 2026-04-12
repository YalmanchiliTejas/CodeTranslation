#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;int i;
	while(cin>>s){
		for(i=0;i<s.size()-1;i++)if(s[i]=='A'&&s[i+1]=='C')break;
		cout<<(i==s.size()-1?"No\n":"Yes\n");
	}
}

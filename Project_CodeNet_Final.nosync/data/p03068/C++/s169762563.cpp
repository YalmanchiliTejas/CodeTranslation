#include<iostream>
using namespace std;
string s;
int a,n;
int main(){
	cin>>n>>s>>a;
	for(register int i=0;i<n;i++){
		if(s[i]!=s[a-1])cout<<'*';
		else cout<<s[i];
	}
}
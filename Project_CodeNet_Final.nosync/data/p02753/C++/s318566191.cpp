#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i,a=0,b=0;
	for(i=0;i<3;++i){
		if(s[i]=='A')++a;
		else ++b;
	}
	if(a and b)cout<<"Yes";
	else cout<<"No";
} 
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='A'&&s[i+1]=='C'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
} 
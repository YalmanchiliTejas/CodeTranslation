#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	for(int i=0;i<3;i++){
		cin>>s[i];
	}
	if((s[0]==s[1])&&(s[1]==s[2])){
		cout<<"No"<<endl;
	}
	else{
	cout<<"Yes"<<endl;
	}
	return 0;
}
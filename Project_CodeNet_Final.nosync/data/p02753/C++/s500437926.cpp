#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	int count = 0;
	if((s[0] == s[1])&&(s[1] == s[2])&& (s[0] == s[2]) ) count++;
	if(!count) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;


}
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int counta=0,countb=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A')
		counta++;
		else
		countb++;
	}
	if(counta>0 && countb>0)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
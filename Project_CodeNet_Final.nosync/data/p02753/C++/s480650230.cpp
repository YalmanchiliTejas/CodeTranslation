#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	cin>>s;
	int numa=0,numb=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A') numa++;
		else numb++;
	}
	if(numa==3||numb==3){
		cout<<"No"<<endl;
	}
	else cout<<"Yes"<<endl;
}
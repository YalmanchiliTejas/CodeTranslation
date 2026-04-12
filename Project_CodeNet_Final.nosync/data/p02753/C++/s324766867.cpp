#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;	cin>>s;
	int cntA=0,cntB=0;

	for(int i=0;i<s.length();i++){
		if(s[i]=='A')cntA++;
		else cntB++;
	}

	if(cntA==3||cntB==3)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;


	return 0;
}

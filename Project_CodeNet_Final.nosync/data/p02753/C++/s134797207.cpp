#include<bits/stdc++.h>
using namespace std;

int main(){
	int i,ans=0;
	string s;
	cin>>s;
	
	for(i=0;i<s.size();i++)
	if(s[i]=='A') ans++;
	
	if(ans==0||ans==3){
		cout<<"No";
	}else{
		cout<<"Yes";
	}
	
	return 0;
} 
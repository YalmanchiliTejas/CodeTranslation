#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	bool key1=false,key2=false;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')key1=true;
		if(s[i]=='B')key2=true;
	}
	if(key1&&key2){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
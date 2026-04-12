#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int fa=0,fb=0;
	cin>>s;
	for(int i=0;i<3;i++){
		if(s[i]=='A')fa=1;
		else if(s[i]=='B')fb=1;
	}
	if(fa&&fb)cout<<"Yes";
	else cout<<"No";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool a,b;
string s;
int main(){
	cin>>s;
	for(int i=0;i<3;i++){
		if(s[i]=='A')
			a=1;
		if(s[i]=='B')
			b=1;
	}
	if(a&&b)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
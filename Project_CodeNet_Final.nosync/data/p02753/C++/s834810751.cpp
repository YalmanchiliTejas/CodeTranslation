#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s;
	int a=0,b=0;
	cin>>s;
	for(int i=0;i<3;i++){
		if(s[i]=='A')
			a=1;
		else
			b=1;
	}
	if(a&&b)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
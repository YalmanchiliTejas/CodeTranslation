#include"bits/stdc++.h"
using namespace std;
int main(){
	string a;
	cin>>a;
	int flag1=0,flag2=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='A')flag1=1;
		if(a[i]=='B')flag2=1;
	}
	if(flag1==1&&flag2==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
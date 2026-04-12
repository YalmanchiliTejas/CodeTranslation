#include"bits/stdc++.h"
using namespace std;
string s;
int x,y,z;
int main(){
	cin>>x>>y>>z;
	if((x*100+y*10+z)%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<endl;
	return 0;
}
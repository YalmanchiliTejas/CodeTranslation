#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c;
	d=100*a+10*b+c;
	if(d%4==0)cout<<"YES"<<endl;
	if(d%4!=0)cout<<"NO"<<endl;
	return 0;
	
} 
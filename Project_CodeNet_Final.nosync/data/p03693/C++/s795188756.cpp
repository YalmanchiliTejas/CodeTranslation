#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,x;
	cin>>a>>b>>c;
	x=100*a+10*b+c;
	if(x%4==0){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
}
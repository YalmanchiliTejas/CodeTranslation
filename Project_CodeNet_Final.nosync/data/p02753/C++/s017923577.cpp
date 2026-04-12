#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	string b1 = a.substr(0,1);
	string b2 = a.substr(1,1);
	string b3 = a.substr(2,1);
	if(b1==b2 && b2==b3)cout<<"No";
	else cout<<"Yes";
	return 0;
}
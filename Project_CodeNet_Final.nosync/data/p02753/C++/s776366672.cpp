#include<bits/stdc++.h>
using namespace std;
int main()
{
	string S;
	cin>>S;
	if(S.substr(0,3)=="AAA" || S.substr(0,3)=="BBB")
	cout<<"No"<<endl;
	else
	cout<<"Yes"<<endl;
	return 0;
}
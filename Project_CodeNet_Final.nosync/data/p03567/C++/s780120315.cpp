#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.find("AC");
	if(n==-1) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
	return 0;
}
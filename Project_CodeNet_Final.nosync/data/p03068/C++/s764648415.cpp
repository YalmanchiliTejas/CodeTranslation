#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	string s;
	cin>>a>>s>>b;
	char c=s[b-1];
	for(int i=0;i<a;i++)
	if(s[i]==c)
	cout<<c;
	else
	cout<<"*";
	return 0;
} 
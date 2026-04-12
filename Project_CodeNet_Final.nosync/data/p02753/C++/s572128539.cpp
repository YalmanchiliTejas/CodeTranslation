
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


int main()
{
	int a,b;
	a=b=0;
	string s;
	getline(cin,s);
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
		a++;
		else
		b++;
	}
	if(a!=3 && b!=3)
	cout<<"Yes"<<'\n';
	else
	cout<<"No"<<"\n";
	return 0;
} 

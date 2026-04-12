#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a=0,b=0;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
		{
			a++;
		}
		else if(s[i]=='B')
		{
			b++;
		}
	}
	
	if(a>=1&&b>=1)
	{
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
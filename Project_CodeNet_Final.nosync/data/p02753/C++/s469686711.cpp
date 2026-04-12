#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=0;
	string s;
	cin>>s;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')a++;
	}
	if(a==1||a==2)cout<<"Yes";
	else cout<<"No";
 } 
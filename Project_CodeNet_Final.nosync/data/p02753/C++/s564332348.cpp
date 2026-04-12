#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	set<char>ms;
	ms.insert(s[0]);
	ms.insert(s[1]);
	ms.insert(s[2]);
	if(ms.size()==1)
	{
		cout<<"No";
	}
	else
	{
		cout<<"Yes";
	}
}
#include<bits/stdc++.h>
using namespace std;
int a,b;
string s;
int main()
{
	cin>>a>>s>>b;
	b--;
	for(int i=0;i<a;i++)
		if(s[i]!=s[b])
			s[i]='*';
	cout<<s<<endl;
}
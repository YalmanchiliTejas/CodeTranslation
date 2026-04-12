#include <bits/stdc++.h>
using namespace std;
string s,t;
int n;
char rev(char c)
{
	return c=='S'?'W':'S';
}
bool check(string str)
{
	bool ok=true;
	for(int i=0;i<n;i++)
	{
		char cl=str[(i+n-1)%n];
		char cr=str[(i+1)%n];
		if(s[i]=='o' && str[i]=='S')ok&=cl==cr;
		else if(s[i]=='x' && str[i]=='S')ok&=cl!=cr;
		else if(s[i]=='o' && str[i]=='W')ok&=cl!=cr;
		else ok&=cl==cr;
	}
	return ok;
}
void process(string str)
{
	t=str;
	t.resize(n);
	for(int i=1;i<n-1;i++)
	{
		if(t[i]=='S' && s[i]=='o')t[i+1]=t[i-1];
		else if(t[i]=='S' && s[i]=='x')t[i+1]=rev(t[i-1]);
		else if(t[i]=='W' && s[i]=='o')t[i+1]=rev(t[i-1]);
		else t[i+1]=t[i-1];
	}
//	cout<<t<<endl;
	if(check(t))
	{
		cout<<t<<endl;
		exit(0);
	}
}
int main()
{
	cin>>n;
	cin>>s;
	process("SS");
	process("SW");
	process("WS");
	process("WW");
	puts("-1");
	return 0;
}
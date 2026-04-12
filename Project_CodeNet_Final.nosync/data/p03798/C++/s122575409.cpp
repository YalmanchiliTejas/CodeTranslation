#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

string find(string a, string b)
{
	int n = a.length();
	for(int i = 0; i<a.length(); i++)
	{
		int t = i-1;
		if(i==0)
			t = n-1;
		int g = i+1;
		if(i==n-1)
			g = 0;
		if(a[i]=='o')
		{
			if(b[i]=='S' && b[t]=='S')
				continue;
			else if(b[i]=='S' && b[t]=='W')
				b[g]='W';
			else if(b[i]=='W' && b[t]=='S')
				b[g]='W';
			else
				continue;
		}
		else
		{
			if(b[i]=='S' && b[t]=='S')
				b[g]='W';
			else if(b[i]=='S' && b[t]=='W')
				b[g]='S';
			else if(b[i]=='W' && b[t]=='S')
				b[g]='S';
			else
				b[g]='W';
		}
	}
	return b;
}

bool check(string s, string s2)
{
	bool flag = 1;
	int n= s.length();
	for(int i = 0; i<n; i++)
	{
		int t = i-1;
		if(i==0)
			t = n-1;
		int g = i+1;
		if(i==n-1)
			g = 0;
		if(s[i]=='x' && ((s2[i]=='W' && s2[t]!=s2[g]) || (s2[i]=='S' && s2[t]==s2[g]) ))
			flag = 0;
		else if(s[i]=='o' && ((s2[i]=='W' && s2[t]==s2[g]) || (s2[i]=='S' && s2[t]!=s2[g]) ))
			flag = 0;
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string s2(n,'S');
	int flag = 0;
	string g = find(s,s2),j="";
	if(check(s,g))
	{
		j = g;
		flag = 1;
	}
	g = s2;
	g[n-1]='W';
	g = find(s,g);
	if(check(s,g))
	{
		j = g;
		flag = 1;
	}
	g = s2; g[0]='W'; g = find(s,g);
	if(check(s,g))
	{
		j = g;
		flag = 1;
	}
	g = s2; g[n-1]=g[0]='W'; g= find(s,g);
	if(check(s,g))
	{
		j = g;
		flag = 1;
	}
	if(flag)
		cout<<j<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
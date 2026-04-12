#include<bits/stdc++.h>
using namespace std;
int n;
string s,t;
char change(char c)
{
	if(c=='S')
		return 'W';
	else
		return 'S';
}
bool ok(char a,char x,char y,char b)
{
	if(x=='o'&&y=='S'&&a=='S'&&b=='S')return true;
	if(x=='o'&&y=='S'&&a=='W'&&b=='W')return true;
	if(x=='x'&&y=='S'&&a=='S'&&b=='W')return true;
	if(x=='x'&&y=='S'&&a=='W'&&b=='S')return true;
	if(x=='o'&&y=='W'&&a=='S'&&b=='W')return true;
	if(x=='o'&&y=='W'&&a=='W'&&b=='S')return true;
	if(x=='x'&&y=='W'&&a=='S'&&b=='S')return true;
	if(x=='x'&&y=='W'&&a=='W'&&b=='W')return true; 
	return false;
}
void dfs(int now)
{
	if(now==n-1)
	{
		if(ok(t[n-2],s[n-1],t[n-1],t[0])&&ok(t[n-1],s[0],t[0],t[1]))
		{
			cout<<t<<endl;
			exit(0);
		}
		return;
	}
	int bef=now-1;
	int nxt=now+1;
	if(t[now]=='S')
	{
		if(s[now]=='x')t[nxt]=change(t[bef]);
		else t[nxt]=t[bef];
	}
	else
	{
		if(s[now]=='o')t[nxt]=change(t[bef]);
		else t[nxt]=t[bef];
	}
	dfs(now+1);
}
int main()
{
	cin>>n;
	cin>>s;
	t=s;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			t[0]=(i==0?'S':'W');
			t[1]=(j==0?'S':'W');
			dfs(1);
		}
	}
	cout<<"-1\n";
	return 0;
}
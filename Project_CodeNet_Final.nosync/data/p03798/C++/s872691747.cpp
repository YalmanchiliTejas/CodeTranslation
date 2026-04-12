#include<bits/stdc++.h>
using namespace std;
char sh[100001];
bool same[100001];
int n;
void ok()
{
	for(int i=1;i<=n;i++)
	{
		cout<<sh[i];
	}
//	cout<<" "<<sh[n+1]<<sh[n+2];
	cout<<endl;
	exit(0);
}
void check(char a,char b)
{
	sh[1]=a;
	sh[2]=b;
	for(int i=2;i<=n+1;i++)
	{
		if((sh[i]=='S'&&same[i]==1)||sh[i]=='W'&&same[i]==0)
		{
			if(sh[i-1]=='S')
			{
				sh[i+1]='S';
			}
			else
			{
				sh[i+1]='W';
			}
		}
		else
		{
			if(sh[i-1]=='S')
			{
				sh[i+1]='W';
			}
			else
			{
				sh[i+1]='S';
			}
		}
	}
	if(!(sh[n+1]==sh[1]&&sh[n+2]==sh[2]))
	{
		return;
	}
	if(sh[n]=='S'&&same[n]==1&&sh[1]==sh[n-1])
	{
		ok();
	}
	else if(sh[n]=='S'&&same[n]==0&&sh[1]!=sh[n-1])
	{
		ok();
	}
	else if(sh[n]=='W'&&same[n]==1&&sh[1]!=sh[n-1])
	{
		ok();
	}
	else if(sh[n]=='W'&&same[n]==0&&sh[1]==sh[n-1])
	{
		ok();
	}
//	cout<<sh[n+1]<<" "<<sh[1]<<"        "<<sh[n+2]<<" "<<sh[2]<<endl;
	return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if(ch=='o')
		{
			same[i]=1;
		}
		else
		{
			same[i]=0;
		}
	}
	same[n+1]=same[1];
	same[n+2]=same[2];
	check('S','S');
	check('S','W');
	check('W','S');
	check('W','W');
	cout<<-1<<endl;
	return 0;
}
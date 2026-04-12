#include<bits/stdc++.h>
using namespace std;
int h,w;
string s[105];
int main()
{
	cin>>h>>w;
	for (int i=1;i<=h;i++)
	{
		cin>>s[i];
	}
	for (int i=1;i<=h;i++)
	{
		int flag=1;
		for (int j=1;j<=w;j++)
		if (s[i][j-1]=='#') flag=0;
		if (flag)
		{
			h--;
			for (int j=i;j<=h;j++)
			s[j]=s[j+1];
			i--;
		}
	}
	for (int i=1;i<=w;i++)
	{
		int flag=1;
		for (int j=1;j<=h;j++)
		if (s[j][i-1]=='#') flag=0;
		if (flag)
		{
			w--;
			for (int j=1;j<=h;j++)
			for (int k=i;k<=w;k++)
			s[j][k-1]=s[j][k];
			i--;
		}
	}
	for (int i=1;i<=h;i++)
	{
		for (int j=0;j<=w-1;j++)
		cout<<s[i][j];
		cout<<endl;
	}
	return 0;
}
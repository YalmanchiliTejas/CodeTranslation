#include<bits/stdc++.h>

using namespace std;

int h,w;
string s[110];
bool ha[110],li[110];

int main()
{
	cin>>h>>w;
	for(int i=0; i<h; i++)cin>>s[i];
	for(int i=0; i<h; i++)
	{
		bool f=1;
		ha[i]=1;
		for(int j=0; j<w; j++)
		{
			if(s[i][j]=='#')
			{
				f=0;
				break;
			}
		}
		if(f)ha[i]=0;
	}
	for(int i=0; i<w; i++)
	{
		bool f=1;
		li[i]=1;
		for(int j=0; j<h; j++)
		{
			if(s[j][i]=='#')
			{
				f=0;
				break;
			}
		}
		if(f)li[i]=0;
	}
	for(int i=0; i<h; i++)
	{
		bool f=0;
		for(int j=0; j<w; j++)
		{
			if((ha[i])&&(li[j]))
			{
				cout<<s[i][j];
				f=1;
			}
		}
		if(f)puts("");
	}
	return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		int p=s[i].find(".");
		//cout<<p<<endl;
		if(p==-1)	continue;
		if(i==0)
		{
			for(int k=p;k<m;k++)
			{
				if(s[i][k]!='.')	continue;
				p=k; 
				int f=-1;
				for(int j=i+1;j<n;j++)
				{
					if(!(s[j][p]=='.'||s[j][p]=='1'))
					{
						f=1;
						break;
					}
				}
				if(f==-1)
				{
					for(int j=0;j<n;j++)
					{
						s[j][p]='1';
					}
				}
			}
		}
		p=0;
		for(int j=0;j<m;j++)
		{
			if(!(s[i][j]=='1'||s[i][j]=='.'))
			{
				p=-1;
				break;
			}
		}
		if(p!=-1&&(s[i][0]=='.'||s[i][0]=='1'))
		{
			for(int j=0;j<m;j++)
			{
				s[i][j]='1';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		int u=0;
		for(int j=0;j<m;j++)
		{
			if(s[i][j]!='1')
			{
				u++;
				cout<<s[i][j];
			}
		}
		if(u!=0)	cout<<endl;
	}
	return 0;
}
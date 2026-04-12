#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;
int n,p,pp;
string st[100+10];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>st[i];
	}
	for(int i=1;i<=26;i++)
	{
		p=1;
		while(p==1)
		{
			for(int j=1;j<=n;j++)
			{
				pp=0;
				for(int q=0;q<st[j].size();q++)
				{
					if(st[j][q]==char('a'+i-1))
					{
						st[j][q]=' ';
						pp=1;break;
					}
				}
				if(pp==0)
				{
					p=0;break;
				}
			}
			if(p==1)
			cout<<char('a'+i-1);
		}
	}
	cout<<endl;
	return 0;
}
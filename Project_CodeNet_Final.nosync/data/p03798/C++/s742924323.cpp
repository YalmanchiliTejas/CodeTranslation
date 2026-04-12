#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[4];
int d[100000];
char x[2]={'S','W'};
int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	p[0]=make_pair(0,0);
	p[1]=make_pair(0,1);
	p[2]=make_pair(1,0);
	p[3]=make_pair(1,1);
	for(int i=0;i<4;i++)
	{
		d[0]=p[i].first;
		d[1]=p[i].second;
		for(int i=1;i<n-1;i++)
		{
			if((s[i]=='o'&&d[i]==0)||(s[i]=='x'&&d[i]==1))
			  d[i+1]=d[i-1];
			else
			  d[i+1]=1^d[i-1];
		}
			if((s[n-1]=='o'&&d[n-1]==0)||(s[n-1]=='x'&&d[n-1]==1))
			{
				if(d[0]!=d[n-2])
				  continue;
				else
				{
					if((s[0]=='o'&&d[0]==0)||(s[0]=='x'&&d[0]==1))
					{
						if(d[1]!=d[n-1])
						  continue;
						else
						{
						  for(int i=0;i<n;i++)
					  		cout<<x[d[i]];
						  return 0;	
						}
					}
					else
					{
						if(d[1]==d[n-1])
						  continue;
						else
						{
						  for(int i=0;i<n;i++)
					  		cout<<x[d[i]];
						  return 0;	
						}
					}
				}
			}
			else
			{
				if(d[0]==d[n-2])
				  continue;
				else
				{
					if((s[0]=='o'&&d[0]==0)||(s[0]=='x'&&d[0]==1))
					{
						if(d[1]!=d[n-1])
						  continue;
						else
						{
						  for(int i=0;i<n;i++)
					  		cout<<x[d[i]];
						  return 0;	
						}
					}
					else
					{
						if(d[1]==d[n-1])
						  continue;
						else
						{
						  for(int i=0;i<n;i++)
					  		cout<<x[d[i]];
						  return 0;	
						}
					}
				}
			}
	}
	cout<<-1;
	return 0;
}
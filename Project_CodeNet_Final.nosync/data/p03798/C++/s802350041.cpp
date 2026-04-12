#include<iostream>
#include<cstdio>
using namespace std;
char s[100005],ans[100005];
int n;
char fir[5]={'S','S','W','W'};
char sec[5]={'S','W','S','W'};
int judge()
{
	for(int i=1;i<=n;i++)
	{
		int left,right;
		left=i-1>=1?i-1:n;
		right=i+1<=n?i+1:1;
		if(s[i]=='o')
		{
			if(ans[i]=='W')
			{
				if(ans[left]==ans[right])
				return 0;	
			}
			else
			{
				if(ans[left]!=ans[right])
				return 0;
			}
		}
		else
		{
			if(ans[i]=='W')
			{
				if(ans[left]!=ans[right])
				return 0;
			}
			else
			{
				if(ans[left]==ans[right])
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	cin>>n;
	scanf("%s",s+1);	
	int flag=0;
	for(int k=0;k<4;k++)
	{
		ans[1]=fir[k];
		ans[2]=sec[k];
		for(int i=2;i<n;i++)
		{
			if(s[i]=='o')
			{
				if(ans[i]=='S')
				ans[i+1]=ans[i-1];
				else
				{
					if(ans[i-1]=='W')
					ans[i+1]='S';
					else
					ans[i+1]='W';
				}	
			}
			else
			{
				if(ans[i]=='S')
				{
					if(ans[i-1]=='S')
					ans[i+1]='W';
					else
					ans[i+1]='S';
				}
				else
				ans[i+1]=ans[i-1];
			}
		}
		if(judge()==1)
		{
			for(int i=1;i<=n;i++)
			cout<<ans[i];
			cout<<endl;	
			flag=1;
		}
		if(flag)
		break;
	}
	if(flag==0)
	cout<<-1<<endl;
	return 0;
}
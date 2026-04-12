#include<iostream>
using namespace std;
bool flag1[1005],flag2[1005];
char ch[1005][1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>ch[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ch[i][j]=='#')
			{
				flag1[i]=1;
				break;
			}
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(ch[i][j]=='#')
			{
				flag2[j]=1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!flag1[i]) continue;
		for(int j=1;j<=m;j++)
		{
			if(!flag2[j]) continue;
			cout<<ch[i][j];
		}
		cout<<endl;
	}
	return 0;
}

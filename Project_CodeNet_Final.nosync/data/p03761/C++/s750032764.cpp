#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#define inf 0x3f3f3f3f
using namespace std;
int vis[55][200];
vector<char>k;
int main()
{
	
	int n;
	scanf("%d",&n);
	char s[55][55];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
		int l=strlen(s[i]);
		for(int j=0;j<l;j++)
		{
			vis[i][s[i][j]-'a']++;
		}
		
	} 
	int flag=0;
	int num=inf;
	int sum=0;
	for(int i=0;i<26;i++)
	{
		sum=0;
		for(int j=0;j<n;j++)
		{
			if(vis[j][i])
			{
				sum++;
				
			}
		}
		if(sum==n)
		{
			flag=1;
			break;
			
		}
	}
	if(!flag)
		puts(" ");
	else
	{
		for(int i=0;i<26;i++)
		{
			num=0;
			int maxx=inf;
			for(int j=0;j<n;j++)
			{
				if(vis[j][i])
				{
					num++;
					maxx=min(vis[j][i],maxx);
				}
			}
			if(num==n)
			{
				while(maxx--)
				{
					k.push_back(i+'a');
				}
			}
		}
		sort(k.begin(),k.end());
		for(int i=0;i<k.size();i++)
		{
			cout<<k[i];
		}
	}
	return 0;
}
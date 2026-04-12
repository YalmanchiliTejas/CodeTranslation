#include <bits/stdc++.h>
using namespace std;
char s1[5];
int vis[5];
int main()
{
	scanf("%s",s1);
	for(int i=0;i<3;i++)
	{
		if(s1[i]=='A')
		{
			vis[1]++;
		}
		if(s1[i]=='B')
		{
			vis[2]++;
		}
	}
	if(vis[1] && vis[2])
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
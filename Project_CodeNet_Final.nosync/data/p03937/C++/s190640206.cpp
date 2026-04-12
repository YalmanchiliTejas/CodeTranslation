#include<bits/stdc++.h>
using namespace std;
int h,w;
char s[15][15];
bool used[15][15];
int main()
{
	cin>>h>>w;
	for (int i=1;i<=h;i++)
	{
		scanf("%s",s[i]+1);
	}
	int x=1,y=1;
	used[1][1]=true;
	while (x!=h || y!=w)
	{
		if (s[x+1][y]=='#')
		{
			x++;
		}
		else if (s[x][y+1]=='#')
		{
			y++;
		}
		else
		{
			break;
		}
		used[x][y]=true;
	}
	if (x!=h || y!=w)
	{
		puts("Impossible");
		return 0;
	}
	for (int i=1;i<=h;i++)
	{
		for (int j=1;j<=w;j++)
		{
			if (s[i][j]=='#' && !used[i][j])
			{
				puts("Impossible");
				return 0;
			}
		}
	}
	puts("Possible");
	return 0;
}

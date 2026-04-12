//https://abc055.contest.atcoder.jp/tasks/arc069_b
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str;
int cond[100005],n,i;
bool a[100005];
int main()
{
	scanf("%d\n",&n);
	cin>>str;
	for (i=0;i<n;i++)
	{
		if (str[i]=='o') a[i+1]=0;
		else a[i+1]=1;
	}
	for (cond[1]=0;cond[1]<=1;cond[1]++)
	{
		for (cond[2]=0;cond[2]<=1;cond[2]++)
		{
			for (i=3;i<=n;i++)
			{
				cond[i]=cond[i-2]^cond[i-1]^a[i-1];
			}
			if (cond[1]==cond[n]^cond[n-1]^a[n] && cond[2]==cond[n]^cond[1]^a[1])
			{
				for (i=1;i<=n;i++)
				{
					if (cond[i]) printf("W");
					else printf("S");
				}
				printf("\n");
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}
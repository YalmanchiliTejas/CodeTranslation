#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[10][10];
int x[2]={0,1},y[2]={1,0};

queue<pair<int,int> > q;

main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	if(a[0][0]=='#'&&a[n-1][m-1]=='#')
	{
		a[0][0]='.';
		q.push(make_pair(0,0));
		int d=0;
		while(!q.empty())
		{
			int p1=q.front().first,p2=q.front().second;
			q.pop();
			d=0;
			for(int i=0;i<2;i++)
			{
				if(p1+x[i]<n&&p2+y[i]<m&&a[p1+x[i]][p2+y[i]]=='#')
				{
					d++;
					a[p1+x[i]][p2+y[i]]='.';
					q.push(make_pair(p1+x[i],p2+y[i]));
				}
			}
			if(d==2)
			{
				printf("Impossible");
				return 0;
			}
		}
		if(a[n-1][m-1]!='.')
		{
			printf("Impossible");
			return 0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				//printf("%c",a[i][j]);
				if(a[i][j]=='#')
				{
					printf("Impossible");
					return 0;
				}
			}
			//printf("\n");
		}
		printf("Possible");
	}
	else
	{
		printf("Impossible");
	}
}

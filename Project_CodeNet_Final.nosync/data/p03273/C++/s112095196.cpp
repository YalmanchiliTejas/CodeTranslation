#include <bits/stdc++.h>
using namespace std;
char a[100][100];
int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		getchar();
		for(j=0;j<m;j++)
			scanf("%c",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			if(a[i][j]!='.')
				break;
		if(j==m)
		{
			for(j=i+1;j<n;j++)
				for(k=0;k<m;k++)
					a[j-1][k]=a[j][k];
			n--;
			i--;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			if(a[j][i]!='.')
				break;
		if(j==n)
		{
			for(j=i+1;j<m;j++)
				for(k=0;k<n;k++)
					a[k][j-1]=a[k][j];
			m--;
			i--;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%c",a[i][j]);
		printf("\n");
	}
	return 0;
}
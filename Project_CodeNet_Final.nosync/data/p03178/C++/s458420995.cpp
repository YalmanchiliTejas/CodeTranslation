#include <bits/stdc++.h>
using namespace std;
int f[10001][101][2];
char a[10001];
int main()
{
	int n,d,i,j,l;
	scanf("%s",a);
	scanf("%d",&d);
	n=strlen(a);
	f[0][0][1]=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<d;j++)
		{
			for(l=0;l<=9;l++)
				f[i+1][(j+l)%d][0]=(f[i+1][(j+l)%d][0]+f[i][j][0])%1000000007;
			for(l=0;l<=a[i]-'0';l++)
			{
				if(l==a[i]-'0')
					f[i+1][(j+l)%d][1]=(f[i+1][(j+l)%d][1]+f[i][j][1])%1000000007;
				else
					f[i+1][(j+l)%d][0]=(f[i+1][(j+l)%d][0]+f[i][j][1])%1000000007;
			}
		}
	}
	printf("%d",(f[n][0][0]+f[n][0][1]+1000000006)%1000000007);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int f[10001][101][2];
char a[10001];
int main()
{
	int i,D,j,k,n;
	scanf("%s",a);
	scanf("%d",&D);
	f[0][0][1]=1;
	n=strlen(a);
	for(i=0;i<n;i++)
	{
		for(j=0;j<D;j++)
		{
			for(k=0;k<=9;k++)
			{
				f[i+1][(j+k)%D][0]=(f[i+1][(j+k)%D][0]+f[i][j][0])%1000000007;
			}
			for(k=0;k<=a[i]-'0';k++)
			{
				if(k==a[i]-'0')
					f[i+1][(j+k)%D][1]=(f[i+1][(j+k)%D][1]+f[i][j][1])%1000000007;
				else
					f[i+1][(j+k)%D][0]=(f[i+1][(j+k)%D][0]+f[i][j][1])%1000000007;
			}
		}
	}
	printf("%d",((f[n][0][0]+f[n][0][1]-1)%1000000007+1000000007)%1000000007);
	return 0;
}
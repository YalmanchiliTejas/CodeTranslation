#include<bits/stdc++.h>
using namespace std;
char a[10001];
long long f[10001][101][2];
int main()
{
	int n,i,D,j,k;
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
	printf("%lld",((f[n][0][0]+f[n][0][1]-1)%1000000007+1000000007)%1000000007);
	return 0;
}
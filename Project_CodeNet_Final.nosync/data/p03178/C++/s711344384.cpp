#include <bits/stdc++.h>
using namespace std;
int f[10001][101][2];
char a[10001];
int main()
{
	int K,D,i,j,k;
	scanf("%s",a);
	scanf("%d",&D);
	K=strlen(a);
	f[0][0][1]=1;
	for(i=0;i<K;i++)
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
	printf("%d",(f[K][0][0]+f[K][0][1]-1+1000000007)%1000000007);
	return 0;
}
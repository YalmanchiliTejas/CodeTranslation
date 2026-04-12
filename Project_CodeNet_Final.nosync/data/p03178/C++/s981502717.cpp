#include"bits/stdc++.h"
using namespace std;
int f[10001][101][2];
int d,n;
char a[10001];
int main()
{
	cin>>a;
	cin>>d;
	n=strlen(a);
	f[0][0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<=9;k++)
				f[i+1][(j+k)%d][0]=((long long)f[i+1][(j+k)%d][0]+f[i][j][0])%1000000007;
			for(int k=0;k<=a[i]-'0';k++)
			{
				if(k==(a[i]-'0'))
					f[i+1][(j+k)%d][1]=((long long)f[i+1][(j+k)%d][1]+f[i][j][1])%1000000007;
				else
					f[i+1][(j+k)%d][0]=((long long)f[i+1][(j+k)%d][0]+f[i][j][1])%1000000007;
			}
		}
	}
	printf("%d",(int)((((long long)f[n][0][0]+f[n][0][1])-1+1000000007)%1000000007));
}
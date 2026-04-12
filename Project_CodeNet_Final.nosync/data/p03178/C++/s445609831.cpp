#include<bits/stdc++.h>
using namespace std;
int f[10001][101][2];
char a[10001];
int main()
{
	f[0][0][1]=1;
	int i,j,l;
	int n,D;
	scanf("%s",a);
	scanf("%d",&D);
	n=strlen(a);
	for(i=0;i<n;i++)
    	{
		for(j=0;j<D;j++)
		{
			for(l=0;l<=9;l++)
				f[i+1][(j+l)%D][0]=(f[i+1][(j+l)%D][0]+f[i][j][0])%1000000007;
			for(l=0;l<=a[i]-'0';l++)
				if(l==a[i]-'0')
					f[i+1][(j+l)%D][1]=(f[i+1][(j+l)%D][1]+f[i][j][1])%1000000007;
				else
					f[i+1][(j+l)%D][0]=(f[i+1][(j+l)%D][0]+f[i][j][1])%1000000007;
		}
      	}
	printf("%d",(f[n][0][1]+f[n][0][0]+1000000006)%1000000007);
}
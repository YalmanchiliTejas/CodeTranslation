#include <bits/stdc++.h>
using namespace std;
char a[10001];
long long f[10001][3][101];
int main()
{
	int ans=0,d,i,j,k,l,len;
	scanf("%s",a);
	scanf("%d",&d);
	len=strlen(a);
	f[0][0][0]=1;
	for(i=0;i<len;i++)
	{
        for(j=0;j<2;j++)
		{
            for(k=0;k<d;k++)
			{
                for(l=0;l<=(j?9:a[i]-'0');l++)
				{
					if(j==1||l<a[i]-'0')
					{
						f[i+1][1][(k+l)%d]+=f[i][j][k];
						f[i+1][1][(k+l)%d]%=1000000007;
					}
					else
					{
						f[i+1][0][(k+l)%d]+=f[i][j][k];
						f[i+1][0][(k+l)%d]%=1000000007;
					}
                }
            }
        }
    }
	printf("%lld",((f[len][0][0]+f[len][1][0]-1)%1000000007+1000000007)%1000000007);
	return 0;
}
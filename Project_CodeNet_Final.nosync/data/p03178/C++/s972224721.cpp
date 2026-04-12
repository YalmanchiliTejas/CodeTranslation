#include "bits/stdc++.h"
#define MOD 1000000007
using namespace std;
int f[10002][100][2]={0};
char k[10001];
int main()
{
    int D,n;
    int i,j,l;
    scanf("%s",k);
    scanf("%d",&D);
    n=strlen(k);
    f[0][0][1]=1;
    for(i=0;i<n;i++)
    {
	for(j=0;j<D;j++)
	{
	    for(l=0;l<=9;l++)
	    {
		f[i+1][(j+l)%D][0]+=f[i][j][0];
		f[i+1][(j+l)%D][0]%=MOD;
 	    }
	    for(l=0;l<=k[i]-'0';l++)
	    {
		if(l==k[i]-'0')
		{
		    f[i+1][(j+l)%D][1]+=f[i][j][1];
		    f[i+1][(j+l)%D][1]%=MOD;
		}
		else
		{
		    f[i+1][(j+l)%D][0]+=f[i][j][1];
		    f[i+1][(j+l)%D][0]%=MOD;
		}
	    }
	}
    }
    printf("%d\n",(MOD+f[n][0][0]+f[n][0][1]-1)%MOD);
    return 0;
}
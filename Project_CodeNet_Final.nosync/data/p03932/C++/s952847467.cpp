#include<stdio.h>
int n,m;
int i,j,k;
int Map[205][205];
int F[410][205][205];
int Max(int a,int b,int c,int d)
{
    if(a>=b&&a>=c&&a>=d)
        return a;
    if(b>=a&&b>=c&&b>=d)
        return b;
    if(c>=a&&c>=b&&c>=d)
        return c;
    if(d>=a&&d>=b&&d>=c)
        return d;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&Map[i][j]);
    int res = Map[1][1] + Map[n][m];
    Map[1][1] = Map[n][m] = 0;
    for(k=1;k<=n+m-2;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(i==n&&j==n&&k==n+m-2)
                    F[k][i][j]=Max(F[k-1][i-1][j],F[k-1][i][j-1],F[k-1][i][j],F[k-1][i-1][j-1])+Map[i][k+2-i]+Map[j][k+2-j];
                else  if(i!=j&&k+2-i>=1&&k+2-j>=1)
                    F[k][i][j]=Max(F[k-1][i-1][j],F[k-1][i][j-1],F[k-1][i][j],F[k-1][i-1][j-1])+Map[i][k+2-i]+Map[j][k+2-j];
    printf("%d\n",F[n+m-2][n][n] + res);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int f[10001][101][2];
char a[10001];
int main()
{
        int n,l,i,j,D,s=0;
        scanf("%s",a);
        n=strlen(a);
        f[0][0][1]=1;
        scanf("%d",&D);
        for(i=0;i<n;i++)
        {
                for(j=0;j<D;j++)
                {
                        for(l=0;l<=9;l++)
                        {
                                f[i+1][(j+l)%D][0]=(f[i][j][0]+f[i+1][(j+l)%D][0])%1000000007;
                        }
                        for(l=0;l<=a[i]-'0';l++)
                        {
                                if(l==a[i]-'0')
                                        f[i+1][(j+l)%D][1]=(f[i][j][1]+f[i+1][(j+l)%D][1])%1000000007;
                                else
                                        f[i+1][(j+l)%D][0]=(f[i][j][1]+f[i+1][(j+l)%D][0])%1000000007;
                        }
                }
        }
        printf("%d",(1000000006+f[n][0][0]+f[n][0][1])%1000000007);
        return 0;
}

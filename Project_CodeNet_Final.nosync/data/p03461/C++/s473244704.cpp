#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=105;
int a,b,f[N][N],d[N][N],s[N][N];
int main()
{
    scanf("%d%d",&a,&b);
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        scanf("%d",&d[x][y]);
    for(int i=1;i<=101;i++)
        for(int j=1;j<=101;j++)
        for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        f[i][j]=max(f[i][j],d[x][y]-(i-1)*x-(101-j)*y);
    memset(s,inf,sizeof(s));
    for(int i=1;i<=101;i++)
        for(int j=1;j<=101;j++)
            for(int x=1;x<=a;x++)
            for(int y=1;y<=b;y++)
            s[x][y]=min(s[x][y],f[i][j]+(i-1)*x+(101-j)*y);
    for(int x=1;x<=a;x++)
        for(int y=1;y<=b;y++)
        if(d[x][y]!=s[x][y])
    {
        printf("Impossible\n");
        return 0;
    }
    printf("Possible\n");
    printf("202 %d\n",100+100+101*101);
    for(int i=1;i<101;i++)
        printf("%d %d X\n",i,i+1);
    for(int i=1;i<101;i++)
        printf("%d %d Y\n",101+i,101+i+1);
    for(int i=1;i<=101;i++)
        for(int j=1;j<=101;j++)
        printf("%d %d %d\n",i,j+101,f[i][j]);
    printf("%d %d\n",1,202);
}

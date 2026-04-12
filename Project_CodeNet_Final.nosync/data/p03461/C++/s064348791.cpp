#include <cstdio>

inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}

const int N=305,Inf=0x3f3f3f3f;
int n,m,f[N][N],d[N][N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&d[i][j]);
    for(int i=0;i<=100;++i)
        for(int j=0;j<=100;++j)
            for(int x=1;x<=n;++x)
                for(int y=1;y<=m;++y)
                    f[i][j]=Max(f[i][j],d[x][y]-i*x-j*y);
    for(int x=1;x<=n;++x)
        for(int y=1;y<=m;++y)
        {
            int Now=Inf;
            for(int i=0;i<=100;++i)
                for(int j=0;j<=100;++j)
                    Now=Min(Now,f[i][j]+i*x+j*y);
            if(Now!=d[x][y])return puts("Impossible"),0;
        }
    puts("Possible\n202 10401");
    for(int i=1;i<=100;++i)printf("%d %d X\n",i,i+1);
    for(int i=102;i<=201;++i)printf("%d %d Y\n",i,i+1);
    for(int i=0;i<=100;++i)
        for(int j=0;j<=100;++j)
            printf("%d %d %d\n",i+1,202-j,f[i][j]);
    return puts("1 202"),0;
}
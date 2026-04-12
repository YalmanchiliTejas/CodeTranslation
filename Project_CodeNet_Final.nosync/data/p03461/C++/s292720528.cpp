#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

#define B cerr<<"Break Point"<<endl;

constexpr int N=15;
constexpr int M=105;

int n,m;
int d[N][N];
int f[M][M];

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
                    f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
    for(int x=1;x<=n;++x)
        for(int y=1;y<=m;++y)
        {
            int nowdis=1e9;
            for(int i=0;i<=100;++i)
                for(int j=0;j<=100;++j)
                    nowdis=min(nowdis,f[i][j]+i*x+j*y);
            if(nowdis!=d[x][y])
            {
                printf("Impossible");
                return 0;
            }
        }
    printf("Possible\n");
    printf("%d %d\n",202,10401);
    for(int i=1;i<=100;++i) printf("%d %d X\n",i,i+1);
    for(int i=102;i<=201;++i) printf("%d %d Y\n",i,i+1);
    for(int i=0;i<=100;++i)
        for(int j=0;j<=100;++j)
            printf("%d %d %d\n",i+1,202-j,f[i][j]);
    printf("%d %d\n",1,202);
    return 0;
}

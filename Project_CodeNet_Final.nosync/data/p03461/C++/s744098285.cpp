#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int x,y,d[105][105],f[105][105];
int main()
{
    scanf("%d%d",&x,&y);
    for (int i=1;i<=x;++i)
        for (int j=1;j<=y;++j)
            scanf("%d",&d[i][j]);
    for (int a=0;a<=maxn;++a)
        for (int b=0;b<=maxn;++b)
            for (int i=1;i<=x;++i)
                for (int j=1;j<=y;++j)
                    f[a][b]=max(f[a][b],d[i][j]-a*i-b*j);
    for (int i=1;i<=x;++i)
        for (int j=1;j<=y;++j) {
            int dis=10000000;
            for (int a=0;a<=maxn;++a)
                for (int b=0;b<=maxn;++b)
                    dis=min(dis,f[a][b]+a*i+b*j);
            if (dis!=d[i][j]) return 0*puts("Impossible");
        }
    puts("Possible");
    printf("%d %d\n",maxn+maxn+2,maxn+maxn+(maxn+1)*(maxn+1));
    for (int i=1;i<=maxn;++i) printf("%d %d X\n",i,1+i);
    for (int i=1;i<=maxn;++i) printf("%d %d Y\n",maxn+1+i,maxn+2+i);
    for (int i=1;i<=maxn+1;++i)
        for (int j=1;j<=maxn+1;++j)
            printf("%d %d %d\n",i,maxn+maxn+3-j,f[i-1][j-1]);
    printf("%d %d\n",1,maxn+maxn+2);
    return 0;
}

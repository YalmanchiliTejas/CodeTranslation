#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF=0x7fffffff;

int n,m,d[N][N],f[N][N];
bool flag;

int main(){
    scanf("%d %d",&n,&m);
    for (register int i=1;i<=n;i++)
        for (register int j=1;j<=m;j++)
            scanf("%d",&d[i][j]);
    
    for (register int i=0;i<=100;i++)
        for (register int j=0;j<=100;j++)
            for (register int x=1;x<=n;x++)
                for (register int y=1;y<=m;y++)
                    f[i][j]=max(f[i][j],d[x][y]-i*x-j*y);
    
    for (register int x=1;x<=n;x++)
        for (register int y=1;y<=m;y++){
            int now=INF;
            for (register int i=0;i<=100;i++)
                for (register int j=0;j<=100;j++)
                    now=min(now,i*x+j*y+f[i][j]);
            if (now!=d[x][y]){ flag=true; goto End; }
        }
    
End:
    if (flag){ printf("Impossible\n"); return 0; }

    //S:1
    //T:202
    //X:[2,101]
    //Y:[102,202]
    printf("Possible\n");
    printf("202 10401\n");
    for (register int i=1;i<=100;i++) printf("%d %d X\n",i,i+1);
    for (register int i=102;i<202;i++) printf("%d %d Y\n",i,i+1);
    for (register int i=0;i<=100;i++)
        for (register int j=0;j<=100;j++)
            printf("%d %d %d\n",i+1,202-j,f[i][j]);
    printf("1 202\n");
    return 0;
}

#include <stdio.h>
#define white 0
#define black 1
int n,m,i,a,b,ans=0;
int col[9]={white};
int r[30][30];
void dfs(int u){
    for(int i=1;i<=n;i++){
        if(col[i]==white)break;
        if(i==n){ans++;
        return ;
        }
    }
    for(int v=1;v<=8;v++){
        if(r[u][v]==1&&col[v]==white){
            col[v]=black;
            dfs(v);
            col[v]=white;
        }
    }
    }
int main(void){
    int i,j,a,b;
    //n頂点、m辺
    scanf("%d %d",&n,&m);
    //m個の辺.頂点a[i]とb[i]をつなぐ
    for(i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        r[a][b]=1;
        r[b][a]=1;
    }
    col[1]=black;
    dfs(1);
    printf("%d\n",ans);
}

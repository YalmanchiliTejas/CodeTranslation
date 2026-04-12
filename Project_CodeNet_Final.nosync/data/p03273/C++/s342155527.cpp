#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 101
char map[maxn][maxn];
int n,m,h[maxn],l[maxn],num[maxn][maxn];

signed main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",map[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]=='.')  num[i][j]=0;
            if(map[i][j]=='#')  num[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        int bol=0;
        for(int j=1;j<=m;j++){
            if(num[i][j]==1){
                bol=1;break;
            }
        }
        if(bol==0)
            h[i]=1;
    }

    for(int i=1;i<=m;i++){
        int bol=0;
        for(int j=1;j<=n;j++){
            if(num[j][i]==1){
                bol=1;break;
            }
        }
        if(bol==0)
            l[i]=1;
    }

    for(int i=1;i<=n;i++){
        if(h[i])    continue;
        for(int j=1;j<=m;j++){
            if(l[j])    continue;
            if(num[i][j]==0)    printf(".");
            else                printf("#");
        }
        printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <memory.h>
using namespace std;

#define MAX 10
char omap[MAX][MAX];
int flag[MAX][MAX], res[MAX][MAX];
int h, w, ans;

bool check(){
    int t;
//    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
//        cout<<omap[i][j];
//        if(j==w)cout<<endl;
//    }
//    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
//        cout<<flag[i][j];
//        if(j==w)cout<<endl;
//    }
    for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
        if(omap[i][j]=='#')t=1;
        else t = 0;
        if(flag[i][j]!=t)return 0;
    }
    return 1;
}

bool cgo(int x, int y){
    //cout<<"->"<<x<<"  "<<y<<"  "<<omap[x][y]<<endl;
    if(x>h||y>w||x<1||y<1||omap[x][y]!='#')return 0;
    //cout<<"ok"<<endl;
    return 1;
}

void dfs(int x, int y){
    if(omap[x][y]=='#')flag[x][y] = 1;
    //cout<<x<<" "<<y<<endl;
    if(x==h && y==w){
        if(check())ans = 1;
    }
    if(cgo(x+1, y))dfs(x+1, y);
    flag[x+1][y] = 0;
    if(cgo(x, y+1)){
            dfs(x, y+1);
    }
    flag[x][y+1] = 0;
}

int main()
{
    while(~scanf("%d%d", &h, &w))
    {
        memset(flag, 0, sizeof(flag));
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++)
                cin>>omap[i][j];
        }
//        for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
//            cout<<omap[i][j];
//            if(j==w)cout<<endl;
//        }
        ans = 0;
        dfs(1, 1);
        if(ans)printf("Possible\n");
        else printf("Impossible\n");
    }
    return 0;
}
